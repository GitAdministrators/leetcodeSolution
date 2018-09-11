class Solution {
public:
    int longestValidParentheses(string s) {
        s.insert(s.begin(),')'); 
        vector<int> dp(s.size(),0);
        int res = 0;
        for(int i = 1; i<s.size();i++)
        {
            if(s[i]== ')')
            {
                if(s[i-1-dp[i-1]] == '(') dp[i]= dp[i-1]+2;
                dp[i] += dp[i-dp[i]];
            }            
            res = max(res,dp[i]);
        }
        return res;
    }
};
