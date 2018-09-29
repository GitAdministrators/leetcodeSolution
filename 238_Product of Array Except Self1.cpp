class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        res.resize(nums.size(),1);
        for(int i = 0; i<nums.size();i++)
        {
            if(i==0) res[i] = nums[i];
            else res[i] = res[i-1]*nums[i];
        }
        res[nums.size()-1] =res[nums.size()-2];
        int right =1;
        for(int i = nums.size()-2;i>=0;i--)
        {
            right *= nums[i+1];
            if(i>0) res[i] = res[i-1] * right;
        }
        res[0] =right;
        return res;
    }
};
