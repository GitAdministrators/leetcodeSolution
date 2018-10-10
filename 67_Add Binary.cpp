class Solution {
public:
    string addBinary(string a, string b) {
        auto ait = a.rbegin();
        auto bit = b.rbegin();
        string res("");
        bool add =  false;
        while(ait!=a.rend() || bit!=b.rend())
        {
            if(ait==a.rend())
            {
                 if(*bit == '1' && add)
                {
                    res.insert(res.begin(),'0');
                }
                else
                {
                    if(add || *bit =='1') 
                    {
                        res.insert(res.begin(),'1');
                    }
                    else
                    {
                        res.insert(res.begin(),'0');
                    }
                    add = false;
                }
                bit++;
            }
            else if(bit == b.rend())
            {
                if(*ait == '1' && add)
                {
                    res.insert(res.begin(),'0');
                }
                else
                {
                    if(add || *ait =='1') 
                    {
                        res.insert(res.begin(),'1');
                    }
                    else
                    {
                        res.insert(res.begin(),'0');
                    }
                    add = false;
                }
                ait++;
            }
            else
            {
                if(*ait == '1' && *bit == '1')
                {
                    if(add) res.insert(res.begin(),'1');
                    else res.insert(res.begin(),'0');
                    add = true;
                }
                else if(*ait == '1' || *bit == '1')
                {
                    if(add) res.insert(res.begin(),'0');
                    else 
                    {
                        add = false;
                        res.insert(res.begin(),'1');
                    }
                }
                else
                {
                    if(add) res.insert(res.begin(),'1');
                    else res.insert(res.begin(),'0');
                    add = false;
                }
                ++ait;
                ++bit;
            }
        }
        if(add) res.insert(res.begin(),'1');
        return res;
    }
};
