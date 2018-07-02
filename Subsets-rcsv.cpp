class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int>sub;
        recursive(nums, 0, sub, subs);
        return subs;
    }
    void recursive(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>> &subs) {
    	subs.push_back(sub);
    	for(int i = 0; i < nums.size(); i++) {
    		sub.push_back(nums[i]);
    		recursive(nums,i + 1, sub, subs);
    		sub.pop_back();
    	}
    	return;
    }
};