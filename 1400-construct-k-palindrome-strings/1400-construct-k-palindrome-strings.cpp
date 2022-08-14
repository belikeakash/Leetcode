class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k==n) return 1;
        else if(k>n) return 0;
        vector<int>a(26,0);
        for(auto x:s) {
            a[x-'a']++;
        }
        int eve = 0, odd=0;
        for(int i=0;i<26;i++) {
            if(a[i]%2==0) eve+=a[i]/2;
            else odd++;
        }

        // if(2*eve + odd < k) return 0;
        if(odd>k) return 0;
        else return 1;
    }
};