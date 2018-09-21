class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int lrow = 0,rrow = matrix.size()-1 , lcol = 0, rcol = matrix[0].size()-1;
        bool bcol = true,badd = true;
        trace(bcol,badd,matrix, lrow,rrow,lcol,rcol,res);
        return res;
    }
    
    void trace(bool bcol,bool badd,vector<vector<int>>& matrix,int lrow,int rrow,int lcol,int rcol,vector<int>& res)
    {
        if(bcol&& badd)
        {
            for(int i = lcol; i<=rcol;i++)
                res.push_back(matrix[lrow][i]);
            bcol = false;
            badd = true;
            lrow++;
        }
        else if(bcol&& !badd)
        {
            for(int i = rcol;i>=lcol;i--)
                res.push_back(matrix[rrow][i]);
            bcol = false;
            badd = false;
            rrow--;
        }
        else if(!bcol&&badd)
        {
            for(int i=lrow;i<=rrow;i++)
                res.push_back(matrix[i][rcol]);
            badd = false;
            bcol = true;
            rcol--;
        }
        else if(!bcol&& !badd)
        {
            for(int i = rrow;i>= lrow;i--)
                res.push_back(matrix[i][lcol]);
            badd = true;
            bcol = true;
            lcol++;
        }
        if(lrow<=rrow && lcol<= rcol)
            trace(bcol,badd,matrix,lrow,rrow,lcol,rcol,res);
    }
};
