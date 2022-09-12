class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner() {
        // cout<<s.size();
    }
    
    int next(int x) {
        // if(s.size()<2) return s.size();
        int y = 0;
        int ans = 1;
        while(s.size() > 0 && x>=s.top().first) {
            // cout<<"a";
            ans+=s.top().second;
            s.pop();
        }
        // cout<<endl;
        s.push({x,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */