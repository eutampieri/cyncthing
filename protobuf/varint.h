#include <stdbool.h>
#include <inttypes.h>
#ifndef CYNCTHING_VARINT_H
#define CYNCTHING_VARINT_H

/*
 * Don't initialise this directly, please use the proto_varint_new() function
 */
typedef union varint {
        uint32_t int32;
        uint64_t int64;
        int8_t byte;
} varint_t;

bool proto_varint_is_true(varint_t value);
bool proto_varint_is_false(varint_t value);
varint_t proto_varint_from_bool(bool value);
varint_t proto_varint_new();
uintptr_t proto_varint_encode(char* buffer, uintptr_t buffer_length, varint_t value);
varint_t proto_varint_from_uintptr_t(uintptr_t value);

#endif //CYNCTHING_VARINT_H
