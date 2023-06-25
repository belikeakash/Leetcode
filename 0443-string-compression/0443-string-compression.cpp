class Solution {
public:
    int compress(vector<char>& v) {
        int n = v.size();
        int ans = 0;
        int c = 1;
        vector<pair<char, int>>a;
        for(int i=1;i<n;i++) {
            if(v[i]==v[i-1]) c++;
            else {
                if(c==1) {
                    ans+=1;
                }
                else if(c>1 && c<=9) {
                    ans+=2;
                }
                else if(c>9 && c<=99) {
                    ans+=3;
                }
                else if(c>99 && c<=999) {
                    ans+=4;
                }
                else ans+=5;
                a.push_back({v[i-1], c});
                c = 1;
            }
        }
        if(c==1) {
            ans+=1;
                }
        else if(c>1 && c<=9) {
            ans+=2;
        }
        else if(c>9 && c<=99) {
            ans+=3;
        }
        else if(c>99 && c<=999) {
            ans+=4;
        }
        else ans+=5;
        
        a.push_back({v[n-1], c});
        int i = 0;
        for(auto x:a) {
            v[i] = x.first;
            i++;
            if(x.second==1) continue;
            string u = to_string(x.second);
            
            for(int j=0;j<u.size();j++) {
                v[i] = u[j];
                i++;
            }
        }
        return ans;
    }
};