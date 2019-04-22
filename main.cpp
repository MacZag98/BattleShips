#include <iostream>

#include "Game.h"
#include "Board.h"
#include "Ship.h"

int choose_ship_length();

bool choose_ship_axis();
bool if_ships_overlap(Ship ship1, Ship ship2);
bool if_both_ships_horizontal(bool if_ship1_is_horizontal, bool if_ship2_is_horizontal);
bool if_both_ships_vertical(bool if_ship1_is_horizontal, bool if_ship2_is_horizontal);

void arrange_ships(Ship *ship_arrangement);

Coordinates choose_coordinates();

int main()
{
	int x, y;
	Ship player1_ship_arrangement[10]; 
	Ship player2_ship_arrangement[10];
	
	return 0;
}

int choose_ship_length()
{
	int length;
	for (;;)
	{
		std::cout << "ship length (1-4):";
		std::cin >> length;
		if (0 < length < 5)
			return length;
		else
			std::cout << "wrong answer.\n";
	}
}

void arrange_ships(Ship *ship_arrangement) //dodaj sprawdzenie czy statki się nie nachodzą i wyświetlanie
{
	int ship_of_certain_length_limit[4] = {4, 3, 2, 1};
	for (int i = 0; i < 10; ++i)
	{
		
	}	
}

Ship add_ship(int *ship_of_certain_length_limit)
{
	int ship_length;
	for (;;)
	{
		std::cout << "available ship lengths:\n";
		for (int i = 0; i < 4; ++i)
		{
			std::cout << "length " << i+1 << " - " << ship_of_certain_length_limit[i] <<" ships.\n";
		}
		ship_length = choose_ship_length();
		--ship_of_certain_length_limit[ship_length-1];
		if (ship_of_certain_length_limit[ship_length-1] == -1)
		{
			++ship_of_certain_length_limit[ship_length-1];
			std::cout << "ship limit reached. choose other length.\n";
		}
		else

			break;
	}
	return Ship(choose_coordinates(), choose_ship_axis(), ship_length);
}

/*void arrange_ships(Ship *ship_arrangement) //dodaj sprawdzenie czy statki się nie nachodzą i wyświetlanie
{
	Coordinates square_coordinates;
	bool if_ship_is_horizontal;
	int ship_length = 1;
	int i = 0;

	while (i < 10)
	{
	std::cout << "Arrnage " << 5-ship_length <<" ships of length " << ship_length << ".\n";

		for (int k = 0; k < 5-ship_length; ++k)
		{
			square_coordinates = choose_coordinates();
			if_ship_is_horizontal = choose_ship_axis();
			
			for (int j = 0; j < i; ++j)
			{
				if (if_ships_overlap(ship_arrangement[j], square_coordinates, if_ship_is_horizontal, ship_length))
				{
					std::cout << "ships overlap. change coordinates or axis.";
					--j
				}
			
				else
				{
				}
			}
			ship_arrangement[i] = Ship(square_coordinates, if_ship_is_horizontal, ship_length);
			++i;
		}
		++ship_lenght;
	}

	std::cout << "Arrange 3 ships length 2.\n";

	for (int i = 4; i < 7; ++i)
	{
		ship_arrangement[i] = Ship(choose_coordinates(), choose_ship_axis(), 2);
	}

	std::cout << "Arrange 2 ships length 3.\n";

	for (int i = 7; i < 9; ++i)
	{
		ship_arrangement[i] = Ship(choose_coordinates(), choose_ship_axis(), 3);
	}

	std::cout << "Arrange 1 ship length 4.\n";

	for (int i = 9; i < 10; ++i)
	{
		ship_arrangement[i] = Ship(choose_coordinates(), choose_ship_axis(), 4);
	}
}*/

bool choose_ship_axis()
{
	char horizontality;
	for (;;)
	{
		std::cout << "is ship horizontal? (y/n): ";
		std::cin >> horizontality;

		if (horizontality == 'y')
			return true;

		else if (horizontality == 'n')
			return false;

		else
			std::cout << "Wrong answer.";
	}
}

Coordinates choose_coordinates()
{
	Coordinates square_coordinates;
	std::cout << "x: ";
	std::cin >> square_coordinates.x;
	std::cout << "y: ";
	std::cin >> square_coordinates.y;
	return square_coordinates;
}

void display_board (Board board_to_display)
{
	Coordinates square_coordinates;
	bool if_discovered_square_is_ship;
	bool if_discovered_square_is_blank;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			square_coordinates.x = j;
			square_coordinates.y = i;
			if_discovered_square_is_ship = board_to_display.if_discovered_square_is_ship(board_to_display.return_game_field(square_coordinates));
			if_discovered_square_is_blank = board_to_display.if_discovered_square_is_blank(board_to_display.return_game_field(square_coordinates));

			if (if_discovered_square_is_ship)
			{
				std::cout << "[*]";
			}
			else if (if_discovered_square_is_blank)
			{
				std::cout << "[x]";
			}
			else
			{
				std::cout << "[ ]";
			}
		}
		std::cout << "\n";
	}
}

bool if_ships_overlap(Ship ship1, Ship ship2)
{
	if (if_both_ships_horizontal(ship1.return_if_ship_is_horizontal(), ship2.return_if_ship_is_horizontal()))
		
		for (int i = 0; i < ship1.return_ship_length(); ++i)
			
			for (int j = 0; j < ship2.return_ship_length(); ++j)
				
				if (ship1.return_ship_starting_coordinates().y == ship2.return_ship_starting_coordinates().y && ship1.return_ship_starting_coordinates().x+i == ship2.return_ship_starting_coordinates().x+j)
					
					return true;
				
				else

					return false;
	else if (if_both_ships_vertical(ship1, ship2))
		
		for (int i = 0; i < ship1->return_ship_length(); ++i)
			
			for (int j = 0; j < ship2->return_ship_length(); ++j)
				
				if (ship1.return_ship_starting_coordinates().y+i == ship2.return_ship_starting_coordinates().y+j)
					
					return true;
				
				else

					return false;
}

bool if_both_ships_horizontal(bool if_ship1_is_horizontal, bool if_ship2_is_horizontal)
{
	if (if_ship1_is_horizontal && if_ship2_is_horizontal)
		
		return true;

	else

		return false;
}

bool if_both_ships_vertical(bool if_ship1_is_horizontal, bool if_ship2_is_horizontal)
{
	if (!if_ship1_is_horizontal && !if_ship2_is_horizontal)

		return true;

	else

		return false;
}