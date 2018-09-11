class Solution {
public:
	int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
		int l = 0, r = nums.size() - 1, mid = r / 2;
		while (l<mid)
		{
			if (nums[mid] > nums[r])
			{
				l = mid;
				mid = (r - l)/2 + l;
			}
			else
			{
				r = mid;
				mid = (r - l)/2 + l;
			}
		}
		if (target >= nums[mid + 1] && target <= nums[nums.size() - 1])
		{
			l = mid+1;
			r = nums.size()-1;
		}
		else if (target >= nums[0] && target <= nums[mid])
		{
			l = 0;
			r = mid;
		}

		mid = r;
		while (l < mid)
		{
			if (nums[mid] > target)
			{
				r = mid;
				mid = (r - l)/2 + l;
			}
			else if (nums[mid]< target)
			{
				l = mid;
				mid = (r - l) /2 + l;
			}
			else
			{
				break;
			}
		}

		if (nums[mid] == target) return mid;
		return -1;
	}
};
