class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char c) {
        
        int n = v.size();
        if(c>=v[n-1]) return v[0];
        int l = 0,r=n-1;
        while(l<r) {
            int mid = l + (r-l)/2;
            if(v[mid]<=c) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        return v[r];
    }
};