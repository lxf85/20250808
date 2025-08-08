cmake_minimum_required(VERSION 3.10.0)
project(0808-5 VERSION 0.1.0 LANGUAGES C)

add_executable(0808-5 0808-5.c main.c)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
