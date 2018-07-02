class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        int start = -1;
        stack<int> left;
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] == '(')
        		left.push(i);
        	else {
        		if(left.empty()) {
        			start = i;
        		} else {
        			int len = 0;
        			left.pop();
        			if(left.empty()) {
        				len = i - start;
        			} else {
        				len = i - left.top();
        			}
        			maxlen = max(maxlen, len);
        		}
        	}
        }
        return maxlen;
    }
};