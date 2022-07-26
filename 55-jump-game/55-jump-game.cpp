class Solution {
public:
   
    bool canJump(vector<int>& a) {
        int n = a.size();
        int c = 0;
        for(int i=n-2;i>=0;i--) {
            c++;
            if(c<=a[i]) c = 0;
            
        }
        if(c==0) return 1;
        return 0;
    }
};