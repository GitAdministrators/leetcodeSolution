class Solution {
public:
    void sortColors(vector<int>& nums) {
        int b = 0;
        int e = nums.size()-1;
        //2 0 1
        for(int i=0;i<=e;)
        {
            if(nums[i]==0)
            {
                if(i==b)
                {
                    i++;
                    b++;
                    continue;
                }
                swap(nums[i],nums[b]);
                b++;
            }
            else if(nums[i]==2)
            {
                if(i==e)
                {
                    i++;
                    e--;
                    continue;
                }
                swap(nums[i],nums[e]);
                e--;
            }
            else
            {
                i++;
            }
        }
    }
};
