class Solution {
public:
    bool isValid(string s) {
        std::vector<char> vec;
        for(int i = 0 ; i<s.size();i++)
        {
            if(s[i]=='(' || s[i] == '{' || s[i] == '[')
            {
                vec.push_back(s[i]);
            }
            else if(  !vec.empty() && ( (s[i] == ')' && vec.back() == '(')
               || (s[i] == '}' && vec.back() == '{')
               || (s[i] == ']' && vec.back() == '[')))
            {
                vec.pop_back();
            }
            else
            {
                return false;
            }
        }
        return vec.empty()?true:false;
    }
};
