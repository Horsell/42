#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

# include <iostream>
# include <vector>

using namespace::std;
using std::vector;

class Board {
protected :
    int width;
    int height;
    vector<vector <int> > board;

public :
    Board(int w, int h);

    // getters :
    vector<vector<int> >	get_board();
    int					get_width();
    int					get_height();

    // state functions :
    void				display();
    bool				is_full();
    bool				is_end();
    int					win();

    // actions functions :
		// to play
    int					put_token(int player, int line, int column);
		// for algorithm
    int					undo(int line, int column);

};

#endif
