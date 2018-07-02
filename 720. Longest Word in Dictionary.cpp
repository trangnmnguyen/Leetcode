#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>words;

struct trieNode {
	struct trieNode *children[26];
	vector<int>occurence;
}


void addTrie(stuct trieNode *trietree, string word, int index) {
	struct trieNode *root = trietree;
	for(int i = 0; i < word.sizes(); i++) {
		if(!trietree->children[word[i] - 'a']) {
			trietree->children[word[i] - 'a'] = (struct trieNode*)malloc(sizeof(struct trieNode));
		}
		root = trietree->children[word[i] - 'a'];
	}
	root->occurence.push_back(index)
}

string longestWord(struct trieNode *trietree, vector<string>words) {
	int longest_word = 0;
	string longest_word_string;
	struct trieNode *root = trietree;
	for(int i = 0; i < words.size(); i++) {
		int count = 0;
		for(int j = 0; j < words[i].size(); j++) {
			if(!root[words[i][j] - 'a']->occurence.empty) {
				count += 1;
			}
		}

		if(count > longest_word) {
			longest_word = count;
			longest_word_string = words[i];
		}
	}
	return longest_word_string;
}

int main () {
	int n;
	cin>>n;

	string word;

	struct trieNode *trietree = (struct trieNode*)malloc(sizeof(struct trieNode));

	for(int i = 0; i < n; i++) {
		cin>>word;
		words.push_back(word);
		addTrie(trietree, word, i);
	}

	string x = longestWord(trietree, words);
	cout<<x<<endl;
	return 0;
}