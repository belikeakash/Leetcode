class Solution {
    int dp[1001][1002];
public:
    int solve(int idx,int prev,int n,unordered_map<int,vector<int>> &mp,vector<int> &nums) {
        if(idx >= n) {return 0;}
        if(dp[idx][prev+1]!=-1) {return dp[idx][prev+1];}

        int ans = 1;
        
        if(prev == -1) {
            for(int i=idx+1;i<n;i++) {
                ans = max(ans, 1 + solve(i,idx,n,mp,nums));
            }
        }else {
            int next = nums[idx]+(nums[idx]-nums[prev]);
            if(mp.find(next)==mp.end()) {return 1;}
            int nextIdx = lower_bound(mp[next].begin(),mp[next].end(), idx+1)-mp[next].begin();
            //cout<<next<<" "<<idx<<" "<<nextIdx<<endl;
            if(nextIdx==mp[next].size()) {return 1;}
            ans = max(ans, 1+ solve(mp[next][nextIdx], idx,n, mp,nums));
        }   
        return dp[idx][prev+1]=ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        unordered_map<int,vector<int>> mp;
        int n = nums.size();

        for(int i=0;i<nums.size();i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 1;
        for(int i=0;i<nums.size();i++) {
            ans = max(ans, solve(i,-1,n,mp,nums));
        }
        return ans;
    }
};