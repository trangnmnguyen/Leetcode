class Solution {
public:
	void recursive(vector<vector<int>>&triangle, int i, int j, int curSum, int& minSum) {
		if(i == triangle.size()) {
			if(curSum < minSum) {
				minSum = curSum;
			}
			return;
		}

		curSum += triangle[i][j];
		recursive(triangle, i + 1, j, curSum, minSum);
		recursive(triangle, i + 1, j + 1, curSum, minSum);
		// curSum -= triangle[i][j];
		return;
	}

    int minimumTotal(vector<vector<int>>& triangle) {
    	int minSum = INT_MAX;
        recursive(triangle, 0, 0, 0, minSum);
        return minSum;
    }
};