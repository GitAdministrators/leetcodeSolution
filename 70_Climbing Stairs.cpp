class Solution {
public:
    int climbStairs(int n) {
        int max = n/2;
        int res = 0;
        for(int i = 0 ; i<= max ; i++)
        {
            res+=getsub(n-2*i,i);
        }
        return res;
    }
private:
    int getsub(int nums1,int nums2)
    {
        if(nums1 == 0 || nums2 == 0) return 1;
        int cnt = nums1+nums2;
        unsigned long long sumcnt = 1,sumnums2 =1;
        if(nums1<nums2) nums2 =nums1;
        while(true)
        {
            sumcnt  *= cnt;
            sumnums2 *= nums2;
            while(sumcnt%2==0 && sumnums2%2==0)
			{
				sumcnt /= 2;
				sumnums2 /= 2;
			}
			while (sumcnt % 3 == 0 && sumnums2 % 3 == 0)
			{
				sumcnt /= 3;
				sumnums2 /= 3;
			}
            cnt--;nums2--;
            if(nums2<=0) break;
        }
        return sumcnt/sumnums2;
    }
};
