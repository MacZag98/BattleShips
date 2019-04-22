#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game
{
	public:
		Game(Ship *player1_ship_arrangement, Ship *player2_ship_arrangement)
		{
			player1_board = Board(player1_ship_arrangement, 1); //1 means that this is player1
			player2_board = Board(player2_ship_arrangement, 0); //0 means that this is player2
		}
		
		bool if_hit(Coordinates square_coordinates, bool if_player1_turn)
		{
			return true;
		}

		void mark_result()
		{

		}

	private:
		Board player1_board;
		Board player2_board;
};

#endif // GAME_H