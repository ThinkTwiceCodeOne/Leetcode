class Solution {
public:
    int solve(int idx,int n,vector<int>& nums,vector<int>& dp)
    {
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take=nums[idx]+solve(idx+2,n,nums,dp);
        int notTake=solve(idx+1,n,nums,dp);
        return dp[idx]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,n,nums,dp);
        
    }
};
