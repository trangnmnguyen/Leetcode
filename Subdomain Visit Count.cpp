class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string>res;
        if(!cpdomains.size()) return res;
        size_t split;
        unordered_map<string, int> sub_domains;
       
        for(int i = 0; i < cpdomains.size(); i++) {
        	split = cpdomains[i].find(' ');
        	cnt = stoi(cpdomains[i].substr(0, split));

        	cpdomains[i] = cpdomains[i].substr(split + 1);

        	while(cpdomains[i].size()) {
        		sub_domains[cpdomains[i]] += cnt; 
        		split = cpdomains[i].find('.');

        		if(split == std::string::npos) break;

        		cpdomains[i] = cpdomains[i].substr(split + 1);
        	}
        }
        for(auto it = sub_domains.begin(); it != sub_domains.end(); it++) {
        	res.push_back(to_string(it->second) + " " + it->first);
        }
        return res;
    }
};