#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        pair<int, int> dp[n][n];
        for(int len = 0; len <= n; ;len++) {
        	for(int j = 0; j < n; j++) {
        		if(i == j) {
        			dp[i][j] = make_pair(nums[i], 0);
        		}
        	}
        }
    }
};