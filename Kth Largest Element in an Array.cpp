class Solution {
public:
	bool debug = false;
	void quickSort(vector<int>& nums, int start, int end, int k) {
		if(start == end) return;
		if(debug) {
			cout << "start: " << start << " End: " << end << " k: " << k << endl;
			cout << "nums: ";
			for(int i = 0; i < nums.size(); i++) {
				cout << nums[i];
			}
			cout << endl;
		}
		
		int pivot = rand() % (end + 1 - start) + start;
		int i = start, j = end;
		int tmp = nums[pivot];
		nums[pivot] = nums[start];
		if(debug) {
			cout << "Pivot: " << pivot << " i: " << i << " j: " << j << " tmp: " << tmp << endl; 
			cout << "New nums: ";
			for(int i = 0; i < nums.size(); i++) {
				cout << nums[i];
			}
			cout << endl;
		}
		while(i < j) {
			while(i < j) {
				if(nums[j] < tmp) {
					swap(nums[j], nums[i]);
					i++;
					break;
				} else j--;
			} 
			if(debug) {
				//cout << "start: " << start << " End: " << end << " k: " << k << endl;
				cout << "i: " << i << " j: " << j << endl;
				cout << "New nums: ";
				for(int i = 0; i < nums.size(); i++) {
					cout << nums[i];
				}
				cout << endl;
			}

			while(i < j) {
				if(nums[i] > tmp) {
					swap(nums[j], nums[i]);
					j--;
					break;
				} else i++;
			}
			if(debug) {
				//cout << "start: " << start << " End: " << end << " k: " << k << endl;
				cout << "i: " << i << " j: " << j << endl;
				cout << "New nums: ";
				for(int i = 0; i < nums.size(); i++) {
					cout << nums[i];
				}
				cout << endl;
			}
		}
		nums[i] = tmp;
		if(debug) {
			//cout << "start: " << start << " End: " << end << " k: " << k << endl;
			cout << "New nums: ";
			for(int i = 0; i < nums.size(); i++) {
				cout << nums[i];
			}
			cout << endl;
		}
		if(i < (nums.size() - k)) {
			quickSort(nums, i + 1, end, k);
		} else if(i > (nums.size() - k)) {
			quickSort(nums, start, i - 1, k);
		} else {
			return;
		}
	}

    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size() - 1, k);
        return nums[nums.size() - k];
    }
};