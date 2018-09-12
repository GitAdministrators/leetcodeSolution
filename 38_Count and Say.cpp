class Solution {
public:
    string countAndSay(int n) {
        string res="";
        string tmp="";
        for(int i = 1; i<=n;i++)
        {
            if(i == 1) 
            {
                res = "1";
                continue;
            }
            
            int count = 1;

            for(int j =0 ;j<res.size();j++)
            {
                if(j+1<res.size() && res[j] == res[j+1])
                {
                    count++;
                }
                else
                {
                    if(count>1) 
                    {
                        tmp+= std::to_string(count)+ res[j];
                        count = 1;
                    }
                    else
                    {
                        tmp += std::to_string(1) + res[j];
                    }
                }
            }
            res =tmp;
            tmp ="";
        }
        return res;
    }
};
