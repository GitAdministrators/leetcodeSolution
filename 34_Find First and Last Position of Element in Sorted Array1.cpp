class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0)return{ -1,-1 };
		if (target<nums[0] || target>nums[nums.size() - 1])return{ -1,-1 };
		const int l = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
		const int u = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
		if (nums[l] != target) // not found
			return vector<int> { -1, -1 };
		else
			return vector<int> { l, u };
    }
};
