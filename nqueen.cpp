#include <iostream>
#include <cstdlib>

using namespace std;

char board[100][100];
char queen[100];
int n;

int can_place_queen(int i, int j) {
    for(int k = 0; k < n; k++) {
        if(i == k)
            return 0;
        if(j == queen[k])
            return 0;
        if(abs(k - i) == abs(queen[k] - j))
            return 0;
    }
    return 1;
}

void printboard() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j == queen[i])
                cout<<'Q';
            else
                cout<<'.';
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void nqueen(int i) {
    if(i >= n) {
        printboard();
        return;
    }
    
    for(int j = 0; j <= n; j++) {
        if(can_place_queen(i, j)) {
            //neu dat dc queen o cho do va k bi tan cong boi bat cu con hau khac
            queen[i] = j;
            nqueen(i + 1);
        }
    }
    return;
}

int main() {
    cin>>n;
    nqueen(0);
    return 0;
}
