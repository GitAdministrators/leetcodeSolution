class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size()-1;
        int max =0;
        while(i!=j)
        {   int tmp =0;
            if(height[i] < height[j])
            { 
                tmp = (j-i)* height[i];
                i++;
            }
            else
            {
                tmp = (j-i)* height[j];
                j--;
            }
            max = max > tmp? max:tmp;
        }
        return max;
    }
};
