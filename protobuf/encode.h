#include <stdlib.h>
#include <inttypes.h>
#include <stdarg.h>
#include "types.h"
#include "tag.h"
#include "../utils/list.h"
#include "varint.h"
#ifndef PROTOBUF_ENCODE_H
#define PROTOBUF_ENCODE_H
#define PROTOBUF_DEFAULT_BUFFER_LENGTH 100
uintptr_t proto_encode(char* buffer, uintptr_t buffer_length, uintptr_t number_of_values,...);
#endif
