class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        deque<int>q;
        for(int i=0;i<k;i++) {
            if(q.empty()) q.push_front(i);
            else {
                if(a[i]>a[q.front()]) {
                    q.push_front(i);
                }
                else {
                    while(a[i]>a[q.back()]) {
                        q.pop_back();
                    }
                    q.push_back(i);
                }
            }
        }
        cout<<q.front()<<endl;
        vector<int>ans;
        ans.push_back(a[q.front()]);
        int j = 0;
        for(int i=k;i<n;i++) {
            while(!q.empty() && q.front()<=j) q.pop_front();
            if(q.empty()) q.push_front(i);
            else {
                if(a[i]>a[q.front()]) {
                    q.push_front(i);
                }
                else {
                    while(a[i]>a[q.back()]) {
                        q.pop_back();
                    }
                    q.push_back(i);
                }
            }
            ans.push_back(a[q.front()]);
            j++;
        }
        
        return ans;
    }
};