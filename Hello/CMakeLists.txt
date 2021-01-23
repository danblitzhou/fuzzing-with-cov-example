# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (Hello hello.c)
set(FUZZ_CFLAGS -O1 -fno-omit-frame-pointer -g -ggdb3 -fsanitize=fuzzer -fprofile-instr-generate -fcoverage-mapping -DFUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION)
# add coverage flags
#target_compile_options(Hello PUBLIC -fprofile-instr-generate -fcoverage-mapping)
target_compile_options(Hello PUBLIC ${FUZZ_CFLAGS})
#target_compile_options(Hello PUBLIC -fsanitize-coverage=trace-pc-guard)
# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (Hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
