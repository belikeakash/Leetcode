class Solution {
public:
    int halveArray(vector<int>& nums) {
        vector<double>a;
        double sum = 0;
        priority_queue<double>q;
        for(auto x:nums) {
            double c = x*1.0;
            a.push_back(c);
            q.push(c);
            sum+=c;
        }
        double p = sum/2;
        double u = 0;
        int ans = 0;
        while(u<p) {
            double c = q.top();
            cout<<c<<" ";
            u+=c/2;
            q.pop();
            q.push(c/2);
            ans++;
        }
        cout<<endl;
        return ans;
    }
};