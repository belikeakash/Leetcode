class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        multiset<int>s;
        for(int i=0;i<k;i++) {
            s.insert(a[i]);
        }
        vector<int>ans;
        int maxi = *s.rbegin();
        ans.push_back(maxi);
        int j = k,i=0;
        while(j<a.size()) {
            s.insert(a[j]);
            s.erase(s.find(a[i]));
            maxi = *s.rbegin();
            ans.push_back(maxi);
            j++;
            i++;
        }
        return ans;
    }
};