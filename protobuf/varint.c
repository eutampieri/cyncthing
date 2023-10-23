#include "varint.h"

bool proto_varint_is_true(varint_t value) {
    return value.byte == 2;
}
bool proto_varint_is_false(varint_t value) {
    return value.byte == 0;
}

varint_t proto_varint_new() {
    varint_t result;
    result.int64 = 0;
    return result;
}

varint_t proto_varint_from_bool(bool value) {
    varint_t result = proto_varint_new();
    result.byte = value ? 2 : 0;
    return result;
}

varint_t proto_varint_from_uintptr_t(uintptr_t value) {
    varint_t result = proto_varint_new();
#if UINT32_MAX == UINTPTR_MAX
    result.int32 = value;
#elif UINT64_MAX == UINTPTR_MAX
    result.int64 = value;
#endif
    return result;
}

uintptr_t proto_varint_encode(char* buffer, uintptr_t buffer_length, varint_t value) {
    uintptr_t buffer_position = 0;
    uint64_t mask = 127;
    uint8_t shifts = 0;
    uintptr_t masked_value= value.int64 & mask;
    masked_value = masked_value >> shifts;
    uint8_t last_zero_byte = 0;

    for(int i = 0; i < 10; i++) {
        //printf("Writing value %lu...\n", masked_value);
        buffer[buffer_position++] = masked_value;
        if(mask != 127) {
            // Set MSB of previous byte to one
            buffer[buffer_position - 2] = buffer[buffer_position - 2] | 128;
        }
        shifts += 7;
        mask = mask << 7;
        masked_value = value.int64 & mask;
        masked_value = masked_value >> shifts;
        if(masked_value == 0) {
            last_zero_byte++;
        } else {
            last_zero_byte = 0;
        }
    }
    buffer_position = buffer_position - last_zero_byte;
    buffer[buffer_position] = buffer[buffer_position] & 0b01111111;
    return buffer_position + 1;
}
