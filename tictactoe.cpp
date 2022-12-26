#include <iostream>
#include <array>

std::array<std::array<char, 3>, 3> board{{
    {{' ', ' ', ' '}},
    {{' ', ' ', ' '}},
    {{' ', ' ', ' '}},
}};

char current_player = 'X';

void print_board() {
    std::cout << "  0 1 2\n";

    for (int row = 0; row < 3; row++) {
        std::cout << row << ' ';

        for (int col = 0; col < 3; col++) {
            std::cout << board[row][col] << ' ';
        }
        std::cout << '\n';
    }
}

bool check_row_win(int row) {
    return board[row][0] == current_player && board[row][1] == current_player && board[row][2] == current_player;
}

bool check_col_win(int col) {
    return board[0][col] == current_player && board[1][col] == current_player && board[2][col] == current_player;
}

bool check_diag_win() {
    return (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player) ||
            (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player);
}

bool check_win() {
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
    while (true) {
        print_board();

        std::cout << "Player " << current_player << ", enter your move (row column): ";
        int row, col;
        std::cin >> row >> col;

        if (board[row][col] != ' ') {
        std::cout << "That cell is already occupied!\n";
        continue;
        }

        board[row][col] = current_player;

        if (check_win()) {
            std::cout << "Player " << current_player << " wins!\n";
            break;
        }

        if (check_tie()) {
            std::cout << "It's a tie!\n";
            break;
        }

        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    return 0;
}
