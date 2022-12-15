class Solution {
public:
    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void solve(int idx,vector<string>& path,vector<vector<string>>& res,string& s)
    {
        if(idx==s.size())
        {
            res.push_back(path);
            return ;
        }
        for(int i=idx;i<s.size();++i)
        {
            if(isPalindrome(s,idx,i))
            {
                path.push_back(s.substr(idx,i-idx+1));
                solve(i+1,path,res,s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(0,path,res,s);
        return res;
        
    }
};
