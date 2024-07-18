#include <iostream>
using namespace std;

class TTT 
{
    int Grid[3][3]; 

public:
    TTT() 
    {
        for (int i = 0; i < 3; ++i) 
	   {
            for (int j = 0; j < 3; ++j) 
		  {
                Grid[i][j] = 0;
            }
        }
    }

    void print_grid() 
    {
        for (int i = 0; i < 3; ++i) 
	   {
            for (int j = 0; j < 3; ++j) 
		  {
                if (Grid[i][j] == 1) 
			 {
                    cout << "O";
                } else if (Grid[i][j] == 2) 
			 {
                    cout << "X";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
    }

    bool valid_move(int row, int col) 
    {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && Grid[row][col] == 0);
    }

    void make_move(int player, int row, int col) 
    {
        if (valid_move(row, col)) 
	   {
            Grid[row][col] = player;
        }
	    else 
	   {
            cout << "Invalid move. Try again." << endl;
        }
    }

    int game_status() 
    {
        for (int i = 0; i < 3; ++i) 
	   {
            if (Grid[i][0] == Grid[i][1] && Grid[i][1] == Grid[i][2] && Grid[i][0] != 0) {
                return Grid[i][0];
            }
            if (Grid[0][i] == Grid[1][i] && Grid[1][i] == Grid[2][i] && Grid[0][i] != 0) {
                return Grid[0][i];
            }
        }
      
        if (Grid[0][0] == Grid[1][1] && Grid[1][1] == Grid[2][2] && Grid[0][0] != 0) 
	   {
            return Grid[0][0];
        }
        if (Grid[0][2] == Grid[1][1] && Grid[1][1] == Grid[2][0] && Grid[0][2] != 0) 
	   {
            return Grid[0][2];
        }
     
        for (int i = 0; i < 3; ++i) 
	   {
            for (int j = 0; j < 3; ++j) 
		  {
                if (Grid[i][j] == 0) 
			 {
                    return 0;
                }
            }
        }
        return 3; 
    }
};

int main() 
{
    TTT game;
    int player = 1;
    int row, col;
    int status;

    while (true) 
    {
        game.print_grid();
        cout << "Player " << (player == 1 ? "O" : "X") << ", Enter your move (row and column): ";
        cin >>row >> col;

        if (game.valid_move(row, col)) 
	   {
            game.make_move(player, row, col);
            status = game.game_status();
            if (status == 1) 
		  {
                game.print_grid();
                cout << "Player O wins!" << endl;
                break;
            } 
		  else if (status == 2) 
		  {
                game.print_grid();
                cout << "Player X wins!" << endl;
                break;
            } 
		  else if (status == 3) 
		  {
                game.print_grid();
                cout << "The game is a draw!" << endl;
                break;
            }
            player = (player == 1) ? 2 : 1;
        } 
	   else 
	   {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}

