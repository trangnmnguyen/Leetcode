#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int dp[row][col];
        return backtrack(grid, 0, 0, row, col, dp);
    }
    
    int backtrack(vector<vector<int>>& grid, int i, int j, int row, int col, int& dp[][col]) {
        if (i == row-1 && j == col-1) {
            return grid[i][j];
        }
        
        if(dp[i][j] != 0) { return dp[i][j]; }
        
        int rowSum, colSum;
        if (i < row-1) { rowSum = backtrack(grid, i+1, j, row, col, dp); }
        if (j < col-1) { colSum = backtrack(grid, i, j+1, row, col, dp); }
        dp[i][j] = grid[i][j] + min(rowSum, colSum);
        return dp[i][j];
    }
};
