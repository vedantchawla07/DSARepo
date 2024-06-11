class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int counterValue = target - nums[i];
            if (map.find(counterValue) != map.end()) {
                return {i, map[counterValue]};
            }
            map[nums[i]] = i;

        }
        return {};
    }
};