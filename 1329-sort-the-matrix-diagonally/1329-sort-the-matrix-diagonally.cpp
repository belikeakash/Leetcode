class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
        int m = a[0].size(),n = a.size();
        for(int g=0;g<m;g++) {
            vector<int>v;
            for(int i=0,j=g;i<n &&j<m;i++,j++) {
                v.push_back(a[i][j]);
                // cout<<a[i][j]<<" ";
            }
            int k = 0;
            sort(v.begin(),v.end());
            for(int i=0,j=g;i<n &&j<m;i++,j++) {
                a[i][j] = v[k];
                k++;
                // cout<<a[i][j]<<" ";
            }
            // cout<<endl;
        }
        for(int i=1;i<n;i++) {
            int k = i;
            int f = 0;
            vector<int>v;
            for(int j=0;j<m;j++) {
                if(k>=n) break;
                v.push_back(a[k][j]);
                cout<<a[k][j]<<" ";
                k++;
            }
            cout<<endl;
            k=i;
            sort(v.begin(),v.end());
            for(int j=0;j<m;j++) {
                if(k>=n) break;
                a[k][j] = v[f];
                k++;
                f++;
            }
        }
        // cout<<m<<" "<<n<<endl;
        return a;
    }
};