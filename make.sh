# make sure the is a ranlib on libboost
/emsdk/upstream/bin/llvm-ranlib /core/Common/3dParty/boost/boost_1_58_0/build/linux_32/static/libboost_regex.a
make x2t
cp ./build/bin/linux_32/x2t ./build/bin/linux_32/x2t.bc
gcc -Wl,--no-check-features -O0 -g -s USE_ICU=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s USE_PTHREADS=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=["ccall"] -s EXPORT_ALL=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s TOTAL_MEMORY=268435456 -s ALLOW_MEMORY_GROWTH=1 -s WASM_MEM_MAX=1073741824 -s WASM=1 ./build/bin/linux_32/x2t.bc ./build/lib/linux_32/libCryptoPPLib.a ./build/lib/linux_32/libXlsFormatLib.a ./build/lib/linux_32/libkernel.so ./build/lib/linux_32/libdoctrenderer.so ./build/lib/linux_32/libHtmlRenderer.so ./build/lib/linux_32/libUnicodeConverter.so ./build/lib/linux_32/libPdfWriter.so ./build/lib/linux_32/libPdfReader.so ./build/lib/linux_32/libgraphics.so ./Common/3dParty/boost/boost_1_58_0/stage/lib/libboost_regex.a -lnodefs.js -o x2t.js
