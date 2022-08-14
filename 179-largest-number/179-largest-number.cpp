class Solution {
public:
    static bool cmp(int n1, int n2) {
        string s1 = to_string(n1);
        string s2 = to_string(n2);
        // cout<<s1<<" "<<s2<<endl;
        // int n1 = s1.size();
        // int n2 = s2.size();
        // int i = 0,j=0;
        // while(i<n1 && j<n2) {
        //     if(s1[i]>s2[i]) return 1;
        //     else if(s1[i]==s2[j]) {
        //         i++;
        //         j++;
        //     }
        //     else return 0;
        // }
        // string p = "";
        // string q = "";
        return s1+s2>s2+s1;
        // if(j==n2) {
        //     p=s2[j-1]+s1;
        //     q=s1+
        // }
        
    }
    string largestNumber(vector<int>& v) {
        vector<string>a;
        for(auto x:v) {
            string s = to_string(x);
            a.push_back(s);
        }
        sort(v.begin(),v.end(),cmp);
        string ans = "";
        for(auto x:v) {
            cout<<x<<" ";
            string s = to_string(x);
            ans+=s;
        }
        int flag = 0;
        for(int i=0;i<ans.size();i++) {
            if(ans[i]!='0') flag = 1;
        }
        if(!flag) return "0";
        return ans;
    }
};