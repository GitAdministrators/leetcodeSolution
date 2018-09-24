class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        if(m==0)
        {
            nums1 = std::move(nums2);
            return;
        }
        int i =m-1,j=n-1;
        int cnt = m+n-1;
        while(i>=0 || j>=0)
        {   
            if(i<0)
            {
                nums1[cnt] = nums2[j];
                cnt--;
                j--; 
                continue;
            }
            else if(j<0)
            {
                return;
            }
            if(nums1[i] < nums2[j])
            {
                nums1[cnt] = nums2[j];
                cnt--;
                j--;
            }
            else if(nums1[i] >= nums2[j])
            {
                nums1[cnt] = nums1[i];
                cnt--;
                i--;
            }
        }
    }
};
