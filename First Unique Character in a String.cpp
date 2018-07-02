class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int>repeat;
        for(int i = 0; i < s.size(); i++) repeat[s[i]]++;
        for(int i = 0; i < s.size(); i++) {
        	if(repeat[s[i]] == 1) {
        		return i;
        	}
        }
        return -1;
    }
};