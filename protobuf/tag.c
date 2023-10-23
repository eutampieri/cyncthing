#include "tag.h"
uint8_t proto_get_tag(proto_type_t type, uint8_t field_number) {
	return (field_number << 3) | type;
}
