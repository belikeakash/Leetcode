class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int a1 = 0,a2=0;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i=0;i<s1.size();i++) {
            if(s1[i]>=s2[i]) a1++;
            if(s1[i]<=s2[i]) a2++;
        }
        cout<<a1<<" "<<a2<<endl;
        if(a1==s1.size() || a2==s1.size()) return 1;
        return 0;
    }
};