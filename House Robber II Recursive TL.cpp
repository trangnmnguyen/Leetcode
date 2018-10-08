class Solution {
public:
    bool debug = false;

    int recursive(const vector<int>&nums, int i, int isFirstVisited) {
        if(i >= nums.size()) {
            return 0;
        }
        int result = 0;
        if(i == 0) {
            result = max(result, recursive(nums, i + 1, 0));
            result = max(result, recursive(nums, i + 2, 1) + nums[i]);
        }
        else {
            result = max(result, recursive(nums, i + 1, isFirstVisited));
            if(i != nums.size() - 1 || isFirstVisited == 0) {
                result = max(result, recursive(nums, i + 2, isFirstVisited) + nums[i]);
            }
        }
        return result;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        return recursive(nums, 0, 0);
    }
};