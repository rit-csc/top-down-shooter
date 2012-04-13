

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



