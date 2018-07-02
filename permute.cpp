#include <bits/stdc++.h>

using namespace std;

void recursive(vector<vector<int>>&result, vector<int>&tmp, vector<int>&nums, int flag[]) {
    if(tmp.size() == nums.size()) {
        result.push_back(tmp);
        return;
    } 

    for(int i = 0; i < nums.size(); i++) {
        if(flag[i] == 0) {
            flag[i] = 1;
            tmp.push_back(nums[i]);
            recursive(result, tmp, nums, flag);
            tmp.pop_back();
            flag[i] = 0;
        }
    }
    return;
} 

vector<vector<int>>permute(vector<int>&nums) {
    vector<vector<int>>result;
    vector<int>tmp;
    int flag[nums.size()];
    for(int i = 0; i < nums.size(); i++) {
        flag[i] = 0;
    }
    recursive(result, tmp, nums, flag);
    return result;
}

int main () {
	int n;
	cin>>n;
	vector<int>nums[n];
	for(int i = 0; i < n; i++) {
		permute(nums);
	}
	return 0;
}