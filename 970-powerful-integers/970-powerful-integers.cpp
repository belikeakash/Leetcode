class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int>a,b;
        int i = 1;
        a.push_back(i);
        if(x!=1) {
            while(i<bound) {
                i=i*x;
                a.push_back(i);
            }
        }
        
        i = 1;
        b.push_back(i);
        if(y!=1) {
            while(i<bound) {
                i=i*y;
                b.push_back(i);
            }
        }
        for(auto x:a) cout<<x<<" ";
        cout<<endl;
        for(auto x:b) cout<<x<<" ";
        vector<int>ans;
        set<int>s;
        int n1 = a.size();
        int n2 = b.size();
        for(int i=0;i<n1;i++) {
            for(int j=0;j<n2;j++) {
                int sum = a[i]+b[j];
                if(sum<=bound) s.insert(sum);
            }
        }
        for(auto x:s) ans.push_back(x);
        return ans;
    }
};