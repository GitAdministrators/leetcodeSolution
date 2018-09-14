class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0 , r = height.size()-1;
        int res =0;
        while(l<r)
        {
            
            if(height[l]<= height[r])
            {
                int ledge = height[l];
                
                while(ledge > height[l+1])
                { 
                   res+= ledge -height[l+1];
                   l++;
                }
                l++;
            }
            else
            {
               int redge = height[r];
                
               while(redge > height[r-1])
               {
                    res+= redge -height[r-1];
                    r--;
               }
                r--;
            }
        }
        return res;
    }
};
