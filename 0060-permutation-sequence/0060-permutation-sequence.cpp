class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for(int i=1;i<=n;i++) {
            s+=to_string(i);
        }
        cout<<s<<endl;
        while(k>1) {
            next_permutation(s.begin(),s.end());
            //cout<<s<<" ";
            k--;
        }
        
        return s;
    }
};