#include <bits.stdc++.h>

using namespace std;

int trap(vector<int>&height) {
	int maxleft = 0;
	int maxright = 0;
	int left = 0; 
	int right = height.size() - 1;
	int result = 0;
	while(left < right) {
		if(height[left] <= height[right]) {
			if(height[left] >= maxleft) {
				maxleft = height[left];
			} else {
				result += maxleft - height[left];
			}
			left++;
		} else {
			if(height[right] >= maxright) {
				maxright = height[right];
			} else {
				result += maxright - height[right];
			}
			right--;
		}
	}
	return result;
}

int main () {
	int n;
	cin>>n;
	vector<int>height[n];
	for(int i = 0; i < n; i++) {
		cin>>height[i];
	}
	int trap(height);
	return;
}