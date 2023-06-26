class Solution {
public:
    long long totalCost(vector<int>& a, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q1,q2;
        unordered_map<int,int>m;
        int n = a.size();
        for(int i=0;i<x;i++) {
            q1.push({a[i], i});
            m[i]=1;
        }
        for(int i=n-1;i>=n-x;i--) {
            if(m[i]) break;
            q2.push({a[i], i});
            m[i]=1;
        }
        int i = x;
        int j = n-x-1;
        int cnt = n;
        long long ans = 0;
        while(k>0) {
            int a1 = INT_MAX;
            int a2 = INT_MAX;
            if(!q1.empty()) {
                a1 = q1.top().first;
            }
            if(!q2.empty()) {
                a2 = q2.top().first;
            }
            if(a2<a1) {
                //cout<<a2<<" "<<q2.top().second<<endl;
                if(!q2.empty()) q2.pop();
                if(!m.count(j)) {q2.push({a[j], j}); m[j]=1; j--;}
               
                
                cnt--;
                ans+=a2;
            }
            else if(a1<a2) {
                cout<<a1<<" "<<q1.top().second<<endl;
                if(!q1.empty()) q1.pop();
             
                if(!m.count(i) && i<n) {q1.push({a[i], i}); m[i]=1; i++;}
               
                cnt--;
                ans+=a1;
            }
            else {
                int pos1 = INT_MAX;
                int pos2 = INT_MAX;
                if(!q1.empty()) pos1 = q1.top().second;
                if(!q2.empty()) pos2 = q2.top().second;
                
                if(pos2<pos1) {
                    if(!q2.empty()) q2.pop();
                    if(!m.count(j)) {q2.push({a[j], j}); m[j]=1; j--;}
                    cout<<a2<<endl;
                    
                    cnt--;
                    ans+=a2;
                }
                else {
                    if(!q1.empty()) q1.pop();
                    
                    if(!m.count(i)) {q1.push({a[i], i}); m[i]=1; i++;}
                    
                    
                    cnt--;
                    ans+=a1;
                }
            }
            k--;
            // cout<<a1<<" "<<a2<<endl;
            if(cnt<x) break;
        }
        while(k>0) {
            
            int a1 = INT_MAX;
            int a2 = INT_MAX;
            
            if(!q1.empty()) {
                a1 = q1.top().first;
            }
            if(!q2.empty()) {
                a2 = q2.top().first;
            }
            cout<<a1<<" "<<a2<<endl;
            if(a2<a1) {
                if(!q2.empty()) q2.pop();
                ans+=a2;
            }
            else {
                if(!q1.empty()) q1.pop();
                ans+=a1;
            }
            k--;
        }
    
        return ans;
    }
};