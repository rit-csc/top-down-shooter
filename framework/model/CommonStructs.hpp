#ifndef __COMMON_STRUCTS_H__
#define __COMMON_STRUCTS_H__

enum Orientation {
	North,
	East,
	South,
	West,
};

struct Location {
	int mapRow;
	int mapColumn;
	Orientation faces;
};

struct Size {
	int width;
	int height;
};


#endif
