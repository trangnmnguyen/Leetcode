#include <bits/stdc++.h>

using namespace std;

bool binarySearch(vector<int>arr, int target, int l, int h) {
	int mid = l + (r - h) / 2;
	if(arr[mid] == target) return true;
	if(arr[mid] > target) return binarySearch(arr, target, l, mid - 1);
	else return binarySearch(arr, target, mid + 1, h);
	return false;
}

bool findPos(vector<int>arr, int target) {
	int val = arr[0], l = 0, h = 1;
	while(val < target) {
		l = h;
		h *= 2;
		val = arr[h];
	}
	return binarySearch(arr, target, l, h);
}

int main () {

}