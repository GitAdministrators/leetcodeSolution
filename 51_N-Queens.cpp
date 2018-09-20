class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if(n<1) return res;
        vector<string> tmp(n,string(n,'.'));
        vector<int> record(5*n - 2,1);
        dfs(0,tmp,record,res,n);
        return res;
     }
    
    void dfs(int i , vector<string> & tmp, vector<int>& record, vector<vector<string> >& res ,int n )
    {
        if(i == n)
        {
            res.push_back(tmp);
            return;
        }
        
        for(int j = 0 ; j<n;j++)
        {
            if(record[j]==1 && record[n+i+j] == 1 && record[4*n-2+i-j] == 1)
            {
                record[j]= record[n+i+j] = record[4*n-2+i-j] = 0;
                tmp[i][j] = 'Q';
                dfs(i+1,tmp,record,res,n);
                tmp[i][j] = '.';
                record[j]= record[n+i+j] = record[4*n-2+i-j] = 1;
            }
        }
    }
};
