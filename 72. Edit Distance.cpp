#include <iostream>
#include <string>

using namespace std;

int recursive(string word1, string word2, int i, int j) {
    if(i == word1.size() - 1 && j < word2.size() - 1)
        return word2.size() - j;
    
    if(j == word2.size() - 1 && i < word1.size() - 1)
        return word1.size() - i;
    
    if(j == word2.size() - 1 && i == word1.size() - 1)
        return 0;
    
    if(word1[i] == word2[j])
        return recursive(word1, word2, i + 1, j + 1);
    else
        return min(min(recursive(word1, word2, i, j + 1), recursive(word1, word2, i + 1, j + 1)), recursive(word1, word2, i + 1, j)) + 1;
}

int main () {
    string word1, word2;
    cin>>word1;
    cin>>word2;
    int a = recursive(word1, word2, 0, 0);
    cout<<a;
    return 0;
}
