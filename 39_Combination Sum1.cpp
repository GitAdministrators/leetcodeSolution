class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c, int t ,bool first = true) {
        vector<vector<int>> res;
        if(c.empty()) return res;
        set<int> iset;
        set<int> leftset;
        for(int i = 0 ; i< c.size();i++)
        {
            if(first && c[i] == t) res.push_back(vector<int>{c[i]});
            
            iset.insert(c[i]);
            if(iset.find(t - c[i])!= iset.end())
            {
                res.push_back(vector<int>{c[i], t-c[i]});
            }
            
            if(t-c[i] >0 && leftset.find(t - c[i]) == leftset.end())
            {
                leftset.insert(t - c[i]);
                auto  tmpvec =  combinationSum(c,t-c[i],false);
                for(auto m : tmpvec)
                {
                    m.push_back(c[i]);
                    res.push_back(m);
                }
            }
        }
        if(first)
        {
            set<vector<int>> hep;
            for(auto m : res)
            {
                sort(m.begin(),m.end());
                hep.insert(m);
            }
            res.assign(hep.begin(),hep.end());
        }
        return res;
        
    }  
};
