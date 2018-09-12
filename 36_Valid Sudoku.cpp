class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check row
        for(int i =0 ; i<board.size();i++)
        {
            if(!isValidSmall(board[i])) return false;
        }
        //check col
        for(int i =0 ;i<board.size();i++)
        {
            vector<char> tmpvec;
            for(int j=0;j<board.size();j++)
            {
               tmpvec.push_back(board[j][i]);
            }
            if(!isValidSmall(tmpvec)) return false;
        }
        //check 3X3
        for(int jlen =0 ; jlen<9;jlen+=3)
        {
            for(int ilen = 0 ; ilen<9;ilen+=3)
            {
                vector<char> tmpvec;
                for(int i = ilen;i<ilen+3;i++)
                {
                    for(int j = jlen;j<jlen+3;j++)
                    {
                        tmpvec.push_back(board[i][j]);
                    }
                }
                if(!isValidSmall(tmpvec)) return false;
            }
        }
        
        return true;
        
    }
    
    bool isValidSmall(vector<char> & vec)
    {
        map<char,int> tmpmap;
        for(int i = 0 ;i<vec.size();i++)
        {
            tmpmap[vec[i]]++;
            if(vec[i] != '.' && tmpmap[vec[i]]>1) return false;
        }
        return true;
    }
};
