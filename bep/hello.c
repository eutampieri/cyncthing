#include <string.h>
#include "hello.h"
#include "../protobuf/encode.h"
#include "../protobuf/types.h"
#include "../utils/list.h"

uintptr_t bep_hello_encode(bep_hello_t* hello, char* buffer, uintptr_t buffer_size) {
    list_t device_name = {.value = hello->device_name, .length = strlen(hello->device_name)};
    list_t client_name = {.value = hello->client_name, .length = strlen(hello->client_name)};
    list_t client_version = {.value = hello->client_version, .length = strlen(hello->client_version)};
    return proto_encode(buffer, buffer_size, 3,
                        1, LEN, device_name,
                        2, LEN, client_name,
                        3, LEN, client_version
                 );
}