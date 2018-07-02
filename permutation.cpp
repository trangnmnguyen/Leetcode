#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int visited[100];
    void findUnique(vector<int>nums, vector<vector<int>>&Unique, vector<int>&temp, int n, int visited[]) {
        if(temp.size() == n) {
            Unique.push_back(temp);
            return;  
        }
            
        for(int i = 0; i < n; i++) {
            if(i != 0) {
                if(visited[i - 1]  == 0 && nums[i] == nums[i - 1])
                    continue;
            }
            
            if(visited[i] == 0) {
                visited[i] = 1;
                temp.push_back(nums[i]);
                findUnique(nums, Unique, temp, n, visited);
                visited[i] = 0;
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>>Unique;
        
        for(int i = 0; i < n; i++) 
            visited[i] = 0;
        
        sort(nums.begin(), nums.begin() + nums.size());
        findUnique(nums, Unique, temp, n, visited);
        
        return Unique;
    }
};

int main() {
	Solution a = new Solution();
	vector<int>nums = {1, 1, 2};
	vector<vector<int>>b = a.permuteUnique(nums);
	return 0;
}