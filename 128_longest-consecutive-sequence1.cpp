class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        std::unordered_set<int> set;
        for(int i : nums) set.insert(i);
        int res = 1;
        for(auto it = set.begin();it!=set.end();it++)
        {
            int cur =*it;
            int pre = cur-1;
            int next =cur+1;
            int tmppre = 1;
            int tmpnext =1;
            while(true)
            {
                auto preit = set.find(pre);
                if(preit == set.end()) break;
                set.erase(preit);
                pre-=1;
                tmppre+=1;
            }
            
            while(true)
            {
                auto nextit = set.find(next);
                if(nextit == set.end()) break;
                set.erase(nextit);
                next+=1;
                tmpnext+=1;
            }
            int sum = tmppre +tmpnext -1;
            res = max(res,sum);
        }
        return res;
    }
};
