
class Solution {
public:
    int reverse(int x) {
        //正负
        bool overzero = false;
        if(x>0)
        {
           overzero = true;
        }
        else
        {
            x= -x;
        }
    
        //0
        if(x == 0) return x;
        
        std::vector<int> ivec;
        while(x>0)
        {
            ivec.push_back(x%10);
            x= x/10;
        }
        //reverse(ivec.begin(),ivec.end());
        
        
        
        //判断溢出
        bool oversize = false;
        if(ivec.size()== 10)
        {
            int max_int = INT_MAX;
            std::vector<int> tmpvec;
            while(max_int >0)
            {
                tmpvec.push_back(max_int%10);
                max_int = max_int /10;
            }
            //reverse(tmpvec.begin(),tmpvec.end());
            std::vector<int>::iterator it_ivec = ivec.begin();
            std::vector<int>::reverse_iterator rit_tmpvec = tmpvec.rbegin();
            for(;it_ivec!=ivec.end(),rit_tmpvec!=tmpvec.rend();it_ivec++,rit_tmpvec++)
            {
                if(*it_ivec > *rit_tmpvec)
                {
                    oversize = true;
                    break;
                }
                else if (*it_ivec < *rit_tmpvec)
                {
                    break;
                }
            }
        }
        
        if(!oversize)
        {
            int  res = 0;
            std::vector<int>::iterator it = ivec.begin();
            for(;it!=ivec.end();it++)
            {
                res = res*10 + *it;
            }
            if(overzero)
                return res;
            else
                return -res;
        }
        return 0; 
    }
};
