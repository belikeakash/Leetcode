class Solution {
public:
    int majorityElement(vector<int>& a) {
        sort(a.begin(),a.end());
        int ans = a[0];
        int x = 1;
        for(int i=1;i<a.size();i++) {
            if(a[i]==a[i-1]) {
                x++;
                cout<<x<<" ";
                if(x>a.size()/2) {ans = a[i];  break;}
               
            }
            else {
                x = 1;
                
            }
        }
        
        return ans;
    }
};