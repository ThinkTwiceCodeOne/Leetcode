class Solution {
public:
    void solve(int open,int close,int n,vector<string>& res,string str)
    {
        if(str.size()==n*2) 
        {
            res.push_back(str);
            return;
        }
        if(open<n) 
        {
            solve(open+1,close,n,res,str+"(");
        }
        if(close<open)
        {
            solve(open,close+1,n,res,str+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        vector<string> res;
        string str="";
        solve(open,close,n,res,str);
        return res;
    }
};
