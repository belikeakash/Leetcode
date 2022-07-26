class Solution {
public:
    vector<int>v;
    int func(vector<int>&a, int c) {
        if(c>=a.size()-1) return 1;
        // if(a[c]==0) return 0;
        if(v[c]!=-1) {return v[c];}
        
        for(int i=c+1;i<=c+a[c];i++) {
            if(func(a,i)==1) return v[c] = 1;
        }
        return v[c] = 0;
    }
    bool canJump(vector<int>& a) {
        
        int n = a.size();
        if(n==1) return 1;
        v.resize(n,-1);
        bool ans = func(a,0);
        return ans;
    }
};