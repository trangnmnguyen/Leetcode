class Solution {
public:
	bool canVisit(vector<int>&nums, vector<int>&visited, int i) {
		if(visited[i]) {
			return false;
		}

		if(i - 1 >= 0 && visited[i - 1]) {
			return false;
		}

		if(i + 1 < nums.size() && visited[i + 1]) {
			return false;
		}

		if(i == 0 && visited[nums.size() - 1]) {
			return false;
		}

		if(i == nums.size() - 1 && visited[0]) {
			return false;
		}
		return true;
	}

    void recursive(vector<int>&nums, vector<int>&visited, int i, int curSum, int& maxSum) {
    	if(debug) {
    		cout << "i: " << i << endl;
    	}
    	if(i == nums.size()) {
    		if(curSum > maxSum) {
    			maxSum = curSum;
    			return;
    		}
    	}

    	if(canVisit(nums, visited, i)) {
    		curSum += nums[i];
    		visited[i] = 1;
    		for(int j = 0; j < nums.size(); j++) {
    			recursive(nums, visited, j, curSum, maxSum);
    		}
    		visited[i] = 0;
    	} else {
    		recursive(nums, visited, i + 1, curSum, maxSum);
    	}
    	
    	return;
    }

    int rob(vector<int>& nums) {
        int maxSum = INT_MIN; 
        vector<int>visited(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
        	recursive(nums, visited, i, 0, maxSum);
        }
        
        return maxSum;
    }
};