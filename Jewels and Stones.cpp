class Solution {
public:
    int numJewelsInStones(string J, string S) {
    	unordered_map<char, int>jewel;
    	int res = 0;
    	for(int i = 0; i < J.size(); i++) jewel[J[i]] = 1;
    	for(int i = 0; i < jewel.size(); i++) {
    		if(jewel[S[i]]) res += 1;
    	}
    	return res;
    }
};