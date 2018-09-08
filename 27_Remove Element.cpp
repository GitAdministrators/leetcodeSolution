class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int len = nums.size();
        int slow =0;
        int fast = 0;
        for(int i =-1 ,j=0;j<nums.size();j++)
        {
            if(nums[j] == val)
            {
                len--;
            }
            else
            {
                i++;
                nums[i] =nums[j];
            }
        }
        nums.resize(len);
        return len;
    }
};
