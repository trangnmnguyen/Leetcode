#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void recursive(int m, int n, int i, int j) {
	    if(i < 0 || j < 0)
	        return;

	    if(i >= m && j >= n)
	        return;

	    if(i == m - 1 && j == n - 1) {
	        cnt++;
	        return;
	    }
	    if(i < m)
	        recursive(m, n, i + 1, j);
	    if(j < n)
	        recursive(m, n, i, j + 1);
	    return;
	}

	int uniquePaths(int m, int n) {
	    recursive(m, n, 0, 0);
	    return cnt;
	}
};