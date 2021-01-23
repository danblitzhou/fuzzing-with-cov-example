# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable (helloDemo demo.c)

set(FUZZ_CFLAGS -O1 -fno-omit-frame-pointer -g -ggdb3 -fsanitize=fuzzer -fprofile-instr-generate -fcoverage-mapping -DFUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION)
set(FUZZ_NL_CFLAGS -O1 -fno-omit-frame-pointer -g -ggdb3 -fsanitize=fuzzer-no-link -fprofile-instr-generate -fcoverage-mapping -DFUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION)
target_compile_options(helloDemo PUBLIC ${FUZZ_NL_CFLAGS})

#target_compile_options(helloDemo PUBLIC -fsanitize-coverage=trace-pc-guard)
# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (helloDemo LINK_PUBLIC Hello)
#target_link_libraries(helloDemo PRIVATE -fsanitize-coverage=trace-pc-guard)
target_link_libraries(helloDemo PRIVATE ${FUZZ_NL_CFLAGS})

set(EXE_NAME "helloFuzz")
add_executable(${EXE_NAME} demo_fuzz.c)


#target_compile_options(${EXE_NAME} PRIVATE -Wno-macro-redefined)
#target_compile_options(${EXE_NAME} PRIVATE -g)
#target_compile_options(${EXE_NAME} PRIVATE -fdeclspec)

#target_compile_options(${EXE_NAME} PRIVATE  -fsanitize-coverage=trace-pc-guard)

target_link_libraries(${EXE_NAME} PRIVATE Hello)

#target_compile_options(${EXE_NAME} PRIVATE -fsanitize=fuzzer,address,undefined -fprofile-instr-generate -fcoverage-mapping)
target_compile_options(${EXE_NAME} PRIVATE ${FUZZ_CFLAGS})
#target_link_libraries(${EXE_NAME} PRIVATE -fsanitize=fuzzer,address,undefined 
#  -fprofile-instr-generate -fcoverage-mapping)
target_link_libraries(${EXE_NAME} PRIVATE ${FUZZ_CFLAGS})
