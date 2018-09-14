class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump(nums,0);
    }
    
    bool canJump(vector<int>& nums ,int index)
    {
       int len = nums[index];
       if(len+index >= nums.size()-1) return true;
       for(int i = index+1; i<len+index+1;i++)
       {
           if(nums[i] + i > nums[index] + index)
               return canJump(nums,i);
       }
       return false;
    }
};
