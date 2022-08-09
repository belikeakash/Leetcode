class Solution {
public:
    bool lemonadeChange(vector<int>& a) {
        map<int,int>m;
        int n = a.size();
        for(int i=0;i<n;i++){
            m[a[i]]++;
            int x = a[i] - 5;
            if(x==15) {
                if(m[10]>0 && m[5]>0) {
                    m[10]--;
                    m[5]--;
                }
                else if(m[5]>=3) {
                    m[5] = m[5]-3;
                }
                else return 0;
                
            }
            if(x==5) {
                if(m[5]>0) {
                    m[5]--;
                }
                else return 0;
            }
            
        }
        return 1;
    }
};