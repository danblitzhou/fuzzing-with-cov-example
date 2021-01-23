#include <stdio.h>
#include <string.h>
#include "hello.h"

int say_hello(const unsigned char *name) {
	return name[0] == 'H';
}
