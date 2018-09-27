class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> lessK;
        vector<int> equK;
        vector<int> bigK;
        srand(time(NULL));
        // 2  0 -1
        int idx = rand()%nums.size();
        for(int i = 0 ; i < nums.size();i++)
        {
            if(nums[i] < nums[idx]) lessK.push_back(nums[i]);
            else if(nums[i] == nums[idx]) equK.push_back(nums[i]);
            else bigK.push_back(nums[i]);
        }
        if(bigK.size() >= k) return findKthLargest(bigK,k);
        else if(bigK.size() < k && bigK.size() + equK.size() >= k) return equK[0];
        else return findKthLargest(lessK,k-bigK.size()- equK.size());
    }
};
