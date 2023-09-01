class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int n = a.size();
        int e1 = INT_MIN;
        int c1 = 0;
        int e2 = INT_MIN;
        int c2 = 0;
        for(int i=0;i<n;i++) {
            if(a[i]==e1) c1++;
            else if(a[i]==e2) c2++;
            else if(c1==0) {e1 = a[i]; c1++;}
            else if(c2==0){ e2 = a[i]; c2++;}
            
            else {
                c1--;
                c2--;
            }
        }
        vector<int>ans;
        //cout<<e1<<" "<<e2<<endl;
        c1 = 0;
        c2 = 0;
        for(int i=0;i<n;i++) {
            if(a[i]==e1) c1++;
            if(a[i]==e2) c2++;
        }
        
        if(c1>n/3) ans.push_back(e1);
        if(c2>n/3) ans.push_back(e2);
        
        return ans;
    }
};