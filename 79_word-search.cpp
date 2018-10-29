class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        if(word.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        for(int i =0 ;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dfs(board,m,n,word,i,j,0)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board , int m ,int n , string& word,int i,int j,int curcount)
    {
        if(curcount == word.size()) return true;
        if(i>=m|| j>=n || i<0 || j<0) return false;
      
        bool res = false;
        if(board[i][j] == word[curcount])
        {
            char tmp = board[i][j];
            board[i][j] ='#';
            res =  dfs(board,m,n,word,i+1,j,curcount+1) 
                || dfs(board,m,n,word,i-1,j,curcount+1)
                || dfs(board,m,n,word,i,j+1,curcount+1) 
                || dfs(board,m,n,word,i,j-1,curcount+1);
            board[i][j] = tmp;
        }
        return res;
    }
    
};
