#include "protobuf/encode.h"
#include "protobuf/varint.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

int main() {
    char* buffer = malloc(PROTOBUF_DEFAULT_BUFFER_LENGTH);
    list_t v = {.value =  "Hello, World!\n"};
    v.length = strlen(v.value);
    varint_t n = proto_varint_new();
    n.int32 = UINT16_MAX;
    uintptr_t encoded = proto_encode(buffer,
                                     PROTOBUF_DEFAULT_BUFFER_LENGTH,
                                     1,
                                     /*1,
                                     LEN,
                                     v,*/
                                     2,
                                     VARINT, n);
    for(uintptr_t i = 0; i < encoded; i++) {
        printf("%c", buffer[i]);
    }
}
