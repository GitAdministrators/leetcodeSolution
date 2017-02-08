class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> num_map;
        std::vector<int> num_vec;
        for(size_t i = 0 ; i<nums.size();i++)
        {
            num_map[nums[i]]=i;
        }
        std::map<int,int>::iterator my_itr;
        for(size_t i = 0 ; i<nums.size();i++)
        {
            my_itr = num_map.find(target-nums[i]);
            if(my_itr!=num_map.end() && num_map[target-nums[i]] != i)
            {
                num_vec.push_back(i);
                num_vec.push_back(num_map[target-nums[i]]);
                break;
            }
        }
        return num_vec;
    }
};
