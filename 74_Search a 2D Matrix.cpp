class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int row = 0;
        for(int i = 0 ;i<matrix.size();i++)
        {
            if(i+1<matrix.size())
            {
                if(matrix[i][0] <= target && matrix[i+1][0]>target)
                {
                    row = i;
                }
            }
        }
        
        if(matrix[matrix.size()-1][0] <= target) row = matrix.size()-1;
        for(int j = 0;j<matrix[0].size();j++)
        {
            if(matrix[row][j] == target) return true;
        }
        return false;
    }
};
