class Solution {
public:
    vector<int> pancakeSort(vector<int>& a) {
        int j = a.size();
        vector<int>b;
        for(auto x:a) b.push_back(x);
        sort(b.begin(),b.end());
        vector<int>ans;
        while(1) {
            bool flag = 0;
            for(int i=0;i<a.size();i++) {
                if(a[i]!=b[i]) flag=1;
            }
            for(int i=0;i<a.size();i++) {
                cout<<a[i]<<" ";
            }
            cout<<endl;
            if(flag==0) break;
            int i = -1;
            for(i=0;i<j;i++) {
                if(a[i]==j) break;
            }
            for(int p=0;p<=i/2;p++) {
                swap(a[p],a[i-p]);
            }
            for(int i=0;i<a.size();i++) {
                cout<<a[i]<<" ";
            }
            cout<<endl;
            i++;
            ans.push_back(i);
            ans.push_back(j);
            
            reverse(a.begin(),a.begin()+j);
            j--;
        }
        return ans;
    }
};