class Solution {
public:
    string longestPalindrome(string s) {
        string ptstr = preprocess(s);
        int n = ptstr.length();
        int * p = new int[n];
        
        int mx =0 , po = 0;
        for(int i = 1 ;i<n;i++ )
        {
            if(mx > i) p[i] = min(p[2*po - i] , mx -i);
            else p[i] = 1;                        // 012345678
            while(ptstr[i-p[i]] == ptstr[i+p[i]]) // ^#c#c#c#$
                p[i]++;
            if(p[i] +i >mx)
            {
                mx= p[i] +i;
                po = i;
            }
        }
        int maxlen = 0;
        int maxbegin =0;
        
        for(int i = 1 ; i<n ;i++)
        {
            if(p[i] > maxlen)
            {
                maxlen = p[i];
                maxbegin = i;
            }
        }
        delete [] p;
        return s.substr((maxbegin + 1 - maxlen)/2 ,maxlen-1);   
    }
    
    string preprocess(string s)
    {
        int n = s.size();
        if(n == 0) return "^$";
        string tempstr = "^";
        for(int i=0;i<n;i++)
        {
            tempstr+= "#"+s.substr(i,1);
        }
        tempstr+="#$";
        return tempstr;
    }
    
};
