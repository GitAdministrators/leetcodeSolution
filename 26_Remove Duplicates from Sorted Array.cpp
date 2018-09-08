class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size();
        int pre = nums.front();
        auto it = nums.begin();
        it++;
        for(;it!=nums.end();)
        {
            if(pre == *it)
            {
                it= nums.erase(it);
                len--;
            }
            else
            {
                pre =*it;
                it++;
            }
        }
        return len;
    }
};
