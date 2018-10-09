class Solution {
public:
    bool debug = true;
	int recursive(vector<int>&prices, int lastBuy, int i, int curProfit, int &maxP) {
		if(debug) {
            cout << "i: " << i << " curProfit: " << curProfit << " maxP: " << maxP << endl;
        }

        if(i >= prices.size()) {
			if(curProfit > maxP) {
				maxP = curProfit;
			}
			return 0;
		}

		if(lastBuy != -1) { //buy
			curProfit = max(recursive(prices, -1, i + 2, curProfit + prices[i] - prices[lastBuy], maxP), //sell
							// recursive(prices, i, i + 1, curProfit - prices[i], maxP)),	//buy
							recursive(prices, lastBuy, i + 1, curProfit, maxP)); //cooldown
		} else { //havent buy yet
			curProfit = max(recursive(prices, i, i + 1, curProfit, maxP),	//buy
							recursive(prices, lastBuy, i + 1, curProfit, maxP)); //cooldown
		}

		return curProfit;
	}

    int maxProfit(vector<int>& prices) {
    	int maxP = 0;
        recursive(prices, -1, 0, 0, maxP);
    	return maxP;
    }
};