class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid = (left + right) >> 1;
        int min_num;
        while(left <= right){
        	if(nums[mid] == nums[left]) {

        	} else if(nums[mid] > nums[left]) {
        		min_num = nums[left];
        		left = mid + 1;
        	} else if(nums[mid] < nums[left]) {
        		if(nums[mid] >= nums[right]) {
        			min_num = nums[mid];
        			right = mid - 1;
        		} 
        	}
        }
    }
};