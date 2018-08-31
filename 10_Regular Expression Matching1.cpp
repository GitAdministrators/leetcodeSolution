class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.size() > 1 && p.at(1) == '*')
        {
            return  isMatch(s,p.substr(2)) || (!s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.') && isMatch(s.substr(1),p)); 
        }
        else
        {
            return !s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.') && isMatch(s.substr(1),p.substr(1));     
        }
    }
};
