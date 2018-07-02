class Solution {
public:
    string longestPalindrome(string s) {
    	int sizestring = 1;
    	string finalstring = "";
        finalstring += s[0];
    	string newstring = "";
    	string rev_string;
        for(int i = 1; i < s.size(); i++) {
            newstring = "";
            newstring += s[i];
            for(int j = i - 1; j >= 0; j--) {
            	newstring += s[j];
            	rev_string = newstring;
                reverse(rev_string.begin(), rev_string.end());
                if(rev_string == newstring) {
                	if(sizestring < i - j + 1) {
                		finalstring = newstring;
                		sizestring = i - j + 1;
                	}
                }
            }
        }
        return finalstring;    
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        string longest_string = "";
        int longestPalindrome_length = 0;
        
    	for(int i = 0; i < s.size(); i++) {
    		int mid = i;
    		    		
    		while(s[mid] == s[mid + 1] && mid < s.size()) {
    			mid ++;
    		}
            
    		int low = i - 1;
    		int high = mid + 1;
            
    		if(low < 0 || high >= s.size() || s[low] != s[high]) {
    			if(mid - i + 1 > longestPalindrome_length) {
    				longestPalindrome_length = mid - i + 1;
    				longest_string = s.substr(i, longestPalindrome_length);
    			}
    		} else if(s[low] == s[high]) {
				while(low >= 0 && high < s.size()) {
					low--;
					high++;
					if(s[low] != s[high]) break;
				}
				if(longestPalindrome_length < high - low - 1) {
					longestPalindrome_length = high - low - 1;
    				longest_string = s.substr(low + 1, longestPalindrome_length);
				}
    		}
    	}
        return longest_string;    
    }
};