class Solution {
public:
    long long int solve(vector<int>& nums,int n,int idx,vector<long long int>& dp)
    {
        if(idx>=n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        long long int ans=INT_MAX;
        for(int i=idx+1;i<=(idx+nums[idx]);i++)
        {
            ans=min(ans,1+solve(nums,n,i,dp));
        }
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<long long int> dp(n,-1);
        return solve(nums,n,0,dp);
        
    }
};
