#ifndef SHIP_H
#define SHIP_H

struct Coordinates
{
	int x;
	int y;
};

class Ship
{
public:
	Ship() 
	{
		ship_length = 0;
		if_ship_is_horizontal = 1;
		ship_starting_coordinates.x = -1;
		ship_starting_coordinates.y = -1;
	}

	Ship(Coordinates square_coordinates, bool if_ship_is_horizontal, int ship_length)
		{
			ship_length = ship_length;
			if_ship_is_horizontal = if_ship_is_horizontal;
			ship_starting_coordinates.x = square_coordinates.x;
			ship_starting_coordinates.y = square_coordinates.y;
		}
		
		int return_ship_length() 
		{
			return ship_length;
		}
		
		bool return_if_ship_is_horizontal() 
		{
			return if_ship_is_horizontal;
		}
		
		Coordinates return_ship_starting_coordinates() 
		{
			return ship_starting_coordinates;
		}
private:
	int ship_length;
	bool if_ship_is_horizontal;
	Coordinates ship_starting_coordinates;
};

#endif //SHIP_H