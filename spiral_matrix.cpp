#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
int a[100][100];
vector<int>v;

void printround(int i, int j, int l) {
	int k;
	
	for(k = 0; k <= j; k++) 
		v.push_back(a[i][k]);

	for(k = i+1; k <= l; k++)
		v.push_back(a[k][j]);

	for(k = l-1; k >= i; k--)
		v.push_back(a[l][k]);

	for(k = l; k > i; k--)
		v.push_back(a[k][i]);
	return;
}

vector<int> smatrix() {
	int round = ceil(n/2);
	int j, l;
	for(int i = 0; i < ceil; i++) {
		j = n - 1 - j;
		l = m - 1 - i;
		printround(i, j, l);
	}
	return v;
}

int main () {
	cin>>m;
	cin>>n;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			cin>>a[i][j];
	}
	smatrix();
}