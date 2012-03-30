CFLAGS = -ISFML/include -LSFML/lib

SFML/lib: SFML/CMakeLists.txt
	cd SFML && cmake . && make
	cp -r SFML/lib Frameworks

SFML/CMakeLists.txt:
	git submodule init
	git submodule update

