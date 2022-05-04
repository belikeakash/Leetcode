class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& v, vector<int>& king) {
        int a = king[0];
        int b = king[1];
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>>ans(8,vector<int>(8,0));
        ans[a][b] = 1;
        vector<vector<int>>op;
        for(auto x:v) {
            int p = x[0];
            int q = x[1];
            ans[p][q] = 2;
        }
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                cout<<ans[i][j]<<" ";
            }  
            cout<<endl;
        }
        vector<int>s(2,0);
        for(int i=b;i<8;i++) {
            if(ans[a][i]==2){s[0]=a;s[1]=i; op.push_back(s); break;} 
        }
        for(int i=b-1;i>=0;i--) {
            if(ans[a][i]==2){s[0]=a;s[1]=i; op.push_back(s); break;} 
        }
        for(int i=a;i<8;i++) {
            if(ans[i][b]==2){s[0]=i;s[1]=b; op.push_back(s); break;}
        }
        for(int i=a-1;i>=0;i--) {
            if(ans[i][b]==2){s[0]=i;s[1]=b; op.push_back(s); break;}
        }
        for(int i=a,j=b;i<8&&j<8;i++,j++) {
            if(ans[i][j]==2) {s[0]=i;s[1]=j; op.push_back(s); break;}
        }
        for(int i=a,j=b;i<8&&j>=0;i++,j--) {
            if(ans[i][j]==2) {s[0]=i;s[1]=j; op.push_back(s); break;}
        }
        for(int i=a,j=b;i>=0&&j>=0;i--,j--) {
            if(ans[i][j]==2) {s[0]=i;s[1]=j; op.push_back(s); break;}
        }
        for(int i=a,j=b;i>=0&&j<8;i--,j++) {
            if(ans[i][j]==2) {s[0]=i;s[1]=j; op.push_back(s); break;}
        }
        return op;
    }
};