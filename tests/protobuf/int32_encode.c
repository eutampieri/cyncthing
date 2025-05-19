#include <stdio.h>
#include "../../protobuf/encode.h"

const char MESSAGE[] = {0x0d, 0x2a, 0x00, 0x00, 0x00};
const int VALUE = 42;

int main() {
    const int buf_len = 5;
    const char buffer[buf_len];
    proto_encode(&buffer, buf_len, 1, 1, I32, 42);
    for(int i = 0; i < buf_len; i += 1) {
        if(MESSAGE[i] != buffer[i]) {
            printf("In position %d: expected %#04x, found %#04x\n", i, MESSAGE[i], buffer[i]);
            return 1;
        }
    }
    return 0;
}