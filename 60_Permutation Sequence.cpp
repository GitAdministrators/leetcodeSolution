class Solution {
public:
    string getPermutation(int n, int k) {
        string res ="";
        vector<int> fac(n+1,1);
        for(int i = 1 ; i <=n ; i++)
        {
            fac[i] = fac[i-1] * i;
        }
        vector<int> snums;
        for(int i = 1 ; i<= n;i++)
        {
            snums.emplace_back(i);
        }
        
        for(int i = 1; i <= n; i++)
        {
            int index = k/fac[n-i];
            if(k%fac[n-i]!=0) index++;
            res += (snums[index - 1] + '0');
            snums.erase(snums.begin() + index -1);
            k = k - (index - 1 ) * fac[n-i];
        }
        return res;
    }
};
