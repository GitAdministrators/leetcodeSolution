class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        int cur = 0;
        for(int i = 0;i<nums.size();)
        {  
            if(i+1 <nums.size() && nums[i] ==nums[i+1])
            {
                int val = nums[i];
                if(cur == i)
                {
                    i+=2;
                    cur+=2;
                    while(i<nums.size() &&nums[i] == val) i++;
                }
                else
                {
                   swap(nums[cur++],nums[i++]);
                   swap(nums[cur++],nums[i++]);
                   while(i<nums.size() && nums[i] ==val) i++;
                }
                len+=2;
            }
            else
            {
               if(cur == i)
               {
                   len+=1;
                   i+=1;
                   cur+=1;
               }
               else
               {
                   swap(nums[cur++],nums[i++]);
                   len+=1;
               }
            }
        }
        return len;
    }
};
