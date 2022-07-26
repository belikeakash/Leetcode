class Solution {
public:
    int func(vector<int>&a, vector<int>&v, int c) {
        if(c>=a.size()-1) return 1;
        if(a[c]==0) return 0;
        if(v[c]!=-1) {return v[c];}
        
        for(int i=c+1;i<=c+a[c];i++) {
            if(func(a,v,i)==1) return v[c] = 1;
        }
        return v[c] = 0;
    }
    bool canJump(vector<int>& a) {
        
        int n = a.size();
        if(n==1) return 1;
        vector<int>v(n,-1);
        bool ans = func(a,v,0);
        return ans;
    }
};