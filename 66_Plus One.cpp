class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool add = true;
        for(auto it = digits.rbegin();it!=digits.rend();it++)
        {
            if(add) *it += 1;
            if(*it == 10)
            {
                *it = 0;
                add = true;
            }
            else add = false;
        }
        if(add) digits.insert(digits.begin(),1);
        return digits;
    }
};
