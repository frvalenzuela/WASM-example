
EMCC=emcc

all: fib.c
	$(EMCC) -O3 -s WASM=1 -s EXPORT_ES6=1 -s EXPORTED_FUNCTIONS="['_fib']" -o fibWASM.js fib.c