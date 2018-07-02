class Solution {
public:
	int m, n;
	int recurs(vector<vector<int>>& grid, int i, int j, int dp[][n]) {
		if(i == m && j == n)
			return 0; 

		if(dp[i][j] != 0)
			return dp[i][j];

		if(recurs(grid, i + 1, j, dp) + grid[i + 1][j] < recurs(grid, i, j + 1, dp) + grid[i][j + 1]) {
			dp[i + 1][j] = recurs(grid, i + 1, j, dp) + grid[i + 1][j];
		} else {
			dp[i][j + 1] = recurs(grid, i, j + 1, dp) + grid[i][j + 1];
		}
		dp[i][j] = min(recurs(grid, i + 1, j, dp) + grid[i + 1][j] , recurs(grid, i, j + 1, dp) + grid[i][j + 1]);
		return dp[i][j];
	}

	int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int dp[m][n];

        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		dp[i][j] = 0;
        	}
        }
  
  		recurs(grid, 0, 0, dp);

        return dp[m - 1][n - 1];
    }
}