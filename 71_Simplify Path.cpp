class Solution {
public:
    string simplifyPath(string path) {
       vector<string> vechelp;
       auto it = path.begin();
       while(it!=path.end())
       {
           if(*it == '/')
           {
               if(it+1!=path.end() && *(it+1) == '/')
               {
                   it++;
               }
               string tmp("");
               while((++it)!=path.end() && *it !='/')
               {
                   tmp+=*it;
               }
               if(tmp =="..")
               {
                   if(!vechelp.empty()) vechelp.pop_back();
               }
               else if(tmp ==".")
               {
                   continue;
               }
               else if(!tmp.empty())
               {
                   vechelp.push_back(tmp);
               }
           }
       }
       string res("/");
       auto vit = vechelp.begin();
       while(vit!=vechelp.end())
       {
           res+=*vit + "/";
           vit++;
       }
        
       if(res.size()>1) res.pop_back();
       return res; 
    }
};
