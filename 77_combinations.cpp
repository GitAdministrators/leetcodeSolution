class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n<k) return res;
        vector<int> tmp;
        helpcombine(res,tmp,n,k,0,0);
        return res;
    }
    
    void helpcombine(vector<vector<int>> & res,vector<int>& tmp,int n, int k,int start ,int cnt)
    {
       if(cnt>= k)
       {
           res.push_back(tmp);
           return;
       } 
        
        
       for(int i = start + 1;i<=n;i++)
       {
           tmp.push_back(i);
           helpcombine(res,tmp,n,k,i,++cnt);
           tmp.pop_back();
           --cnt;
       }
        
    }
    
    
};
