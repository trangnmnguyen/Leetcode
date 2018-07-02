class solution {
public:
	int pivot(vector<int>&arr, int start, int end) {
		int p = start, s = start + 1, e = end;
		while(start < end) {
			while(s < end && arr[s] < arr[p]) s++;

			while(e >= start && arr[e] > arr[p]) e--;
			
			if(s < e) swap(a[i], a[j]);
		}
		swap(a[j],a[p]);
		return j;
	}

	int quicksort(vector<int>&arr, int k, int start, int end) {
		if(start < end) {
			int pivot = partition(arr, start, end);
			if(pivot == k - 1) return a[pivot];
			else if(pivot > k - 1) return quicksort(arr, k, pivot + 1, end);
			return quicksort(arr, k, start, pivot);
		}
	}

	int kthSmallest(vector<int>&arr, int k) {
		int n = arr.size();
		return quicksort(arr, k, 0, n);
	}
};