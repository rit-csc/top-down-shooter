CFLAGS = -ISFML/include -LSFML/lib

SFML/lib: SFML/CMakeLists.txt
	cd SFML && cmake . && make

SFML/CMakeLists.txt:
	git submodule init
	git submodule update

