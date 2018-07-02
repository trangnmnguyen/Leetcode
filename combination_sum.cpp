#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> combinationSum(vector<int>&candidates, int target) {
    vector<vector<int>>result;
    vector<int>tmp;
    recursive(result, tmp, candidates, target, 0);
    return result;
}

void recursive(vector<vector<int>> &result, vector<int> &tmp, vector<int> &candidates, int target, int start) {
    int newtarget = target;
    if(target < 0) {
        return; 
    } 
    if(target == 0) {
        result.push_back(vector<int>(tmp));
    }

    for(int i = start; i < candidates.size(); i++) {
        tmp.push_back(candidates[i]);
        recursive(result, tmp, candidates, target-candidates[i], i);
        tmp.pop_back();
    }
    return;
}

int main() {
	int n;
	cin>>n;
	vector<int>candidates[n];
	for(int i = 0; i < n; i++) {
		cin>>candidates[i];
	}
	int target;
	cin>>target;
	combinationSum(candidates, target);
	return;
}