#include <iostream>
#include <vector>
#include <string>

using namespace std;

int flag = 0;
char asterisk = '\0';

void isMatch(string s, string p, int i, int j) {
    if(i >= s.size() || j >= p.size())
        return;

    if(flag == 0) {
        if(p[j + 1] == '*') {
            asterisk = p[j];
        }

        if(s[i] == p[j] || p[j] == '.')
            isMatch(s, p, i + 1, j + 1);
        else if (s[i] == asterisk) {
            isMatch(s, p, i + 1, j);
        } else {
            asterisk = '\0';
            if(p[j + 1] == '*') {
                isMatch(s, p, i, j + 2);
            } else if (p[j] == '*') {
                isMatch(s, p, i, j + 1);
            } else {
                flag = 1;
            }
        }
    }
    
    return;
}
    
int main() {
    string s, p;
    cin>>s;
    cin>>p;
    isMatch(s, p, 0, 0);
    cout<<flag<<endl;
    return 0;
}
    
   