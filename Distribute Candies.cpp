class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int>type;
        for(int i = 0; i < candies.size(); i++) type[candies[i]] ++;
        int res = max((candies.size() / 2 > type.size() ? type.size() : candies.size() / 2));
    	return res;
    }
};