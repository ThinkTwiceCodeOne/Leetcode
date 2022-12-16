class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans=0;
        int maxi=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                st.pop();
                if(st.empty()) st.push(i);
                else 
                {
                    ans=i-st.top();
                    maxi=max(ans,maxi);
                }
            }
            if(s[i]=='(')
            {
                st.push(i);
            }

        }
        return maxi;
        
    }
};
