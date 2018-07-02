class Solution {
public:
    int singleNumber(vector<int>& nums) {
     	unordered_map<int, int>rep;
     	for(int i = 0; i < nums.size(); i++) {
     		rep[nums[i]]++;
     	}   
     	for(auto i = rep.begin(); i != rep.end(); i++) {
     		if(i->second == 1) return i->first;
     	}
     	return 0;
    }
};