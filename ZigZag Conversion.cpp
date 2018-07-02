#include <iostream>

using namespace std;

string convert(string s, int row) {
    if(s.size() == 0) 
        return "";
    
    if(row == 1)
        return s;
    
    vector<char>a[row];
    int flag = 0;
    int count = 0;

    string newstring = "";
    
    for(int i = 0; i < s.size(); i++) {
        if(count == 0) {
            flag = 0;
        } else if(count == row - 1) {
            flag = 1;
        }

        a[count].push_back(s[i]);

        if(flag == 0)
            count++;
        else if(flag == 1)
            count--;
    }

    
    int index = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            newstring.push_back(a[i][j]);
        }
    }
    return newstring;
}

int main () {
	string s;
	cin>>s;
	int row;
	cin>>row;
	string a = convert(s, row);
	return;
}