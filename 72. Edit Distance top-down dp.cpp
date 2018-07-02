class Solution {
public:
	int cache[1000][1000];
	int recursive(string word1, string word2, int i, int j) {
		int n = word1.size();
		int m = word2.size();

		if(i == n && j < m)
			return m - j;
		if(j == m && i < n)
			return n - i;
		if(i == n && j == m)
			return 0;

		if(cache[i][j] != NULL)
			return cache[i][j];

		if(word1[i] == word2[j])
			cache[i][j] = recursive(word1, word2, i + 1, j + 1);
		else
			cache[i][j] = min(min(recursive(word1, word2, i + 1, j), recursive(word1, word2, i, j + 1)), recursive(word1, word2, i + 1, j + 1)) + 1;

		return cache[i][j];
	}

    int minDistance(string word1, string word2) {
    	int result = recursive(word1, word2, 0, 0);
        return result;
    }
};