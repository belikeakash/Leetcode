class Solution {
public:
    int minDeletion(vector<int>& a) {
        stack<int>s;
        int n = a.size();
        for(int i=0;i<n;i++) {
            while(!s.empty() && s.size()%2==1 && a[s.top()]==a[i]) {
                s.pop();
            }
            s.push(i);
        }
        cout<<s.size()<<endl;
        return (s.size())%2==0?n-s.size():n-s.size()+1;
        
    }
};