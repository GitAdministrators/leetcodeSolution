class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<vector<int>> res;
        vector<int> tmp;
    
        bc(res,tmp,c,t,0);
        
        return vector<vector<int> >(res.begin(),res.end());
    }
    
    void bc(vector<vector<int>>& res,vector<int>& tmp, vector<int>& c , int t ,int index)
    {
        if(t<0)
        {
            return;
        }
        else if(t== 0)
        {
            res.push_back(tmp);
            return;
        }
        
        for(int i =index;i<c.size();i++)
        {
            if(i == index || c[i] != c[i-1])
            {
            tmp.push_back(c[i]);
            bc(res,tmp,c,t-c[i],i+1);
            tmp.pop_back();
            }
        }
    }
};
