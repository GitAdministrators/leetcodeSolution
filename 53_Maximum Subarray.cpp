class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxsum  = nums[0];
        int leftsum = nums[0];
        int index = 1;
        while(index < nums.size())
        {
            if(leftsum + nums[index] <= 0)
            {
                maxsum= max(maxsum,max(nums[index],leftsum +nums[index]));
                leftsum = max(leftsum + nums[index], nums[index]); 
                if(leftsum < 0 ) leftsum =0;
                index++;
            }
            else
            {
                 leftsum = max(leftsum + nums[index],nums[index]);
                 maxsum= max(maxsum,max(nums[index],leftsum));
                 index++;
            }
        }
        return maxsum;
    }
};
