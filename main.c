#include "protobuf/encode.h"
#include "protobuf/varint.h"
#include "bep/hello.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#define __USE_XOPEN_EXTENDED
#include <unistd.h>

int main() {
    char* buffer = malloc(PROTOBUF_DEFAULT_BUFFER_LENGTH);
    char* hostname = malloc(PROTOBUF_DEFAULT_BUFFER_LENGTH);
    gethostname(hostname, PROTOBUF_DEFAULT_BUFFER_LENGTH);
    bep_hello_t hello = {.device_name = hostname, .client_version="0.1", .client_name="cyncthing"};
    uintptr_t encoded = bep_hello_encode(&hello, buffer, PROTOBUF_DEFAULT_BUFFER_LENGTH);
    for(uintptr_t i = 0; i < encoded; i++) {
        printf("%c", buffer[i]);
    }
    free(buffer);
    free(hostname);
}
