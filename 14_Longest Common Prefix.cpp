class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.empty()) return res;
        if(strs.size() == 1) return strs[0];
        
        for(int m = 0;m<INT_MAX;m++)
        {
            string tmp = "";
            for(int i = 1 ; i <strs.size(); i++)
            {
                if(strs[i-1].size()>m && strs[i].size()>m && strs[i-1][m] ==strs[i][m])
                {
                    tmp = strs[i-1][m];
                }
                else 
                {
                    return res;
                }
            }
            res += tmp;
        }
    }
};
