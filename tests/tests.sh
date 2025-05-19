#!/bin/bash
for f in $1/*.c
    do gcc $f ../../protobuf/*.c
    if ./a.out
    then echo $f: passed
    else echo $f: failed
    fi
    rm a.out
done