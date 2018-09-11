class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int len = nums.size();
        if(len == 1) return target>nums[0]?1:0;
        int l = 0 , r= len -1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] >target)
            {
                r = mid - 1;
            }
            else if(nums[mid] <target)
            {
                l = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return l;
    }
};
