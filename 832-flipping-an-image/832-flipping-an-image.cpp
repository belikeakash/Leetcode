class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& a) {
        int n = a.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(a[i][j]==1) a[i][j]=0;
                else if(a[i][j]==0) a[i][j]=1;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++) {
            int l = 0,r=n-1;
            while(l<r) {
                swap(a[i][l],a[i][r]);
                l++;
                r--;
            }
        }
        return a;
    }
};