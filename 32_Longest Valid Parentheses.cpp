class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        std::stack<char> stc;
        int len = s.size();
        int rec[len] = {0};
        int index = 0;
        for(int i = 0 ; i<len;i++)
        {
            if(s[i] == '(')
            {
                stc.push(s[i]);
                index++;
            }
            else 
            {
                if(!stc.empty()&& stc.top() == '(')
                {
                    stc.pop();
                    rec[index]++;
                    index--;
                    rec[index] +=rec[index + 1];
                    rec[index+1] = 0;
                }
                else
                {
                    index++;
                }
            }
        }
        int max= 0;
        for(int i = 0 ;i<len ;i++)
        {
            if(rec[i] >max) max = rec[i];
        }
        return max*2;
    }
};
