//
// Created by eugenio on 25/10/23.
//

#include "decode.h"

uintptr_t proto_decode_tag(char* buffer, uintptr_t buffer_length, uintptr_t* position) {
    if(*position > buffer_length) {
        return -1;
    }

}