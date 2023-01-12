set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(NOT WIN32)
    add_compile_options(-Wno-invalid-noreturn -Wno-pragma-pack -Wno-int-to-pointer-cast -fPIC -fms-extensions -DBIT64 -DPAL_STDCPP_COMPAT -DPLATFORM_UNIX -DHOST_64BIT -std=c++17)
    add_link_options(--no-undefined -pthread)
endif(NOT WIN32)

if (WIN32)
    set(BASE_SOURCES
        ${BASE_SOURCES}
        src/EventPipeProfiler.def)

    add_compile_options(/std:c++17)
endif(WIN32)

set(SOURCES
    ${BASE_SOURCES}
    src/EventPipeProfiler.cpp
    src/dllmain.cpp
    src/eventpipemetadatareader.cpp
    src/eventpipeeventprinter.cpp)

add_library(EventPipeProfiler SHARED ${SOURCES})