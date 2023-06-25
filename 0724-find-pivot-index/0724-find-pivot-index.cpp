class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int n = a.size();
        int tot = 0;
        int sum = 0;
        for(auto x:a) tot+=x;
        for(int i=0;i<n;i++) {
            if(sum==tot-sum-a[i]) return i;
            sum+=a[i];
        }
        
        return -1;
    }
};