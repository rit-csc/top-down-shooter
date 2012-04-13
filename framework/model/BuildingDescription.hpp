#ifndef __BUILDING_DESCRIPTION_H__
#define __BUILDING_DESCRIPTION_H__

struct Cost {
	int cpuTime;
	int ram;
	int bitCoins;
	int powerToRun;
	int buildTime;
	int hddSpace;

};

struct BuildingDescription {
	int type;	//id of this building description
	string name;	//human readable building name
	int maxHealth;	//max health of building
	Size size;	//how much space the building takes up
	int losRadius;	//how far the building can see
	int maxMovementSpeed;	//>0 if the building can move (i.e. is a unit)
	Cost cost;
	
	//TODO stats on what the building can do, 'attack type/strength/rate', passability (can things move thorugh this building), can things be build on this building's location?, 	
}

#endif

