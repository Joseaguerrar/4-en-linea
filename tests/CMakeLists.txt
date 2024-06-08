enable_testing()

find_package(GTest REQUIRED)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)


add_executable(unit_tests
# TODO: Añadan acá todos los archivos de pruebas
    test_tablero.cpp
    test_jugadorHumano.cpp
    test_jugadorIAFacil.cpp
    test_jugadorIAInteligente.cpp
# TODO: Añadan acá el código fuente de su proyecto. Por ejemplo:
    ../src/tablero.cpp
    ../src/jugadorHumano.cpp
    ../src/jugadorIAFacil.cpp
    ../src/jugadorIAInteligente.cpp
)

target_link_libraries(unit_tests
    GTest::gtest
    GTest::gtest_main)

target_include_directories(unit_tests PUBLIC ${INCLUDE_DIR})

add_test(AllTests unit_tests)