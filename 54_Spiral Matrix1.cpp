class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<vector<int> > dirs{{0,1},{1,0},{0,-1},{-1,0}};
        int rowlen = matrix.size();    if(rowlen == 0) return res;
        int collen= matrix[0].size();  if(collen == 0) return res;
        
        vector<int> rec{collen,rowlen-1};
        int idir = 0;
        int ir = 0 , ic = -1;
        while(rec[idir%2])
        {
            for(int i = 0; i< rec[idir%2];i++)
            {   
                ir += dirs[idir][0];
                ic += dirs[idir][1];
                res.push_back(matrix[ir][ic]);
            }
            rec[idir%2]--;
            idir = (idir+1) % 4;
        }
        return res;        
    }
};
