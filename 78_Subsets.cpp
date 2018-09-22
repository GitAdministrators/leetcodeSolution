class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) return res;
        res.push_back(vector<int>());
        vector<int> tmp;
        dfs(0,nums,tmp,res);
        return res;
    }
    
    void dfs(int index,vector<int>& nums ,vector<int>& tmp,vector<vector<int> >& res)
    {   
        for(int i =index;i<nums.size();i++)
        {
             tmp.push_back(nums[i]);    
             res.push_back(tmp);
             dfs(i+1,nums,tmp,res);
             tmp.pop_back();
        }
    }
};
