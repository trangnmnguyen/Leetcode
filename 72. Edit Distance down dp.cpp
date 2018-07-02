class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();

		int cache[n][m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++)
				cache[i][j] = 0;
		}

		for(int i = 1; i <= n; i++)
			cache[i][0] = i;

		for(int j = 1; j <= m; j++)
			cache[0][j] = j;

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if()
			}
		}
	}

};