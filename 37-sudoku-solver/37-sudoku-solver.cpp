class Solution {
public:
    bool isValid(char c, int row, int col, vector<vector<char>>&board) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] != '.' && board[i][col] == c) return false; //check row
            if(board[row][i] != '.' && board[row][i] == c) return false; //check column
            if(board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] != '.' && 
board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; //check 3*3 block
        }
        return true;
    }
    bool func(vector<vector<char>>& a) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(a[i][j]=='.') {
                    for(int k=1;k<=9;k++) {
                        char c = (char)k+'0';
                        if(isValid(c,i,j,a)) {
                            a[i][j]=c;
                            if(func(a)) return 1;
                            else a[i][j]='.';
                        }       
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& a) {
        func(a);
    }
};