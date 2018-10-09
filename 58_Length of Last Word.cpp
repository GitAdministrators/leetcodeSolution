class Solution {
public:
    int lengthOfLastWord(string s) {
        int res= 0;
        bool in = false;
        auto it = s.rbegin();
        while(it!=s.rend())
        {
            while(it!=s.rend() && (*it>='a' && *it<='z') || (*it>='A' && *it<='Z'))
            {
                res++;
                it++;
            }
            if(res!=0) break;
            else it++;
        }
        return res;
    }
};58. Length of Last Word
