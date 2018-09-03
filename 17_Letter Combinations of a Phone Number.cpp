static string mattch[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
public:
    void processVec(vector<string>& res, string s)
    {
        int index = std::atoi(s.c_str());
        string tmp = mattch[index];
        vector<string> tmpvec;

         for(int i =0 ; i<res.size();i++)
         {
             for(int j = 0 ; j <tmp.size();j++)
            {
                 string cur = res[i];
                 tmpvec.push_back(cur.append(tmp.substr(j,1)));
            } 
        }

        res.clear();
        res = std::move(tmpvec);
    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        if(digits.empty()) return res;
        res.push_back("");
        for(int i = 0 ; i<digits.size();i++)
        {
            processVec(res,digits.substr(i,1));
        }
        return res;
    }
};
