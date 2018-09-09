class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle =="") return 0;
        char fst = needle[0];
        size_t index = haystack.find(fst);
        int len = haystack.size();
        while(index < len)
        {
            size_t tempit = index;
            bool hasfind = true;
            for(int i = 0 ; i< needle.size();i++)
            {
                if(index >= len || (haystack[index++] != needle[i]))
                {
                    index = haystack.find(fst,tempit+1);
                    hasfind = false;
                    break;
                }
            }
            if(!hasfind) continue;
            return tempit;
        }
        return -1;
    }
};
