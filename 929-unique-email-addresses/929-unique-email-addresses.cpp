class Solution {
public:
    int numUniqueEmails(vector<string>& v) {
        set<string>s;
        for(auto x:v) {
            int n = x.size();
            int i = 0;
            string p = "";
            bool flag = 0;
            while(i<n) {
                if(x[i]=='.'&& flag == 0){
                    i++;
                    continue;
                }
                if(x[i]=='@') flag = 1;
                else if(x[i]=='+') {
                    while(x[i]!='@' && i<n) {
                        
                        i++;}
                    if(x[i]=='@') flag = 1;                    
                }
                p+=x[i];
                i++;
                // cout<<i<<" ";
            }
            s.insert(p);
        }
        for(auto x:s) cout<<x<<" ";
        cout<<endl;
        return s.size();
    }
};