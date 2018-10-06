class Solution {
public:
	bool debug = false;
	int recursive(vector<vector<int>>&triangle, vector<vector<int>>&costToEnd ,int i, int j) {
		if(debug) {
			cout << "i: " << i << " j: " << j << endl;
		}
		if(i == triangle.size() || j == triangle[i].size()) {
			return 0;
		}
		if(debug) {
			cout << 1 << endl;
		}

		if(costToEnd[i][j] != -1) {
			return costToEnd[i][j];
		}
		if(debug) {
			cout << 2 << endl;
		}

		costToEnd[i][j] = triangle[i][j] + min(recursive(triangle, costToEnd, i + 1, j), recursive(triangle, costToEnd, i + 1, j + 1));
		return costToEnd[i][j];
	}

    int minimumTotal(vector<vector<int>>& triangle) {
    	vector<vector<int>>costToEnd;
    	for(int i = 0; i < triangle.size(); i++) {
    		costToEnd.push_back(vector<int>(triangle[i].size(), -1));
    	}

    	if(debug) {
    		for(int i = 0; i < costToEnd.size(); i++) {
    			for(int j = 0; j < costToEnd[i].size(); j++) {
    				cout << costToEnd[i][j] << " ";
    			}
    			cout << endl;
	    	}
    	}
        int minSum = recursive(triangle, costToEnd, 0, 0);
        return minSum;
    }
};