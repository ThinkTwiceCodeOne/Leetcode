class Solution {
public:
    int solve(int idx,int n,vector<int>& nums,vector<int>& dp)
    {
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = nums[idx]+solve(idx+2,n,nums,dp);
        int notTake=solve(idx+1,n,nums,dp);
        return dp[idx]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> temp1,temp2;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        vector<int> dp(n,-1);
        int ans1=solve(0,temp1.size(),temp1,dp);
        vector<int> dp1(temp2.size(),-1);
        int ans2=solve(0,temp2.size(),temp2,dp1);
        return max(ans1,ans2);
        
    }
};
