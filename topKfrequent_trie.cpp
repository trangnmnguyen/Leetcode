#include <bits/stdc++.h>

using namespace std;

struct trieNode {
	struct trieNode *children[26];
	int countWord;
}

struct trieNode *getWord() {
	struct trieNode *newNode = (struct trieNode*)malloc(sizeof(struct trieNode));
	for(int i = 0; i < 26; i++) {
		newNode->children[i] = NULL;
	}
	newNode->countWord = 0;
	return newNode;
}

void addTree(struct trieNode *newTree, string word) {
	struct trieNode *root = newTree;
	for(int i = 0; i < word.size(); i++) {
		int index = word[i] - 'a';
		if(!root->children[index]) {
			root->children[index] = (struct trieNode*)malloc(sizeof(struct trieNode));
		}
		root = root->children[index];
	}
	root->countWord ++;
	return;
}

void k_frequent(struct trieNode *newTree) {
	struct trieNode *root = newTree;
	for(int i = 0; i < 26; i++) {
		if(root->children[i]) {
			
		}
	}
}

int main () {
	

}