class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = haystack.size();
        int plen = needle.size();
        int next[50000];
        getnext(needle,next);
        int i =0,j=0;
        while(i<len && j<plen)
        {
            if(j==-1 || haystack[i] == needle[j])
            {
                i++; 
                j++;
            }
            else
            {
                j= next[j];
            }
        }
        if(j==plen) return i-j;
        return -1;
    }
    
    void getnext(string str,int* next)
    {
        int i,j;
        j = -1;
        next[0] = -1;
        i=0;
        int m = str.size();
        while(i<m)
        {
            while(-1!=j && str[i]!=str[j])j=next[j];
            next[++i]=++j;
        }
    }
};
