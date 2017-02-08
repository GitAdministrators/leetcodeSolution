class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int max_len = 0;
        int pos = -1;
        for(int i = 0;i<s.size();++i)
        {
            auto iter = hash.find(s[i]);
            if(iter!=hash.end()&& (iter->second >= pos))
            {
                pos = iter->second;
            }
            hash[s[i]] = i;
            max_len = max(max_len,i-pos);
        }
        return max_len;
    }
};
