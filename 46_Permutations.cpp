class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int> > res;
        res.push_back(vector<int>{nums[0]});
        for(int i = 1 ;i < size;i++)
        {
            vector<vector<int>>  tmp;
            for(int j=0;j<res.size();j++)
            {
                int len = res[0].size();
                for(int k =0; k<=len;k++)
                {
                    auto t = res[j];
                    auto it = t.begin();
                    advance(it,k);
                    t.insert(it,nums[i]);
                    tmp.push_back(t);
                }
            }
            res = std::move(tmp);
        }
        return res;
    }
};
