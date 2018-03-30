#include <bits/stdc++.h>
using namespace std;
const int size_of_trie = 'z'-'a'+2;

struct TrieNode;

using TriePtr = TrieNode*;

struct TrieNode{
	TrieNode(char c) : c(c){
		for(int i = 0; i < size_of_trie; i++){
			vals[i] = nullptr;
		}
	}	
	~TrieNode(){
		for(int i = 0; i < size_of_trie; i++){
			delete vals[i];
		}
	}
	TriePtr vals[size_of_trie] = {};
	char c;
};


// Assuming the alphabet is lowercased

class Trie{
public:
	Trie() : root(size_of_trie-1-'a'){

	}

	void insert(string word){
		auto r1 = &root;
		for(auto & c :  word){
			if(r1->vals[c-'a'] == nullptr){
				r1->vals[c-'a'] = new TrieNode(c);
			}
			r1 = r1->vals[c-'a'];
		}		
		if(r1->vals[size_of_trie-1] == nullptr){
			r1->vals[size_of_trie-1] = new TrieNode(size_of_trie-1+'a');
		}
	}

	bool search(string word){
		auto r1 = & root;
		for(auto & c : word){
			if(r1->vals[c-'a'] == nullptr){
				return false;
			}
			r1 = r1->vals[c-'a'];
		}
		return r1->vals[size_of_trie-1] != nullptr;
	}


	bool startsWith(string prefix){
		auto r1 = &root;
		for(auto & c : prefix){
			if(r1->vals[c-'a']==nullptr){
				return false;
			}
			r1 = r1->vals[c-'a'];
		}
		for(int i = 0; i < size_of_trie; i++){
			if(r1->vals[i] != nullptr) return true;
		}
		return false;

	}
private:
	TrieNode root;
};
