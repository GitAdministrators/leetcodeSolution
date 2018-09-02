class Solution {
public:
    int romanToInt(string s) {
        bool bi =  false;
        bool bx =  false;
        bool bc =  false;
        int res = 0;
        for(int i = s.size()-1 ; i>=0;i--)
        {
            if(s[i] == 'I')
            {
                res += bi?-1:1;
            }
            else if(s[i] == 'V')
            {
                res += 5;
                bi = true;
            }
            else if(s[i] == 'X')
            {
                res += bx?-10:10;
                bi =true;
            }
            else if(s[i] == 'L')
            {
                res += 50;
                bx =true;
            }
            else if(s[i] == 'C')
            {
                res += bc?-100:100;
                bx = true;
            }
            else if(s[i]=='D')
            {
                res += 500;
                bc = true;
            }
            else if(s[i] == 'M')
            {
                res+=1000;
                bc=true;
            }
        }
        return res;
    }
};
