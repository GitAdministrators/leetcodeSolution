class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int cnt = 0;
        for(int i = 0 ;i<nums.size();i++)
        {
            if(cnt == 0 ||  res == nums[i])
            {
                res = nums[i];
                ++cnt;
            }
            else --cnt;
        }
        return res;
    }
};
