class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        size_t split;
        int cnt;
        vector<string>res;
        unordered_map<string, int>rep
        for(int i = 0; i < cpdomains.size(); i++) {
        	split = cpdomains[i].find(' ');
        	cnt = stoi(cpdomains[i].substr(0, split));
        	cpdomains[i] = cpdomains[i].substr(split + 1);
        	while(cpdomains[i].size()) {
        		rep[cpdomains[i]] += cnt;
        		split = cpdomains[i].find('.');
        		if(split == std::string::npos) break;
        		cpdomains[i] = cpdomains[i].substr(split + 1);
        	}
        }
        for(auto i = rep.begin(); i != rep.end(); i++) {
        	res.push_back(i->first + " " + i->second);
        }
        return res;
    }
};