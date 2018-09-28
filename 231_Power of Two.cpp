class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        int mask = 0x01;
        int cnt  = 0;
        for(int i = 0 ; i < 32 ;i++)
        {
            if((n>>i)&mask) cnt++;
        }
        if(cnt == 1) return true;
        return false;
    }
};
