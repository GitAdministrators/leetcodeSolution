class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int len = nums.size();
        int index = 0;
        while(index<len)
        {
            if(nums[index] == val)
            {
                swap(nums[index] ,nums[len-1]);
                len--;
            }
            else
            {
                index++;
            }
        }        
        nums.resize(len);
        return len;
    }
};
