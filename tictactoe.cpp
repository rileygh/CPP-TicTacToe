#include <iostream>
#include <array>

// The board is represented as a 3x3 array of characters.
// An empty cell is represented by a space character (' ').
// A cell occupied by player X is represented by an 'X' character.
// A cell occupied by player O is represented by an 'O' character.
std::array<std::array<char, 3>, 3> board{{
    {{' ', ' ', ' '}},
    {{' ', ' ', ' '}},
    {{' ', ' ', ' '}},
}};

// The current player is either 'X' or 'O'.
char current_player = 'X';

void print_board() {
  // Print the top row of column indices
    std::cout << "  0 1 2\n";

  // Print each row of the board
    for (int row = 0; row < 3; row++) {
    // Print the row index
        std::cout << row << ' ';

    // Print each cell in the row
        for (int col = 0; col < 3; col++) {
            std::cout << board[row][col] << ' ';
        }
        std::cout << '\n';
    }
}

bool check_row_win(int row) {
  // Check if the given row is a win for the current player
    return board[row][0] == current_player && board[row][1] == current_player && board[row][2] == current_player;
}

bool check_col_win(int col) {
  // Check if the given column is a win for the current player
    return board[0][col] == current_player && board[1][col] == current_player && board[2][col] == current_player;
}

bool check_diag_win() {
  // Check if either diagonal is a win for the current player
    return (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player) ||
            (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player);
}

bool check_win() {
  // Check if the current player has won the game
    for (int row = 0; row < 3; row++) {
        if (check_row_win(row)) {
            return true;
        }
    }

    for (int col = 0; col < 3; col++) {
        if (check_col_win(col)) {
            return true;
        }
    }

    return check_diag_win();
}

bool check_tie() {
  // Check if the game is a tie (i.e., no more empty cells)
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
  // The game loop
    while (true) {
        // Print the current board
        print_board();

        // Prompt the current player to make a move
        std::cout << "Player " << current_player << ", enter your move (row column): ";
        int row, col;
        std::cin >> row >> col;

        // Make the move
        board[row][col] = current_player;

        // Check if the current player has won the game
        if (check_win()) {
            std::cout << "Player " << current_player << " wins!\n";
            break;
        }

        // Check if the game is a tie
        if (check_tie()) {
            std::cout << "It's a tie!\n";
            break;
        }

        // Switch to the other player
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    return 0;
}
