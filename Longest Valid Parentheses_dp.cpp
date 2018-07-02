class Solution {
public:
    int longestValidParentheses(string s) {
    	int maxlen = 0;
    	vector<int> dp(s.size(), 0);
    	for(int i = 1; i < s.size(); i++) {
    		if(s[i] == ')') {
    			if(s[i - 1] == '(') {
    				dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
    			} else {
                    if(i - dp[i - 1] - 1 >= 0) {
                        if(s[i - dp[i - 1] - 1] == '(') {
                            //cout<<i - dp[i - 1] - 1<<endl;
                            dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0);
                        }  
                    }
    			}
    			maxlen = max(maxlen, dp[i]);
    		}
    	}
        // for(int i = 0; i < s.size(); i++)
        //     cout<<dp[i]<<" ";
    	return maxlen;
    }
};