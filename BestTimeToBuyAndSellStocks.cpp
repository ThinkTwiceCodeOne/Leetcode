class Solution {
public:
    int maxProfit(vector<int>& v) {
        int mini=v[0];
        int profit=0;
        for(int i=1;i<v.size();i++)
        {
            int cost=v[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,v[i]);
        }
        return profit;
    }
};
