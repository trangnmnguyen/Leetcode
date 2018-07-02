class Solution {
public:
	int recursive(int m, int n, int i, int j, vector<vector<int>>&dp) {
		int h1=0, h2=0;

	    if(i == m - 1 && j == n - 1) {
	        return 1;
	    }

	    if (dp[i][j] != 0) {
	    	return dp[i][j];
	    }

	    if(i < m) 
	    	h1 = recursive(m, n, i + 1, j, dp);
	    if(j < n)
	    	h2 = recursive(m, n, i, j + 1, dp);
	    
	    dp[i][j] = h1 + h2;
	    
	    return dp[i][j];
	}

    int uniquePaths(int m, int n) {
    	vector<vector<int>> dp(m, vector<int>(n));

    	for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j++)
    			dp[i][j] = 0;
    	}

    	int result = recursive(m, n, 0, 0, dp);
    	return result; 	   
    }
};