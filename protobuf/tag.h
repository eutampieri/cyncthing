#include <inttypes.h>
#include "types.h"

#ifndef PROTOBUF_TAG
#define PROTOBUF_TAG
uint8_t proto_get_tag(proto_type_t type, uint8_t field_number);
#endif
