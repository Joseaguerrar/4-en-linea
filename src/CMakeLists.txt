# TODO: Cambiar el nombre del destino. Este va a ser el nombre del ejecutable
set(TARGET_NAME PlantillaWxWidgets)
set(TARGET_NAME2 ANDAMIAJE)
project(${TARGET_NAME})
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

######################################## DEPENDENCIAS ########################################

# TODO: Si necesitan algún componente adicional de wxWidgets, agréguenlo a la lista( Preguntar al pofe)
find_package(wxWidgets REQUIRED COMPONENTS net core base)

if(wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

######################################## Configuración del proyecto ########################################

set(SRCS1
# TODO: Agregar aquí los archivos fuente de su proyecto
    main.cpp
    tablero.cpp
    jugadorIAInteligente.cpp
    jugadorHumano.cpp
    jugadorIAFacil.cpp
)

set(SRCS2
    tablero.cpp
    jugadorIAInteligente.cpp
    jugadorHumano.cpp
    jugadorIAFacil.cpp
    main2.cpp
)

if(APPLE)
    # create bundle on apple compiles
    add_executable(${TARGET_NAME} MACOSX_BUNDLE ${SRCS1})

    add_executable(${TARGET_NAME2} MACOSX_BUNDLE ${SRCS2})
    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    set_target_properties(${TARGET_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
    set_target_properties(${TARGET_NAME2} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    # the WIN32 is needed for Windows in order for it to look for WinMain
    # instead of the main function. This is ignored on other systems,
    # so it works on all platforms
    add_executable(${TARGET_NAME} WIN32 ${SRCS1} main.exe.manifest)
    add_executable(${TARGET_NAME2} WIN32 ${SRCS2} main2.cpp)
endif()

target_include_directories(${TARGET_NAME} PUBLIC ${INCLUDE_DIR})
target_link_libraries(${TARGET_NAME} ${wxWidgets_LIBRARIES})
target_include_directories(${TARGET_NAME2} PUBLIC ${INCLUDE_DIR})
target_link_libraries(${TARGET_NAME2} ${wxWidgets_LIBRARIES})


# Si quisieran generar otro ejecutable, con otro nombre, simplemente repitan el proceso:
# add_executable(NOMBRE_EJECUTABLE archivo1.cpp archivo2.cpp ...)
# target_include_directories(NOMBRE_EJECUTABLE PUBLIC ${INCLUDE_DIR})
# La siguiente línea solamente la necesitan si usan wxWidgets, sino no la agreguen:
# target_link_libraries(NOMBRE_EJECUTABLE ${wxWidgets_LIBRARIES})