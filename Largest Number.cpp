class Solution {
public:
	vector<int>mergeSort(vector<int>&nums, int start, int end) {
		int mid = (start + end) / 2;
		vector<int>v1 = mergeSort(nums, start, mid);
		vector<int>v2 = mergeSort(nums, mid + 1, end);
		vector<int>v3 = merge(v1, v2);
		for(int i = start; i <= end; i++) {
			nums[i] = v3[i];
		}
		return v3;
	}

	vector<int>merge(const vector<int>&v1, const vector<int>&v2) {
		int i = 0, j = 0;
		vector<int>v3;
		// while(i < v1.size() && j < v2.size()) {
		// 	if(compare(v1[i], v2[j])) {
		// 		v3.push_back(v1[i]);
		// 		i++;
		// 	} else {
		// 		v3.push_back(v2[j]);
		// 		j++;
		// 	}
		// } 

		// if(v1.size() == i) {
		// 	while(j < v2.size()) {
		// 		v3.push_back(v2[j]);
		// 		j++;
		// 	}
		// } else if(v2.size() == j) {
		// 	while(i < v1.size()) {
		// 		v3.push_back(v1[i]);
		// 		i++;
		// 	}
		// }

		while(i < v1.size() || j < v2.size()) {
			if(j == v2.size() || i < v1.size() && compare(v1[i], v2[j])) {
				v3.push_back(v1[i]);
				i++;
			} else {
				v3.push_back(v2[j]);
				j++;
			}
		}

		return v3;
	}

	bool compare(int x, int y) {
		// if(to_string(x) + to_string(y) > to_string(y) + to_string(x)) {
		// 	return true;
		// } else return false;
		return to_string(x) + to_string(y) > to_string(y) + to_string(x);
	}

    string largestNumber(vector<int>&nums) {
  		mergeSort(nums, 0, nums.size() - 1);
  		string res = "";
  		for(int i = 0; i < nums.size(); i++) {
  			res += to_string(nums[i]);
  		}
  		return res; 
    }
}; 