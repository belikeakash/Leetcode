class Solution {
public:
    set<string>sk;
    vector<string>a;
    string v;
    void func(int i, string s) {
        if(i==s.size()) {
            sk.insert(v);
            return;
        }
        func(i+1,s);
        v+=s[i];
        func(i+1,s);
        v.pop_back();
    }
    void per(int i, string s) {
        if(i==s.size()-1) {a.push_back(s); return;}
        for(int j=i;j<s.size();j++) {
            if(j!=i && s[i]==s[j]) continue;
            swap(s[i],s[j]);
            per(i+1,s);
        }
    }
    int numTilePossibilities(string s) {
        sort(s.begin(),s.end());
        int n = s.size();
        per(0,s);
        for(auto x:a) {
            cout<<x<<" ";
            func(0,x);
        }
        cout<<endl;
        return sk.size()-1;
    }
};