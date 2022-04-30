class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a1, vector<int>& a2) {
        int s1=0,s2=0;
        for(auto x:a1) s1+=x;
        for(auto x:a2) s2+=x;
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        int d = s1-s2;
        vector<int>ans;
        bool flag = 0;
        for(int i=0;i<a1.size();i++) {
            int l = 0,r=a2.size()-1;
            while(l<=r) {
                int mid = l+(r-l)/2;
                cout<<a1[i]-a2[mid]<<" ";
                if(2*(a1[i]-a2[mid])==d) {
                    flag = 1;
                    cout<<a1[i]-a2[mid]<<endl;
                    ans.push_back(a1[i]);
                    ans.push_back(a2[mid]);
                    break;
                }
                else if(2*(a1[i]-a2[mid])<d) {
                    r = mid-1;
                }
                else {
                    l = mid+1;
                }
            }
            if(flag==1) {
                break;
            }
        }
        cout<<endl;
        return ans;
    }
};