class Solution {
public:
    bool debug = true;
	int recursive(vector<int>&prices, vector<vector<int>>&transaction, int i, int lastBuy) {
        if(i >= prices.size()) {
			return 0;
		}

		if(debug) {
            cout << "i: " << i << " curProfit: " << transaction[i][lastBuy] << endl;
        }

		if(transaction[i][lastBuy] != INT_MIN) {
			return transaction[i][lastBuy];
		}

		int &result = transaction[i][lastBuy];

		if(lastBuy) { 
			result = max(recursive(prices, transaction, i + 2, 0) + prices[i], recursive(prices, transaction, i + 1, lastBuy));
		} else { //havent buy yet
			result = max(recursive(prices, transaction, i + 1, 1) - prices[i], recursive(prices, transaction, i + 1, lastBuy));
		}
		return result;
	}

    int maxProfit(vector<int>& prices) {
    	vector<vector<int>>transaction(prices.size(), vector<int>(2, INT_MIN));
        return recursive(prices, transaction, 0, 0);
    }
};