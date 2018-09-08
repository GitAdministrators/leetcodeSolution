class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size();
        if(len == 1) return len;
        
        int slow = 0;
        int fast = 0;
        for(int i = 0,j =i+1;j<nums.size();j++)
        {    
             slow = nums[i];
             fast = nums[j];
             if(slow != fast)
             {
                 i++;
                 nums[i] = fast;
             }
             else
             {
                 len--;
             }
        }
        return len;
    }
};
