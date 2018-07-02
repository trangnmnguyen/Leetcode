class Solution {
public:
	int recursive(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>&dp) {
		int m = (int)obstacleGrid.size();
		int n = (int)obstacleGrid[0].size();
		int h1 = 0, h2 = 0;

		if(i == m - 1 && j == n - 1) {
			if(obstacleGrid[i][j] == 1) {
				dp[i][j] = 0;
				return 0;
			}
			else {
				dp[i][j] = 1;
				return 1;
			}
		}

		if(dp[i][j] != -1)
			return dp[i][j];

		if(obstacleGrid[i][j] == 1) {
			dp[i][j] = 0;
			return 0;
		}

		if(i < m - 1) {
			h1 = recursive(obstacleGrid, i + 1, j, dp);
		}
		if(j < n - 1) {
			h2 = recursive(obstacleGrid, i, j + 1, dp);
		}

		dp[i][j] = h1 + h2;
		return dp[i][j];
	}

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	if(obstacleGrid[0][0] == 1)
			return 0;
        vector<vector<int>>dp((int)obstacleGrid.size(), vector<int>((int)obstacleGrid[0].size()));
        for(int i = 0; i < obstacleGrid.size(); i++) {
        	for(j = 0; j < obstacleGrid[0].size(); j++) {
        		dp[i][j] = -1;
        	}
        }
        return recursive(obstacleGrid, 0, 0, dp);
    }
};