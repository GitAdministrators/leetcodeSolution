class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        vector<int> vecleft;
        vector<int> vecright;
        for(int i = 0 ; i<nums.size()-1 ; i++)
        {
            if(vecleft.empty()) vecleft.push_back(nums[i]);
            else vecleft.push_back(vecleft.back()*nums[i]);
        }
        
        for(int i = nums.size()-1; i>0 ; i--)
        {
            if(vecright.empty()) vecright.push_back(nums[i]);
            else vecright.push_back(vecright.back()*nums[i]);
        }
        res.push_back(vecright.back());
        for(int i = 1 ; i <nums.size()-1;i++)
        {
            res.push_back(vecleft[i - 1] * vecright[nums.size() - i - 2]);
        }
        res.push_back(vecleft.back());
        return res;
    }
};
