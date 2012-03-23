CFLAGS = -ISFML/include -LSFML/lib

SFML/lib:
	cd SFML
	cmake .
	make
