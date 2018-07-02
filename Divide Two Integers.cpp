class Solution {
public:
    int divide(int dividend, int divisor) {
    	if(dividend == 0 || (divisor == -1 && dividend == INT_MIN)) return 0;

    	int sign = (((dividend > 0) ^ (divisor > 0)) ? -1 : 1);

    	long long dvd = labs(dividend);
    	long long dvs = labs(divisor);
    	int res = 0; 
    	while(dvs < dvd) {
    		long long tmp = dvs, multiple = 1;
    		while((tmp << 1) < dvd) {
    			tmp <<= 1;
    			multiple <<= 1;
    		}
    		dvd -= tmp;
    		res += multiple;
      	return sign == 1 ? res : -res;
    }
};	