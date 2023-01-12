cmake_minimum_required (VERSION 3.14)

project(ProfilerSamples)

set(BASE_SOURCES )

include_directories(common)

add_subdirectory(eventpipe)
add_subdirectory(stacksampling)
