#include <iostream>
using namespace std;
class TICTAC {
private:
    char mat[3][3];
    char player;

public:
    TICTAC(char player = 'X') {
        this->player = player;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mat[i][j] = ' ';
            }
        }
    }

    void Matrix() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool enteredvalues(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && mat[row][col] == ' ') {
            mat[row][col] = player;
            return true;
        }
        return false;
    }

    bool checker() {
        for (int i = 0; i < 3; i++) {
            if (mat[i][0] == player && mat[i][1] == player && mat[i][2] == player) {
                return true;
            }
            if (mat[0][i] == player && mat[1][i] == player && mat[2][i] == player) {
                return true;
            }
        }
        if (mat[0][0] == player && mat[1][1] == player && mat[2][2] == player) {
            return true;
        }
        if (mat[0][2] == player && mat[1][1] == player && mat[2][0] == player) {
            return true;
        }
        return false;
    }

    bool drawfunction() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    void start() {
        cout << " ---start game--- " << endl;

        while (true) {
            Matrix();

            int row, col;
            cout << "Player " << player << ", enter your desire index  " << endl;
            cin >> row >> col;



            if (enteredvalues(row, col)) {

                if (checker()) {

                    Matrix();
                    cout << "Player " << player << " wins!" << endl;
                    break;
                }


                if (drawfunction()) {

                    Matrix();
                    cout << " **Draw**" << endl;
                    break;
                }


                if (player == 'X') {
                    player = 'O';
                }
                else
                    player = 'X';

            }
            else {
                cout << "Invalid move try again." << endl;
            }
        }
    }
};

int main() {
    TICTAC game;
    game.start();
    return 0;
}
