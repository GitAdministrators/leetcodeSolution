class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        vector<vector<bool> > dp(slen+1, vector<bool >(plen+1 , false));
        dp[0][0] = true;
        for(int i = 0;i<=slen;i++)
        {
            for(int j = 1;j<=plen;j++)
            {
                if(j>1 && p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-2] || (i>0 && (s[i-1] ==  p[j-2] || p[j-2]=='.') &&dp[i-1][j]);
                }
                else
                {
                    dp[i][j] =  i>0 && (s[i-1] ==  p[j-1] || p[j-1]=='.') && dp[i-1][j-1];
                }
            }
        }
        return dp[slen][plen];
    }
};
