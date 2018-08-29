class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        bool bpositive = true;
        bool bfirst = true;
        char symbol = ' ';
        char ch_zero = '0';
        int count = 0;
        int res = 0;
        
        for(int i = 0 ; i <n; i++)
        {
            char tmp = str.at(i);
            if(tmp == ' ' && bfirst) continue;
            
            int  pop = -1;
            if(bfirst)
            {
                if(tmp == '+' || tmp == '-')
                {
                    symbol = tmp;
                    bfirst = false;
                    continue;
                }
                else if( tmp >= '0' && tmp<='9')
                {
                    bfirst = false;
                    pop =  (int)tmp - (int)ch_zero; 
                }
                else
                {
                   return 0; 
                } 
            }
            else
            {
                if(tmp >='0' && tmp <='9')
                {
                    pop = (int)tmp - (int)ch_zero;
                }
                else
                {
                    break;
                }
            }
            
            if(res>INT_MAX/10 || (res==INT_MAX/10 && pop >INT_MAX%10)) return INT_MAX;
            if(res<INT_MIN/10 || (res==INT_MIN/10 && -pop <INT_MIN%10)) return INT_MIN;
           
            if(symbol == '-')
            {
                res = res* 10 - pop;
            }
            else
            {
                res = res*10 + pop;
            }
        }
        return res;
    }
};
