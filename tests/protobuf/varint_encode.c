#include <stdio.h>
#include "../../protobuf/encode.h"

const char MESSAGE[] = {0x08, 0x2a};
const int VALUE = 42;

int main() {
    const int buf_len = 5;
    const char buffer[buf_len];
    int end = proto_encode(&buffer, buf_len, 1, 1, VARINT, 42);
    for(int i = 0; i < end; i += 1) {
        if(MESSAGE[i] != buffer[i]) {
            printf("In position %d: expected %#04x, found %#04x\n", i, MESSAGE[i], buffer[i]);
            return 1;
        }
    }
    return 0;
}