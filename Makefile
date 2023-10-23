protobuf:
	gcc -std=c99 -Wall protobuf/encode.c protobuf/tag.c protobuf/varint.c
bep:
	gcc -std=c99 -Wall bep/hello.c
build: protobuf bep
	echo ""
clean:
	rm a.out

all: build