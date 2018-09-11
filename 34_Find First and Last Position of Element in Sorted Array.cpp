class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty() || target< nums[0] || target >nums[nums.size()-1]) return vector<int>{-1,-1};
        
        int lmid = 0,rmid = nums.size()-1;
        int l = 0 , r = nums.size()-1;
        while(l < r)
        {
            int len = (r-l)/2;
            if(nums[l+len] < target)
            {
                if(len == 0) 
                {
                  len=1;
                  l = l+len; 
                  break;
                }
                l=l+len;
            }
            else if(nums[l+len] >=target)
            {
                r= l+len;
            }
        }
        lmid = l;
        
        l= 0; r=nums.size()-1;
        while(l<r)
        {
            int len = (r-l)/2;
            if(nums[r-len] >target)
            {
                if(len==0)
                {
                   len =1;
                   r = r-len;
                   break;
                } 
                r= r-len;
            }
            else if(nums[r-len] <=target)
            {
                l = r-len;
            }

        }
        rmid = r;
        
        if(nums[lmid] == target && nums[rmid] == target) return vector<int>{lmid,rmid};
        return vector<int>{-1,-1};
    }
};
