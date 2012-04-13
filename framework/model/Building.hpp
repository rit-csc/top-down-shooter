#ifndef __BUILDING__
#define __BUILDING__

class Building {

	private:
		Building(int type, Location location);

		Size size;
		Location location;
		int health;
		int type;
		
	public:
		static Building createBuilding(BuildingDescription type);
		
		Size getSize();
		Location getLocation();
		int getHealth();

};

#endif
