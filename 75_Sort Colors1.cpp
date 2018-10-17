class Solution {
public:
    void sortColors(vector<int>& nums) {
        int  b = -1;
        int  e = nums.size();
        // 2 0 1 
        // 0 0 0 2 0 2
        for(int i = 0 ;i<e;)
        {
            if(nums[i] == 0)
            {
                swap(nums[i++],nums[++b]);
            }
            else if(nums[i] ==2)
            {
                swap(nums[i],nums[--e]);
            }
            else
            {
                i++;
            }
        }
    }
};
