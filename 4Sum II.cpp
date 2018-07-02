class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
     	unordered_map<int>ABSum;
     	for(int i = 0; i < A.size(); i++) {
     		for(int j = 0; j < B.size(); j++) {
     			++ABSum[A[i] + B[j]];
     		}
     	}
     	int res = 0;
     	for(int i = 0; i < C.size(); C++) {
     		for(int j = 0; j < D.size(); j++) {
     			res += (ABSum[C[i] + D[j]] != 0 : 1 : 0);
     		}
     	}  
     	return res; 
    }
};