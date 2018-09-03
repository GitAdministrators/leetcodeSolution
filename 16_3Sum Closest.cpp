class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty() || nums.size()<3) return {};
        int len = nums.size();
        std::sort(nums.begin(),nums.end());
        int res = INT_MAX;
        for(int i = 0; i<len;i++)
        {
            if(i>=1)
            {
                while(nums[i] == nums[i-1])
                {
                    i++;
                    continue;
                }
            }
            
            int l = i+1;
            int r = len-1;
            int min = INT_MAX;
            while(l<r)
            {
                int tmp = nums[i] +nums[l] + nums[r] - target;
                if(abs(tmp) < abs(min))
                {
                    min = tmp;
                }
                
                if(tmp > 0)
                {
                    r--;
                }
                else if(tmp<0)
                {
                    l++;
                }
                else 
                {
                    return tmp+target;
                }
            }
            res = abs(res) < abs(min)?res:min;
        }
        return res+target;
    }
};
