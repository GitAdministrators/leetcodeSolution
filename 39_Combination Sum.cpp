class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& c, int target) {
		set<vector<int>>  res;
		vector<vector<int>> ans;
		if (c.empty()) return ans;
        sort(c.begin(),c.end());
		set<int> iset;
		for (int i = 0; i<c.size(); i++)
		{
			if (c[i]>target) break;
			if (c[i] == target)
			{
				res.insert(vector<int>{c[i]});
				break;
			}

			if (iset.find(target - c[i]) != iset.end())
			{
				res.insert(vector<int>{min(c[i], target - c[i]), max(c[i], target - c[i])});
			}
			else
			{
				iset.insert(c[i]);
			}
			vector<vector<int>> tmpvec = combinationSum(c, target - c[i]);
			if (!tmpvec.empty())
			{
				for (auto m : tmpvec)
				{
					m.push_back(c[i]);
					sort(m.begin(), m.end());
					res.insert(m);
				}
			}
		}
		ans.assign(res.begin(), res.end());
		return ans;
	}
};
