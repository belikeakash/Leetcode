class Solution {
public:
    int minAbsoluteDifference(vector<int>& a, int x) {
        multiset<int>s;
        
        int n = a.size();
        for(int i=x;i<n;i++) {
            s.insert(a[i]);
        }
        int mini = INT_MAX;
        for(int i=0;i<n-x;i++) {
            auto it = s.lower_bound(a[i]);
            cout<<*it<<" ";
            if(it!=s.end()) {
                mini = min(mini, abs(*it - a[i]));
            }
            if(it!=s.begin()) {
                mini = min(mini, abs(*std::prev(it) - a[i]));
            }
            s.erase(s.find(a[i+x]));
        }
        
        return mini;
    }
};