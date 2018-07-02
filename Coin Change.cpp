class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	if(amount == 0)
    		return 0;

    	if(coins.size() == 0)
    		return -1;

    	sort(coins.begin(), coins.end());
        int n = coins.size();
        int m = amount + 1;

        int dp[n][m];
        for(int i = 0; i < n; i++) 
        	dp[i][0] = 0;
      
        for(int i = 1; i < m; i++) 
        	dp[0][i] = i >= coins[0] ? checkMinus1(dp[0][i - coins[0]]) + 1 : -1;
        	
        for(int i = 1; i < n; i++) {
        	if(coins[i] == 0) 
                continue;
        	for(int j = 1; j < m; j++) {
                if(j >= coins[i]) {
                    int cur = checkMinus1(dp[i][j - coins[i]]) + 1;
                    int prev = dp[i - 1][j];
                    dp[i][j] = cur==-1 ? prev :
                               prev==-1 ? cur :
                               min(cur,prev);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
        	}
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cout<<dp[i][j]<< " ";
            cout<<"\n";
        }
        
        return dp[n - 1][m - 1];
    }

    int checkMinus1(int x) {
    	return x==-1 ? -2 : x;
    }
};