#include <iostream>
using namespace std;

int panel[6][7] = {0};
int player = 1;
bool endGame = false;

void Draw() {
    for (int k = 0; k < 7; k++) {
        cout << "  " << k + 1 << "  ";
    }
    cout << "\n===================================" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if(panel[i][j] == 0)
                cout << "|   |";
            else if(panel[i][j] == 1)
                cout << "| x |";
            else if(panel[i][j] == 2)
                cout << "| o |";
        }
        cout << endl << "===================================" << endl;
    }
}

bool checkWin(int player) {
    // Check horizontally
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (panel[i][j] == player && panel[i][j + 1] == player && panel[i][j + 2] == player && panel[i][j + 3] == player) {
                return true;
            }
        }
    }

    // Check vertically
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            if (panel[i][j] == player && panel[i + 1][j] == player && panel[i + 2][j] == player && panel[i + 3][j] == player) {
                return true;
            }
        }
    }

    // Check diagonally
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (panel[i][j] == player && panel[i + 1][j + 1] == player && panel[i + 2][j + 2] == player && panel[i + 3][j + 3] == player) {
                return true;
            }
        }
    }

    // Check diagonally
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
    } else {
        cout << "Wrong column number!" << endl;
        return;
    }
}

int main() {
    int input;
    while (!endGame) {
        Draw();
        cout << "Player: " << player<< endl;
        cout << "Enter column number (1-7): ";
        cin >> input;
        input--;
        crackIt(input);
        if (player == 1)
            player = 2;
        else
            player = 1;
    }
    return 0;
}
