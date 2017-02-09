class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double dnum = 0.0;
        int total_size = nums1.size() + nums2.size();
        int index =total_size/2;
        int j = 0,k = 0;
        bool odd = total_size%2;
        vector<int> nums3;
        for(int i = 0;i<total_size;++i)
        {
            if(j<nums1.size()&&k<nums2.size())
            {
                if(nums1[j]>=nums2[k])
                {
                    nums3.push_back(nums2[k]);
                    ++k;
                }
                else
                {
                    nums3.push_back(nums1[j]);
                    ++j;
                }
            }
            else if(j<nums1.size())
            {
                nums3.push_back(nums1[j]);
                ++j;
            }
            else if(k<nums2.size())
            {
                nums3.push_back(nums2[k]);
                ++k;
            }
        }
        if(odd)
        {
            dnum = nums3[index];
        }
        else
        {
            dnum = ((double)nums3[index -1] + nums3[index])/2;
        }
        return dnum;
    }
};
