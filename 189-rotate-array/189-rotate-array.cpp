class Solution {
public:
    void rotate(vector<int>& a, int x) {
        int n = a.size();
        int k = x%n;
        reverse(a.begin(),a.end());
        reverse(a.begin(),a.begin()+k);
        reverse(a.begin()+k,a.end());
    }
};