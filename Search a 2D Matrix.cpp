class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
       
    	int row = 0;
        for(int i = 0; i < matrix.size(); i++) {
        	if(matrix[i][0] <= target)
        		row = i;
        	else
        		break;
        }

        for(int i = 0; i < matrix[row].size(); i++) {
        	if(matrix[row][i] == target)
        		return true;
        }
        return false;
    }
};