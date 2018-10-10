class Solution {
public:
    bool isNumber(string s) {
        //pre
        while(!s.empty() && s.back() == ' ') s.pop_back();
        while(!s.empty() && s.front() == ' ') s.erase(s.begin());
        if(s.empty()) return false;
        
        bool bres       = true;
        bool bneg       = false;
        bool bnegnext   = false;
        bool blog       = false;
        bool bdot       = false;
        bool binnum     = false;

        
        auto it = s.begin();
        while(it!=s.end())
        {
          if(*it == '+' || *it == '-')
          {
              if(bnegnext) return false;
              if(binnum || bneg || bdot) 
              {
                 if(*(it-1) == 'e')
                 {
                     bnegnext = true;
                 }
                 else return false;
              }
              else bneg = true;
          }  
          else if(*it == 'e')
          {
              if(!binnum || blog) 
              {
                  return false;
              }
              else blog = true;
          }
          else if(*it == '.')
          {
              if(bdot || blog)
              {
                  return false;
              }
              else bdot = true;
          }
          else if(*it >='0' && *it<='9')
          {
              binnum = true;
          }
          else
          {
              return false;
          }
          it++;
        }
        
        if(s.back() == '.' && !binnum) bres =false;
        else if(s.back() == '.' && binnum) bres = true;
        else if(!(s.back()>='0' && s.back()<='9')) bres = false;
        return bres;
    }
};
