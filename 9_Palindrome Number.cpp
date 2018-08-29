class Solution {
public:
    bool isPalindrome(int x) {
      if(x < 0)  return false;
      int res = 0;
      int len = log10(x)+1;
      
      for(int i = 0 ; i<len/2;i++)
      {
          res = res*10 + x%10;
          x/=10;
      }  
      
      if(len%2 == 1) x/=10;
        
      if(res == x)
          return true;
      else
          return false;
        
        
    }
};
