class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
	if (len == 0)
		return 0;
	int cur = nums[0];
	int curIndex = 1;
	int count = 1;
	for (int i = 1; i< len; i++)
	{
		if (nums[i] != cur)
		{
			nums[curIndex++] = nums[i];
			cur = nums[i];
			count = 1;
		}
		else
		{
			if (count < 2)
			{
				count++;
				nums[curIndex++] = nums[i];
			}
			
		}

	}

	return curIndex;    
    }
};
