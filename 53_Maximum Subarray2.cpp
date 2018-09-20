class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = maxsub(nums,0,nums.size() - 1);
        return max;
    }
    int maxsub(vector<int>& nums , int l,int h)
    {
        if(l== h) return nums[l];
        int m = (l+h)/2;
        return max(maxsub(nums,l,m),maxsub(nums,m+1,h),maxcross(nums,l,m,h));
    }
    int max(int a,int b )
    {
        return a>b?a:b;
    }
    
    int max(int a,int b ,int c)
    {
        return max(max(a,b),c);
    }
    int maxcross(vector<int>& nums,int l ,int m ,int h)
    {
         int sum = 0; 
        int left_sum = INT_MIN; 
     for (int i = m; i >= l; i--) 
    { 
        sum = sum + nums[i]; 
        if (sum > left_sum) 
          left_sum = sum; 
    } 
    sum = 0; 
    int right_sum = INT_MIN; 
    for (int i = m+1; i <= h; i++) 
    { 
        sum = sum + nums[i]; 
        if (sum > right_sum) 
          right_sum = sum; 
    }  
    return left_sum + right_sum; 
    }
};
