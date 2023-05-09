class Solution {
public:
    bool isValid(int i, int j, char c, vector<vector<char>>&a) {
        for(int x=0;x<9;x++) {
            if(a[i][x]==c) return 0;
            if(a[x][j]==c) return 0;
        }
        int u = i/3 * 3;
        int v = j/3 * 3;
        for(int x=u;x<u+3;x++){
            for(int y=v;y<v+3;y++) {
                if(a[x][y]==c) return 0;
            }
        }
        return 1;
    }
    int func(vector<vector<char>>&a) {
        bool ans = 0;
        bool flag = 0;
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++){
                if(a[i][j]=='.') flag = 1;
            }
        }
        if(!flag) return 1;
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(a[i][j]=='.') {
                    for(int x=1;x<=9;x++) {
                        char c = x+'0';

                        if(isValid(i,j,c,a)) {
                           // cout<<i<<" "<<j<<" "<<c<<endl;
                            a[i][j]=c;
                            ans = func(a);
                            if(ans) return 1;
                            a[i][j] = '.';
                        }
                        
                        }
                    return 0;
                        
                    }
                //if(ans==0) a[i][j] = '.';
                    
                    
                }
            }
        
        return 1;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        func(board);
    }
};