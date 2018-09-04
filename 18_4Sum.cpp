class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::set<vector<int> > res;
        if(nums.size() <4 )  return vector<vector<int>> {};
        std::sort(nums.begin(),nums.end());
        for(int i = 0 ;i<nums.size()-3 ;i++)
        {
            if(i>=1 && nums[i] == nums[i-1])
            {
                continue;
            }
            
            int threesum = target - nums[i];
            for(int head = i+1; head <nums.size()-2  ;head++ )
            {
            int mid = head+1;
            int tail = nums.size() - 1;
            
            while(mid < tail)
            {
                int tmpsum = nums[head] + nums[mid] + nums[tail];
                if(tmpsum < threesum)
                {
                    mid++;
                }
                else if(tmpsum > threesum)
                {
                    tail--;
                }
                else 
                {
                    std::vector<int> ans{nums[i],nums[head],nums[mid],nums[tail]};
                    res.insert(ans);
                    mid++;
                    tail--;
                }
            }
            }
        }
        return vector<vector<int> >(res.begin(),res.end());    
    }
};
