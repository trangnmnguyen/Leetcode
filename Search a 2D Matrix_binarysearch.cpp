class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.size() == 0 || matrix[0].size() == 0)
    		return false;

  		int n = matrix.size();
  		int m = matrix[0].size();
  
  		if(target < matrix[0][0] || target > matrix[n - 1][m - 1])
  			return false;
  	
  		int l = 0, r = m * n - 1;
  		while(l != r) {
  			int mid = (l + r)>>1;
  			if(matrix[mid / m][mid % m] < target)
  				l = mid + 1;
  			else
  				r = mid;
  		}
  		return matrix[r / m][r % m] == target;
    }
};