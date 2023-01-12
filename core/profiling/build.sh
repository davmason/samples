#!/bin/bash

printf '  Building ...'

if [ ! -d "bin/" ]; then
    mkdir bin/
fi

pushd bin

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++
cmake ../ -DCMAKE_BUILD_TYPE=Debug

make -j8

popd

printf '  Copying binaries to main directory\n'
cp eventpipe/bin/libEventPipeProfiler.so .
cp eventpipe/bin/libSampleProfiler.so .

printf 'Done.\n'
