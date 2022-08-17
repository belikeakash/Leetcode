class Solution {
public:
    int maxSum(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        int i = 0;
        int j = 0;
        long long s1=0,s2=0,s=0;
        while(i<n1 && j<n2) {
            if(a[i]==b[j]) {
                s1 = s2 = max(s1,s2) + a[i];
                cout<<s<<" ";
                // s1=0;
                // s2=0;
                i++;
                j++;
            }
            else if(a[i]<b[j]) {
                s1+=a[i];
                i++;
            }
            else {
                s2+=b[j];
                j++;
            }
        }
        // s+=max(s1,s2);
        while(i<n1) {s1+=a[i]; i++;}
        while(j<n2) {s2+=b[j]; j++;}
        cout<<endl;
        s =max(s1,s2)%1000000007;
        return s;
    }
};