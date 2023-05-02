class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int n = a.size();
        int c1=0,n1=-1,c2=0,n2=-1;
        for(int i=0;i<n;i++) {
            if(a[i]==n1) {
                c1++;
            }
            else if(a[i]==n2) {
                c2++;
            }
            else if(c1==0) {
                c1=1;
                n1=a[i];
            }
            else if(c2==0) {
                c2=1;
                n2=a[i];
            }
            else {
                c1--;
                c2--;
            }
        }
        cout<<n1<<" "<<c1<<endl;
        cout<<n2<<" "<<c2<<endl;
        cout<<endl;
        vector<int>ans;
        c1=0;
        c2=0;
        for(auto x:a) {
            if(x==n1) c1++;
            if(x==n2) c2++;
        }
        if(c1>n/3) ans.push_back(n1);
        if(c2>n/3 && n1!=n2) ans.push_back(n2);
        
        return ans;
    }
};