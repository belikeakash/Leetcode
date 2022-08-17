class Solution {
public:
    bool isPossible(vector<int>& a) {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>m;
        int p = 0;
        for(auto x:a) {
            if(!m[x-1].empty()) {
                int y = m[x-1].top();
                // cout<<y<<" ";
                m[x-1].pop();
                m[x].push(++y);
                if(y==3) p--;
                
            }
            else {
                m[x].push(1);
                p++;
            }
        }
        return p== 0;
//         cout<<endl;
//         for(auto x:m) {
//             cout<<x.first<<" ";
//             if(x.second.size()<3) { return 0;}
//         }
        
//         return 1;
    }
};