#include <iostream>
#include <vector>
// #include <map>
// #include <bitset>
// #include <algorithm>

using namespace std;

int getBoxIdx(int i, int j) {
    return (i / 3) * 3 + (j / 3);
}

bool isValidSudoku(vector<vector<char>>& board) {
    std::vector<unsigned> rows(9, 0);
    std::vector<unsigned> cols(9, 0);
    std::vector<unsigned> boxes(9, 0);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue; //skip if empty

            int b = getBoxIdx(i, j);
            int val = board[i][j] - '0';
            int idx = 1 << (9 - val);

            //since idx not 0 and only has 1 bit that is 1, if we and whatever is in row/col/box
            //with it, if the value we are checking exists, then it will return something not 0(true)
            //otherwise, if value doesn't yet exist, it will be 0(false)
            if (rows[i] & idx || cols[j] & idx || boxes[b] & idx) return false;

            //add bits back
            rows[i] |= idx;
            cols[j] |= idx;
            boxes[b] |= idx;
        }
    } 

    return true;
}

int main(){
    std::vector<std::vector<std::vector<char>>> inputs = {
        {{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}},

        {{'8','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}},

        {{'9','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}}
    };

    std:vector<bool> ans = {
        true,
        false,
        false
    };

    for (int i = 0; i < inputs.size(); ++i) {
        bool curr_ans = isValidSudoku(inputs[i]);
        if (curr_ans != ans[i]) {
            cout << i << ", " << ans[i] << ", " << curr_ans << endl;
        }
    }

    // unsigned temp = 0b000101001;
    // temp = 0b1 << 4 | temp;
    // cout << temp << endl;


    return 0;
}
