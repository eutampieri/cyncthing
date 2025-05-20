# Include the nanopb provided Makefile rules
include ../deps/nanopb/extra/nanopb.mk

# Compiler flags to enable all warnings & debug info
CFLAGS = -Wall -Werror -g -O0 -std=c99
CFLAGS += "-I$(NANOPB_DIR)"

# C source code files that are required
CSRC  = hello.c                    # The main program
CSRC += bep.pb.c                   # The compiled protocol definition
CSRC += $(NANOPB_DIR)/pb_encode.c  # The nanopb encoder
CSRC += $(NANOPB_DIR)/pb_decode.c  # The nanopb decoder
CSRC += $(NANOPB_DIR)/pb_common.c  # The nanopb common parts

# Build rule for the main program
simple: $(CSRC)
	$(CC) $(CFLAGS) -osimple $(CSRC)

# Build rule for the protocol
bep.pb.c: bep.proto
	$(PROTOC) $(PROTOC_OPTS) --nanopb_out=. bep.proto

