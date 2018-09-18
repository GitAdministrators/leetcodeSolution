class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     vector<vector<string>> res;
     std::unordered_map<string,vector<string>> hash_map;
     for(int i = 0 ; i<strs.size();i++)
     {
         string tmp = strs[i];
         strSort(tmp);
         if(hash_map.find(tmp)!=hash_map.end())
         {
             hash_map[tmp].push_back(strs[i]);
         }
         else
         {
             vector<string> vec;
             vec.push_back(strs[i]);
             hash_map[tmp] = vec;
         }
     }   
    for(auto it = hash_map.begin();it!=hash_map.end();it++)
    {
        res.push_back(it->second);
    }
     return res;
    }
    
     void strSort(string& s) {
        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            ++count[s[i] - 'a'];
        }
        s = "";
        for (int i = 0; i < 26; ++i) {
            while (count[i]--) {
                s += ('a' + i);
            }
        }
    }
    
};
