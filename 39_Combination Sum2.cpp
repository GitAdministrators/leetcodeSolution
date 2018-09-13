class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<vector<int>> res;
        vector<int> tmp;
        bc(res,tmp,c,t,0);
        return res;
    }
    
    void bc( vector<vector<int>>& res, vector<int>& tmp , vector<int>& c ,int t , int index)
    {
        if(t<0)
        {
            return;
        }
        else if(t==0)
        {
            res.push_back(tmp);
        }
        
        for(int i = index ; i<c.size();i++)
        {
            tmp.push_back(c[i]);
            bc(res,tmp,c,t-c[i],i);
            tmp.pop_back();
        }
    }
    
};
