class Solution {
public:
    vector<string> fullJustify(vector<string>& v, int maxi) {
        vector<string>res;
        int n = v.size();
        vector<string>a;
        a.push_back(v[0]);
        int sz=v[0].size(); 
        for(int i=1;i<v.size();i++) {
            if(sz+v[i].size()+a.size()<=maxi) {
                sz+=v[i].size();
                a.push_back(v[i]);
            }
            else {
                string ans = "";
                int d = maxi - sz;
                //cout<<sz<<" "<<a.size()<<endl;
                if(a.size()==1) {
                    ans+=a[0];
                    for(int j=0;j<d;j++) ans+=" ";
                }
                else {
                    int minD = d/(a.size()-1);
                    
                    int x = d%(a.size()-1);
                    //cout<<minD<<" "<<<<endl;
                    for(int j=0;j<a.size()-1;j++) {
                        ans+=a[j];
                        for(int k=0;k<minD+(x>0);k++) {
                            ans+=" ";
                        }
                        x--;
                    }
                    ans+=a[a.size()-1];
                    
                }
                a.clear();
                a.push_back(v[i]);
                sz = v[i].size();
                res.push_back(ans);
            }
            
            
        }
        string ans = "";
                int d = maxi - sz;
                if(a.size()==1) {
                    ans+=a[0];
                }
                else {
                    for(int j=0;j<a.size()-1;j++) {
                        ans+=a[j];
                        ans+=" ";
                        d--;
                    }
                    ans+=a[a.size()-1];
                    
                }
                for(int j=0;j<d;j++) ans+=" ";
                res.push_back(ans);
        return res;
    }
};