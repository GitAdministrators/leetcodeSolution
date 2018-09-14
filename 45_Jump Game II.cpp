class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        if(nums.size() == 1) 
        {
            return 0;
        }
        jump(nums,0,count);
        return count;
    }
    void jump(vector<int>& nums,int index,int & count)
    {
        int len = nums[index];
        if(index + len >= nums.size()-1)
        {
            count++;
            return;
        }
        
        int max = 0;
        int maxindex = -1;
        
        
        for(int i =index +1 ;i<len+index+1 ; i++)
        {
            if(nums[i] + i >= max)
            {
                max =  nums[i] +i;
                maxindex = i;
            }
        }
        count+=1;
        jump(nums,maxindex,count);
    }
};
