class Solution {
public:
    long solve(int idx,int n,int buy,int cap,vector<int>& prices,vector<vector<vector<long>>>& dp)
    {
        if(idx==n) return 0;
        if(cap==0) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        if(buy)
        {
            return dp[idx][buy][cap]=max(-prices[idx]+solve(idx+1,n,0,cap,prices,dp),0+solve(idx+1,n,1,cap,prices,dp));
        }
        else 
        {
            return dp[idx][buy][cap]=max(prices[idx]+solve(idx+1,n,1,cap-1,prices,dp),0+solve(idx+1,n,0,cap,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<long>>> dp(n,vector<vector<long>>(2,vector<long>(3,-1)));
        return solve(0,n,1,2,prices,dp);
        
    }
};
