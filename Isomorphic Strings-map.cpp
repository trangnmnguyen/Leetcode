class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != i.size()) return false;
        unordered_map<char, char>mp;
        for(int i = 0; i < s.size(); i++) {
        	auto it = mp.find(s[i]);
        	if(it == mp.end()) mp.insert(make_pair<char, char>(s[i], t[i]));
        	else if(it->second() != t[i]) return false;
        }
        return true;
    }
};