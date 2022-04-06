MCC=emcc

all: sudoku.cpp
	$(EMCC) -O3 -s WASM=1 -o main.js -s EXTRA_EXPORTED_RUNTIME_METHODS='["getValue", "setValue"]' -s EXPORTED_FUNCTIONS="['_calloc', '_SolveSudoku']" -s EXPORT_ES6=1 -s MODULARIZE=1 sudoku.cpp
