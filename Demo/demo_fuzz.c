#include <stdint.h>
#include <stddef.h>
#include "hello.c"
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (size > 0 && data[0] == 'H')
    if (size > 1 && data[1] == 'I') {
	int said = say_hello(data);
       	if (size > 2 && data[2] == '!') {
		__builtin_trap();
       	}

    }
  return 0;
}
