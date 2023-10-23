#include "../utils/list.h"
#ifndef BEP_HELLO_H
#define BEP_HELLO_H
typedef struct bep_hello {
	char* device_name;
	char* client_name;
	char* client_version;
} bep_hello_t;
uintptr_t bep_hello_encode(bep_hello_t* hello, char* buffer, uintptr_t buffer_size);
#endif
