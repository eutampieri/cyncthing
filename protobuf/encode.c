#include "encode.h"
uintptr_t proto_byte_encode(char* buffer, uintptr_t buffer_length, uint8_t value) {
    uintptr_t buffer_position = 0;
    buffer[buffer_position++] = value;
    return buffer_position;
}

uintptr_t proto_encode(char* buffer, uintptr_t buffer_length, uintptr_t number_of_values, ...) {
	uintptr_t buffer_position = 0;
	va_list args;
	va_start(args, number_of_values);
    uintptr_t index;
	for(uintptr_t i = 0; i < number_of_values; i++) {
        index = va_arg(args, uintptr_t);
        // TODO Handle expanding allocation
        proto_type_t type = va_arg(args, proto_type_t);
        uint8_t tag = proto_get_tag(type, index);
        buffer[buffer_position++] = tag;
        list_t list;
        varint_t varint;
		switch(type) {
            case VARINT:
                varint = va_arg(args, varint_t);
                buffer_position += proto_varint_encode(
                        buffer + buffer_position,
                        buffer_length - buffer_position,
                        varint);
                break;
            case I64:
                *(buffer + buffer_position) = va_arg(args, uint64_t);
                buffer_position += sizeof(uint64_t);
                break;
            case LEN:
                list = va_arg(args, list_t);
                buffer_position += proto_varint_encode(
                        buffer + buffer_position,
                        buffer_length - buffer_position,
                        proto_varint_from_uintptr_t(list.length));
                for (uintptr_t j = 0; j < list.length; j++) {
                    buffer_position += proto_byte_encode(
                            buffer + buffer_position,
                            buffer_length - buffer_position,
                            list.value[j]);
                }
                break;
            case SGROUP:
                break;
            case EGROUP:
                break;
            case I32:
                *(buffer + buffer_position) = va_arg(args, uint32_t);
                buffer_position += sizeof(uint32_t);
                break;
            default:
                break;
        }
	}
    va_end(args);
	return buffer_position;
}
