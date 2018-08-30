class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int len = s.size();
        if(len == 1) return s;
        
        string res = "";
        char **  cl = new char*[numRows];
        for(int i=0;i<numRows;i++)
        {
            cl[i] = new char[len/2 + 1];
            memset(cl[i],0,len/2 +1);
        }
     
        bool badd = true;
        for(int i =0, col = 0,cnt = -1;i<len;i++)
        {
            if(badd)
            {
                cl[++cnt][col] = s.at(i);
                if(cnt == numRows-1)
                {
                    badd = false;
                }
            }
            else
            {
                cl[--cnt][++col] =s.at(i);
                if(cnt == 0)
                {
                    badd = true;
                }
            }
            
        }
        for(int i=0;i<numRows;i++)
        {
            for(int j =0;j<len/2 + 1;j++)
                if(cl[i][j] != '\0') res += cl[i][j];
        }
        return res;
    }
};
