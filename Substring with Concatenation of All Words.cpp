class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	int wordlen = (int)words[0].size();
        int len = (int)words.size() * wordlen;
        string tmp, substring;
        for(int i = 0; i < s.size(); i++) {
        	if(i + len <= s.size() - 1) tmp = s.substr(i, i + len - 1);
        	int ii = 0;
        	while(1) {
        		if(ii >= tmp.size()) break;
        		substring = tmp.substr(ii, ii + wordlen - 1);
        		int find = words.find(substring);
        		if(find == words.end()) break;
        		else ii = ii + wordlen + 1;
        	}
        	if(ii )
        }
    }
};