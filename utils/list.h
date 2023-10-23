#include <stdint.h>
#ifndef UTILS_LIST_H
#define UTILS_LIST_H
typedef struct list {
	uintptr_t length;
	char* value;
} list_t;
#endif
