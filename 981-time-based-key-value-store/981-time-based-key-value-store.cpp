class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>m;
    TimeMap() {
        cout<<m.size();
    }
    
    void set(string key, string s, int t) {
        m[key].push_back({s,t});
    }
    
    string get(string k, int t) {
        if(!m.count(k)) return "";
        string ans = "";
        int l = 0,r = m[k].size()-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(m[k][mid].second==t) {
                return m[k][mid].first;
            }
            else if(m[k][mid].second<t) {
                ans = m[k][mid].first;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        cout<<endl;
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */