class Solution {
public:
    bool debug = false;

    int recursive(const vector<int>&nums, int i, int isFirstVisited, map<pair<int, int>, int>& memo) {
        if(i >= nums.size()) {
            return 0;
        }
        if(memo.find(make_pair(i, isFirstVisited)) != memo.end()) {
            return memo[make_pair(i, isFirstVisited)];
        }
        int& result = memo[make_pair(i, isFirstVisited)];
        result = 0;
        if(i == 0) {
            result = max(result, recursive(nums, i + 1, 0, memo));
            result = max(result, recursive(nums, i + 2, 1, memo) + nums[i]);
        }
        else {
            result = max(result, recursive(nums, i + 1, isFirstVisited, memo));
            if(i != nums.size() - 1 || isFirstVisited == 0) {
                result = max(result, recursive(nums, i + 2, isFirstVisited, memo) + nums[i]);
            }
        }
        return result;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<pair<int, int>, int> memo;
        return recursive(nums, 0, 0, memo);
    }
};