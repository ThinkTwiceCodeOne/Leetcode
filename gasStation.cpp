class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int result=0;
        int tank=0;
        int totalCost=0;
        for(int i=0;i<gas.size();i++)
        {
            tank+=gas[i]-cost[i];
            if(tank<0)
            {
                result=i+1;
                totalCost+=tank;
                tank=0;
            }
        }      
        totalCost=totalCost+tank;
        if(totalCost>=0) return result;
        return -1;
    }
};
