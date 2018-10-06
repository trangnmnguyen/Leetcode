class Solution {
public:
	bool debug = true;

	void mergeSort(vector<int>& nums, int start, int end) {
		int mid = (start + end) / 2;
        if(debug) {
            cout << mid << endl;
        }
		mergeSort(nums, start, mid);
		mergeSort(nums, mid + 1, end);
		merge(nums, start, mid, end);
        if(debug) {
            cout << mid << endl;
        }
	}

	void merge(vector<int>& nums, int start, int mid, int end) {
		vector<int> tmp;
		int i = start, j = mid + 1;
		while(i <= mid && j <= end) {
			if(nums[i] < nums[j] || j > end) {
				tmp.push_back(nums[i]);
				i++;
			} else {
				tmp.push_back(nums[j]);
				j++;
			}
			if(debug) {
	        	cout << "Cur array: ";
	        	for(int i = 0; i < tmp.size(); i++) {
	        		cout << tmp[i] << " ";
	        	}
	        	cout << "\n";
	        }
		}
		for(int k = start; k <= end; k++) {
			tmp[k - start] = nums[k];
		}
	}

    void wiggleSort(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        
        if(debug) {
        	cout << "Sorted array: ";
        	for(int i = 0; i < nums.size(); i++) {
        		cout << nums[i] << " ";
        	}
        	cout << "\n";
        }
        vector<int>newNums;
        int med = 0;
        if(nums.size() % 2 == 1) {
        	med = nums.size() / 2;
        	newNums.push_back(nums[med]);
        	for(int i = med - 1; i >= 0; i--) {
        		newNums.push_back(nums[i + med + 1]);
        		newNums.push_back(nums[i]);
        	}
        } else {
        	med = (nums.size() - 1) / 2;
        	for(int i = med; i >= 0; i--) {
        		newNums.push_back(nums[i]);
        		newNums.push_back(nums[i + med + 1]);
        	}
        	// if(debug) {
	        // 	cout << "Cur array: ";
	        // 	for(int i = 0; i < newNums.size(); i++) {
	        // 		cout << newNums[i] << " ";
	        // 	}
	        // 	cout << "\n";
	        // }
        }
        if(debug) {
        	cout << "New array: ";
        	for(int i = 0; i < newNums.size(); i++) {
        		cout << newNums[i] << " ";
        	}
        	cout << "\n";
        }
        for(int i = 0; i < newNums.size(); i++) {
            nums[i] = newNums[i];
        }
    }
};