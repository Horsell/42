#include "board.h"

Board::Board(int w, int h)
{
    width = w;
    height = h;

    board.resize(w);
    for (int i = 0; i < w ; i++){
        board[i].resize(h);
    }
}

vector<vector<int> >	Board::get_board()
{
	return (board);
}

int						Board::get_width()
{
	return (width);
}

int						Board::get_height()
{
	return (height);
}

void					Board::display()
{
	for (int i = 0 ; i < width ; i++)
	{
		for (int j = 0 ; j < height ; j++)
			cout << board[i][j];
		cout << endl;
	}
}

bool					Board::is_full()
{
	for (int i = 0 ; i < width ; i++)
	{
		for (int j = 0 ; j < height ; j++)
			if (board[i][j] == 0)
				return (false);
	}
	return (true);
}

bool					Board::is_end()
{
	if (is_full())
		return (true);
	return (false);
}

int						Board::put_token(int player, int line, int column)
{
	if (line >= width || column >= height)
		return (0);
	if (board[line][column] == 0)
		board[line][column] = player;
	else
		return (0);
	return (1);
}
