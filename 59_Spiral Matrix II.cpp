class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return vector<vector<int> >();
        vector<vector<int> > dir{{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int> > res {n,vector<int>(n,0)};
        int idir = 0, ir = 0 , ic = -1,count=0;
        vector<int> rec{n,n-1};
        while(rec[idir%2])
        {
            for(int i = 0 ; i<rec[idir%2];i++)
            {
                ic += dir[idir][1];
                ir += dir[idir][0];
                count++;
                res[ir][ic] = count;
            }
            rec[idir%2]--;
            idir = (idir+1)%4;
        }
        return res;
    }
};
