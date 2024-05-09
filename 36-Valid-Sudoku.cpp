class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> rowsValid;
        set<char> colsValid;
        bool squaresValid[9][9]={false};

        for (int i = 0; i < 9; i++) {
            /*Outer loop to loop over all rows cols and squares*/
            for (int j = 0; j < 9; j++) {
                /*Inner loop to loop over elements*/
                if (board[i][j] != '.') {
                    if (rowsValid.count(board[i][j]) == 1) {
                        return false;
                    }
                    else {
                        rowsValid.emplace(board[i][j]);
                    }
                }
                if (board[j][i] != '.') {
                    if (colsValid.count(board[j][i]) == 1) {
                        return false;
                    }
                    else {
                        colsValid.emplace(board[j][i]);
                    }
                }
                if (board[i][j] != '.') {
                    int c =i/3 *3,r=j/3;
                    if(!squaresValid[c+r][board[i][j]-'1']){
                        squaresValid[c+r][board[i][j]-'1'] = true;
                    }else{
                        return false;
                    }
                }
            }
            rowsValid.clear();
            colsValid.clear();
        }


        return true;
    }
};