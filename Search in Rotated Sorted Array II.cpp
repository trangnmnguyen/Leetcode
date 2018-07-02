class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = (l + r) >> 1;
        while(l < r) {
        	if(nums[mid] == target)
        		return true;
        	if(nums[mid] > target) {
        		if(nums[mid] > nums[l]) {
        			r = mid - 1;
                    cout<<1;
        		} else if(nums[mid] <= nums[l]){
        			l = mid + 1;
                    cout<<2;
        		}
        	} else if(nums[mid] < target) {
        		if(nums[mid] > nums[l]) {
        			l = mid + 1;
                    cout<<3;
        		} else if(nums[mid] <= nums[l]) {
        			r = mid - 1;
                    cout<<4;
        		}
        	}
            //cout<<l<<" ";
        }
        return false;
    }
};