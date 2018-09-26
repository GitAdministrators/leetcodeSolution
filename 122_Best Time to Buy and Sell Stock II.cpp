class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int maxfee = 0;
        int minindex =0,maxindex =0;
        for(int i =1;i<prices.size();i++)
        {
            if(prices[minindex] > prices[i])
            {
                minindex = i;
            }
            else if(prices[maxindex]<prices[i])
            {
                maxindex = i;
                while(++i<prices.size())
                {
                    if(prices[maxindex] <prices[i])
                    {
                        maxindex = i;
                    }
                    else break;
                }
                i--;
            }
            
            if(minindex<maxindex)
            {
                maxfee += prices[maxindex] - prices[minindex];
                minindex=maxindex;
            }
            else 
            {
                maxindex = minindex;
            }
        }
        return maxfee;
    }
};
