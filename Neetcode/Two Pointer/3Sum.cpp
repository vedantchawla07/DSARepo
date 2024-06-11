class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        int a = 0, c = n - 1;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        while (a < n - 2 && nums[a] <= 0) {

            int b = a + 1;
            int c = n - 1;
            while (b < c) {
                while (b < c && -nums[a] == nums[b] + nums[c]) {
                    //cout << nums[a] << " " << nums[b] << " " << nums[c] << endl;
                    ans.push_back({nums[a], nums[b], nums[c]});
                    while (b < c && nums[b] ==  nums[b + 1]) b++;
                    while (b < c && nums[c] == nums[c - 1]) c--;
                    b++;
                    c--;
                }
                while (b < c && -nums[a] < nums[b] + nums[c]) {
                    c--;
                }
                while (b < c && -nums[a] > nums[b] + nums[c]) {
                    b++;
                }
            }
            while (a < n - 2 && nums[a] == nums[a + 1]) a++;
            a++;
            //cout << a << endl;
        }
        return ans;
    }
};