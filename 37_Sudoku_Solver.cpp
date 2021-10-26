#include <iostream>
#include <vector>

using std::vector;

//trash
std::vector<char> possibleMoves(std::vector<std::vector<char>> board, int i, int j) {
    //retuns a list of possible moves for position (i, j)
    if (board[i][j] != '.') return std::vector<char>();

    std::vector<bool> pot(9, true);
    for (bool x : pot) {
        if (x) std::cout << "1";
        else std::cout << "0";
    }
    std::cout << std::endl;
    //check curr row
    for (int x = 0; x < 9; ++x) {
        if (board[i][x] != '.') {
            pot[board[i][x] - '1'] = false;
        }
    }
    //check curr col
    for (int y = 0; y < 9; ++y) {
        if (board[y][j] != '.') {
            pot[board[y][j] - '1'] = false;
        }
    }
    //check curr grid
    int grid = (i / 3) * 3 + (j / 3);
    int start_row = (grid / 3) * 3, start_col = (grid % 3) * 3;
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            if (board[y + start_row][x + start_col] != '.') {
                pot[board[y + start_row][x + start_col] - '1'] = false;
            }
        }
    }

    std::vector<char> ans;
    for (int z = 0; z < pot.size(); ++z) {
        if (pot[z]) {
            ans.push_back(z + '1');
        }
    }
    return ans;
}

//check if val is valid at (i, j)
bool checker(vector<vector<char>> board, int i, int j, char val) {
    //check row and col
    for (int x = 0; x < 9; ++x) if (board[i][x] == val) return false;
    for (int y = 0; y < 9; ++y) if (board[y][j] == val) return false;

    //check grid
    int row = i - i % 3, col = j - j % 3;

    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            if (board[row + y][col + x] == val) return false;
        }
    }
    return true;
}

bool solveHelper(vector<vector<char>> &board, int i, int j) {
    //recursive approach
    //for each grid, we try every char from 1 - 9. if it works for the current
    //cell, then move onto the next cell. do this until all cells done.
    if (i == 9) return true; //out of bounds, done
    if (j == 9) return solveHelper(board, i + 1, 0); //move onto next row

    if (board[i][j] != '.') return solveHelper(board, i, j + 1);

    for (char c = '1'; c <= '9'; ++c) {
        if (checker(board, i, j, c)) {
            board[i][j] = c;
            if (solveHelper(board, i, j + 1)) return true;
            //not true, so revert
            board[i][j] = '.';
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>> &board) {
    if(solveHelper(board, 0, 0)) {
        std::cout << "solved!" << std::endl;
    }
    else {
        std::cout << "not solved!" << std::endl;
    }
}

int main(){
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
