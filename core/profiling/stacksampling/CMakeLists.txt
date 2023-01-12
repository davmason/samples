set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(NOT WIN32)
    add_compile_options(-Wno-invalid-noreturn -Wno-pragma-pack -Wno-int-to-pointer-cast -fPIC -fms-extensions -DBIT64 -DPAL_STDCPP_COMPAT -DPLATFORM_UNIX -DHOST_64BIT -std=c++11)
    add_link_options(--no-undefined -pthread)
endif(NOT WIN32)

if (WIN32)
    set(BASE_SOURCES
        ${BASE_SOURCES}
        src/SampleProfiler.def)
endif(WIN32)

set(SOURCES
    ${BASE_SOURCES}
    src/SampleProfiler.cpp
    src/dllmain.cpp
    src/sampler.cpp)

add_library(SampleProfiler SHARED ${SOURCES})