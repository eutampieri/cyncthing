//
// Created by eugenio on 25/10/23.
//
#include <inttypes.h>
#include "types.h"
#include "varint.h"

#ifndef CYNCTHING_DECODE_H
#define CYNCTHING_DECODE_H

uintptr_t proto_decode_tag(char* buffer, uintptr_t buffer_length, uintptr_t* position);

#endif //CYNCTHING_DECODE_H
