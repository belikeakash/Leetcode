class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int>q;
        int n = a.size();
        for(int i=0;i<k;i++) {
            //if(q.size()==0) q.push_back(i);
            while(!q.empty() && a[i]>a[q.back()]) q.pop_back();
            q.push_back(i);
        }
        vector<int>ans;
        ans.push_back(a[q.front()]);
        for(int i=k;i<n;i++) {
            if(i-k>=q.front()) {
                q.pop_front();
            }
            while(!q.empty() && a[i]>a[q.back()]) q.pop_back();
            q.push_back(i);
            
            ans.push_back(a[q.front()]);
        }
        
        return ans;
    }
};