class Solution {
public:
    int mySqrt(int x) {
        long long tmp = x;
        while(true)
        {
            if(tmp* tmp == x) return tmp;
            else if(tmp*tmp>x) tmp/=2;
            else 
            {
                while(tmp*tmp <x)
                {
                    tmp+=1;
                }
                
                return (tmp*tmp == x) ? tmp:tmp-1;
            }
        }
        return 0;
    }
};
