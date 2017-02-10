class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int longest = 0;
        string max_str ="";
        if(n == 1)
        {
            return s;
        }
        for(int i =0;i<n-1;i++)
        {
            string temp ="";
            temp = ExpandAroundCenter(s,i,i);
            if(longest<temp.size())
            {
                max_str= temp;
                longest=temp.size();
            }
            temp = ExpandAroundCenter(s,i,i+1);
            if(longest<temp.size())
            {
                max_str= temp;
                longest=temp.size();
            }
        }
        return max_str;
    }
    string ExpandAroundCenter(string s,int cl,int cr)
    {
        int n = s.size();
        int l =cl , r=cr;
        while(l>=0 && r<=n-1 && s[l]==s[r])
        {
            --l;
            ++r;
        }
        return s.substr(l+1,r-l-1);
    }
};
