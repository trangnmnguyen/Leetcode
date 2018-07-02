#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
		return a.second > b.second || (a.second == b.second && a.first < b.first); 
	}

	vector<string> topKFrequent(vector<string> &words, int k) {
		unordered_map<string, int> freq;
		for(auto w in words) {
			freq[w]++;
		}
		priority_queue< pair<string,int>, vector<pair<string,int>>, decltype(cmp)> pq(cmp);
		for(auto w : freq) {
			pq.emplace(w.first, w.second);
			if(pq.size() > k) {
				pq.pop();
			}
		}
		vector<string>output;
		while(!pq.empty()) {
			output.push_back(pq.top().first());
			pq.pop();
		}
		return output;
	}

}

auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };