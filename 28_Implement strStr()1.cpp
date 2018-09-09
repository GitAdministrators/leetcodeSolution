class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        for(int i = 0 ; i< len1 -len2 +1 ; i++)
        {
            if(needle.compare(haystack.substr(i,len2).c_str()) == 0) return i;
        }
        return -1;
    }
};
