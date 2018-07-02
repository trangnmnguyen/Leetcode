class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_size = 0; 
        int new_size = 0;
        for(int i = 0; i < height.size(); i++) {
            for(int j = 0; j < height.size(); j++) {
                if(i != j) {
                    new_size = min(height[i], height[j]) * abs(i - j);
                    max_size = max(max_size, new_size);
                }   
            }
        }
        return max_size;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_size = 0; 
        int new_size = 0;
        int i = 0; 
        int j = height.size() - 1;
        while(i < j) {
            new_size = min(height[i], height[j]) * abs(i - j);
            max_size = max(max_size, new_size);
            if(height[i] <= height[j]) {
                i++;   
            } else if(height[i] > height[j]) {
                j--;
            } 
        }
        return max_size;
    }
};