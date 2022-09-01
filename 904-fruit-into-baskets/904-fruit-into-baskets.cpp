class Solution {
public:
    int totalFruit(vector<int>& a) {
        unordered_map<int,int>m;
        int i = 0;
        int j = 0;
        int n = a.size();
        int ans = 0;
        while(j<n) {
            m[a[j]]++;
            if(m.size()<=2) {
                ans = max(ans,j-i+1);
            }
            else if(m.size()>2) {
                while(m.size()>2) {
                    if(m[a[i]]>1) m[a[i]]--;
                    else m.erase(a[i]);
                    i++;
                }
                if(m.size()<=2) {
                ans = max(ans,j-i+1);
            }
            }
            j++;
        }
        return ans;
    }
};