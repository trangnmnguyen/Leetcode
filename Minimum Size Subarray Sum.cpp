class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, start = 0, minlen = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
        	sum += nums[i];
        	while(sum >= s) {
        		minlen = min(minlen, i - start + 1);
        		sum -= nums[start++];
        	}
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};