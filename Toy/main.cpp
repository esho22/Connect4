#include <iostream>
#include <cstdlib> // 3ashan rand() function
#include <ctime>   // 3ashan srand() function
using namespace std;

int panel[6][7] = { 0 };
int player = 1;
int ch;
bool endGame = false;

void Draw() {
    for (int k = 0; k < 7; k++) {
        cout << "  " << k + 1 << "  ";
    }
    cout << "\n===================================" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (panel[i][j] == 0)
                cout << "|   |";
            else if (panel[i][j] == 1)
                cout << "| x |";
            else if (panel[i][j] == 2)
                cout << "| o |";
        }
        cout << endl << "===================================" << endl;
    }
}

bool checkWin(int player) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (panel[i][j] == player && panel[i][j + 1] == player && panel[i][j + 2] == player && panel[i][j + 3] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            if (panel[i][j] == player && panel[i + 1][j] == player && panel[i + 2][j] == player && panel[i + 3][j] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (panel[i][j] == player && panel[i + 1][j + 1] == player && panel[i + 2][j + 2] == player && panel[i + 3][j + 3] == player) {
                return true;
            }
        }
    }

    for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (panel[i][j] == player && panel[i - 1][j + 1] == player && panel[i - 2][j + 2] == player && panel[i - 3][j + 3] == player) {
                return true;
            }
        }
    }

    return false;
}

void crackIt(int input) {
    if (input >= 0 && input < 7) {
        int rowIndex = 5;
        while (rowIndex >= 0) {
            if (panel[rowIndex][input] == 0) {
                panel[rowIndex][input] = player;
                break;
            }
            rowIndex--;
        }

        if (rowIndex < 0) {
            cout << "Column is full. Try another column." << endl;
            return;
        }

        if (checkWin(player)) {
            endGame = true;
            cout << "\nPlayer " << player << " wins!!" << endl;
        }
    }
    else {
        cout << "Wrong column number!" << endl;
    }
}

void playerMove() {
    int input;
    cout << "Player: " << player << endl;
    cout << "Enter column number (1-7): ";
    cin >> input;
    input--;
    crackIt(input);
}

void computerMove() {
    int randColumn;
    do {
        randColumn = rand() % 7;
    } while (panel[0][randColumn] != 0);

    crackIt(randColumn);
}

void Seta_Fy_sab3a() {
    srand(time(0));

    while (!endGame) {
        Draw();
        if (ch == 1) {
            if (player == 1) {
                playerMove();
            } else {
                cout << "Computer's Turn (Player 2)" << endl;
                computerMove();
            }

            if (checkWin(player)) {
                endGame = true;
                if (player == 1)
                    cout << "\nPlayer 1 wins!!" << endl;
                else
                    cout << "\nComputer (Player 2) wins!!" << endl;
            }

            player = (player == 1) ? 2 : 1;
        }
        else if(ch == 2)
            {
                if (player == 1) {
                    playerMove();
                } else {
                    cout << "Player 2" << endl;
                    playerMove();
                }

                if (checkWin(player)) {
                    endGame = true;
                    if (player == 1)
                        cout << "\nPlayer 1 wins!!" << endl;
                    else
                        cout << "\nPlayer 2 wins!!" << endl;
                }

                player = (player == 1) ? 2 : 1;
            }
        }
    }

int main(){
    cout << "If u need to play with ur computer press 1\nIf u need to play with ur friend press 2: \n";
    cin >> ch;
    Seta_Fy_sab3a();
    return 0;
}
