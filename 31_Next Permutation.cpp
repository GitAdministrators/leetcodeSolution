class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        bool ismin = true;
        for(int i = 1;i<len; i++)
        {
            if(nums[i-1] < nums[i])
            {
                ismin = false;
                break;
            }
        }
        if(ismin) reverse(nums.begin(),nums.end());
        else 
        {
            int index = len-1;
            for(int i = index ; i>0 ;i--)
            {
                if(nums[i] > nums[i-1]) 
                {
                    index = i-1;
                    break;
                }
            }
            int sindex = 0;
            for(int i = index + 1;i<len;i++)
            {
                if(nums[i] <= nums[index])
                {
                    break;
                }
                else
                {
                    sindex = i;
                }
            } 
            
            int temp = nums[index];
            nums[index] = nums[sindex];
            nums[sindex] = temp;
            reverse(nums.begin()+index + 1,nums.end());
        }
    }
};

