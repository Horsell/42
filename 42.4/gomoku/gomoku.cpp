#include "board.h"
#include "ai.h"

int		main(void)
{
	Board board(4, 4);
	board.display();
	if (board.put_token(1, 2, 4))
		cout << "Player 1 in 2:3\n";
	else
		cout << "Unable to play at the specified coordinates\n";
	board.display();
	return (0);
}
