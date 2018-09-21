class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1 || n<1) return 0;
        if(m==1 || n == 1) return 1;
        if(m<n) return uniquePaths(n,m);
        int im = m+n-2;
        int in = n-1;
        long long summ = 1,sumn =1;
        while(in)
        {
            summ*=im;
            sumn*=in;
            im--;in--;
        }
        return summ/sumn;
    }
};
