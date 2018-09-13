class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        for(int i = 0 ; i<height.size(); )
        {
            if(height[i] == 0) 
            {
                i++;
                continue;
            }
            
            int nextindex =  findnexth(i,height);
            
            if(nextindex != -1)
            {
                res +=  min(height[i],height[nextindex])*(nextindex - i -1);
                for(int j = i + 1 ; j<nextindex;j++)
                {
                    res-= height[j];
                }
                i += nextindex-i;
            }
            else
            {
                i+=1;
            }
        }
        return res;
    }
private:
    int findnexth(int index,vector<int>& height)
    {
        int max = 0;
        int maxindex = -1;
        for(int i = index + 1 ; i<height.size();i++)
        {
            if(max <= height[i] ) 
            {
                max = height[i];
                maxindex =i;
            }
            
            if(max >= height[index])
                return i;
        }
        return maxindex;
    }
};
