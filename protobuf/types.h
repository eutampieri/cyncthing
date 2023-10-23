#ifndef PROTOBUF_TYPES
#define PROTOBUF_TYPES
typedef enum proto_type {
	VARINT	= 0,
	I64     = 1,
	LEN     = 2,
	SGROUP	= 3,
	EGROUP	= 4,
	I32     = 5
} proto_type_t;

/*typedef enum proto_type_c {

} proto_type_c_t;*/
#endif
