cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# TODO: Cambiar el nombre del proyecto/ya lo cambié
project(cuatroEnLinea LANGUAGES CXX)

include(FetchContent)

# TODO: Si requirieran cambiar la versión de C++, pueden hacerlo aquí(Creo que no)
# algunos valores válidos son 11, 14, 17, 20. Pueden ver más información acá:
# https://cmake.org/cmake/help/latest/manual/cmake-compile-features.7.html#manual:cmake-compile-features(7)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(tests)