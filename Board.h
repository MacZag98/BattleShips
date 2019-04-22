#ifndef BOARD_H
#define BOARD_H

#include <iostream>

#include "Ship.h"

struct Square //field
	{
		bool if_ship = false; //if there is a ship
		bool if_discovered = false; //if discovered
	};

class Board
{
public:
	Board ();
	
	Board (bool if_player1)
	{
		this->if_player1 = if_player1;
	}
	
	Board (Ship *ship_arrangement, bool if_player1, int number_of_ships_placed = 10)
	{
		for (int i = 0; i < number_of_ships_placed; ++i)
		
			add_ship_to_board(ship_arrangement[i]);		
		
		if_player1 = if_player1;
	}

	~Board ()
	{
		delete game_field;
	}

	void add_ship_to_board(Ship ship_to_add)
	{
		int x, y, ship_length;
		bool if_ship_is_horizontal;
		
		x = ship_to_add.return_ship_starting_coordinates().x;
		y = ship_to_add.return_ship_starting_coordinates().y;
		ship_length = ship_to_add.return_ship_length();
		if_ship_is_horizontal = ship_to_add.return_if_ship_is_horizontal();

		if (if_ship_is_horizontal)
			
			for (int j = 0; j < ship_length; ++j)

				game_field[x+j][y].if_ship = 1;
			
		else
				
			for (int j = 0; j < ship_length; ++j)
					
				game_field[x][y+j].if_ship = 1;
	}

	void discover_field (Coordinates square_coordinates)
	{
		game_field[square_coordinates.x][square_coordinates.y].if_discovered = true;
	}

	bool if_discovered_square_is_ship(Square square)
	{
		return square.if_ship && square.if_discovered;
	}

	bool if_discovered_square_is_blank(Square square)
	{
		return !square.if_ship && square.if_discovered;
	}

	bool if_one_surrounding_squares_is_ship(Coordinates square_coordinates)
	{
		for (int i = -1; i <= 1; ++i)
			for (int j = -1; j <= 1; ++j)
			{
				if (i == 0 && j == 0)

					continue;

				if (0 <= square_coordinates.x < 10 && 0 <= square_coordinates.y < 10 && game_field[square_coordinates.x+j][square_coordinates.y+i].if_ship)
				
					return true
			}
		return false;
	}

	Square return_game_field (Coordinates square_coordinates)
	{
		return game_field[square_coordinates.x][square_coordinates.y];
	}

private:
	bool if_player1;
	Square game_field[10][10];
};

#endif // BOARD_H