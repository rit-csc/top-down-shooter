CFLAGS = -ISFML/include -LSFML/lib

SFML/CMakeLists.txt:
	git submodule init
	git submodule update

SFML/lib: SFML/CMakeLists
	cd SFML
	cmake .
	make
