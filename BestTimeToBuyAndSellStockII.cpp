lass Solution {
public:
    long solve(int idx,int n,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(idx==n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        long profit=0;
        if(buy) 
        {
            profit=max(-prices[idx]+solve(idx+1,n,0,prices,dp),0+solve(idx+1,n,1,prices,dp));
        }
        else
        {
            profit=max(prices[idx]+solve(idx+1,n,1,prices,dp),0+solve(idx+1,n,0,prices,dp));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,n,1,prices,dp);
        
    }
};
