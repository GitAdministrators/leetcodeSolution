class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int res =1;
        int tmp =1;
        for(int i =1 ;i<nums.size();i++)
        {
            if(nums[i-1] +1 == nums[i])
            {
                tmp+=1;
            }
            else if(nums[i-1] == nums[i])
            {
                continue;
            }
            else
            {
                res =max(tmp,res);
                tmp =1;
            }
        }
        res =max(tmp,res);
        return res;
    }
};
