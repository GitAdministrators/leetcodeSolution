class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty() || nums.size()<3 ) return {};
        vector<vector<int> > res;
        std::sort(nums.begin(),nums.end());
        int len = nums.size();
        for(size_t i = 0;i<len;i++)
        {
           if(nums[i]>0) break;
            
            if(i>=1)
            {
                while(nums[i]==nums[i-1])
                {
                    i++;
                    continue;
                }
            }
            
            int j = i+1;
            int r = len-1;
            while(j < r)
            {
                if(nums[i]+nums[j] + nums[r] < 0)
                {
                    j++;
                }
                else if(nums[i]+nums[j] + nums[r] >0)
                {
                    r--;
                }
                else
                {
                    std::vector<int> tmp{nums[i],nums[j],nums[r]};
                    res.push_back(tmp);
                    while(j<r && nums[j] == nums[j+1]) j++;
                    while(j<r && nums[r] == nums[r-1]) r--;
                    j++;
                    r--;
                }
            }
        }
        return res;
        
    }
};
