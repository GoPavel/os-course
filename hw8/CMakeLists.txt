cmake_minimum_required(VERSION 2.8)

project(hw8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wunreachable-code -Werror=conversion -Wall -Wextra")

add_executable(${PROJECT_NAME}
        main.cpp
        sigsegv_dump.cpp
        sigsegv_dump.h)

# useful stuff
# -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2
# -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
# -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
