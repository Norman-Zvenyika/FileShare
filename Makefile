test: libpack109.a main
	mkdir -p build/bin/release
	mkdir -p received

libpack109.a:
	g++ src/lib.cpp -c -Iinclude -std=c++11
	ar rs libpack109.a lib.o 
	mkdir -p build/lib/release
	mkdir -p build/objects/release
	mv *.o build/objects/release
	mv libpack109.a build/lib/release

clean:
	rm -f *.a
	rm -f *.o
	rm -rf build

main:
	g++ -c src/bin/main.cpp -Iinclude -o build/objects/release/main.o
	g++ build/objects/release/main.o -L build/lib/release -lpack109 -o server