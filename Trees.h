#pragma once
#ifndef Tree
#define Tree
#define Char_size 256
#include <fstream>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <stack>
#include <Windows.h>
using namespace std;

struct Node {
	unsigned char character;
	long long int Freq;
	Node* left;
	Node* right;
	Node(unsigned char c, long long int f, Node* l = NULL, Node* r = NULL) {
		character = c;
		Freq = f;
		left = l;
		right = r;
	}
	Node(char c, Node* l = NULL, Node* r = NULL) {
		character = c;
		left = l;
		right = r;
	}
};
void Mindownheap(vector<Node*>& A, int i, int length) {
	int least = i;
	if (2 * i + 1 <= length && A[2 * i + 1]->Freq < A[i]->Freq) {
		least = 2 * i + 1;
		if (2 * i + 2 <= length && A[2 * i + 2]->Freq < A[2 * i + 1]->Freq) {
			least = 2 * i + 2;
		}
	}
	else if (2 * i + 2 <= length && A[2 * i + 2]->Freq < A[i]->Freq) {
		least = 2 * i + 2;
	}
	if (least != i) {
		swap(A[i], A[least]);
		Mindownheap(A, least, length);
	}
}
Node* Extract_min(vector<Node*>& A) {
	if (A.size() < 1) {
		return NULL;
	}
	Node* minimum = A[0];
	A[0] = A.back();
	A.pop_back();
	Mindownheap(A, 0, A.size() - 1);
	return minimum;
}
void Insert_MinHeap(vector<Node*>& A, Node* element) {
	A.push_back(element);
	int i = A.size() - 1;
	while (i > 0 && A[(i - 1) / 2]->Freq > A[i]->Freq) {
		swap(A[i], A[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}
void Build_Minheap(vector<Node*>& A, int length) {
	for (int i = (length - 1) / 2; i >= 0; i--) {
		Mindownheap(A, i, length);
	}
}
void store_codes(Node* Root, char single_code[], int index, vector<long long int>& Huffman_codemap) {
	if (Root->left) {
		single_code[index] = '0';
		store_codes(Root->left, single_code, index + 1, Huffman_codemap);
	}
	if (Root->right) {
		single_code[index] = '1';
		store_codes(Root->right, single_code, index + 1, Huffman_codemap);
	}
	if (!Root->left && !Root->right) {
		for (int i = index; i >= 0; i--) {
			if (i != index) {
				Huffman_codemap[Root->character] *= 10;
				Huffman_codemap[Root->character] += single_code[i] - '0';
			}
			else {
				Huffman_codemap[Root->character] = 1;
			}
		}
	}
}
void store_tree(ofstream& input, Node* Root) {
	if (!Root->left && !Root->right) {
		input << '1';
		input << Root->character;
	}
	else {
		input << '0';
		store_tree(input, Root->left);
		store_tree(input, Root->right);
	}
}
Node* Huffman(long long int Count[]) {
	vector<Node*>minheap;
	for (int i = 0; i < Char_size; i++) {
		if (Count[i] != 0) {
			minheap.push_back(new Node(i, Count[i]));
		}
	}
	Build_Minheap(minheap, minheap.size() - 1);
	while (minheap.size() != 1) {
		Node* Z = new Node(-1, 0, Extract_min(minheap), Extract_min(minheap));
		Z->Freq = Z->left->Freq + Z->right->Freq;
		Insert_MinHeap(minheap, Z);
	}
	return(minheap[0]);
}
void Write_compressed(ifstream& input, ofstream& output, vector<long long int >& Huffman_codemap) {
	char ch;
	unsigned char bits_8 = 0;
	long long int counter = 0;
	while (input.get(ch)) {
		long long int temp = Huffman_codemap[static_cast<unsigned char>(ch)];
		while (temp != 1) {
			bits_8 <<= 1;
			if ((temp % 10) != 0) {
				bits_8 |= 1;
			}
			temp /= 10;
			counter++;
			if (counter == 8) {
				output << bits_8;
				counter = bits_8 = 0;
			}
		}
	}
	while (counter != 8) {
		bits_8 <<= 1;
		counter++;
	}
	output << bits_8;
	output.close();
}

Node* Make_Huffman_tree(ifstream& input) {
	char ch;
	input.get(ch);
	if (ch == '1') {
		input.get(ch);
		return (new Node(ch));
	}
	else {
		Node* left = Make_Huffman_tree(input);
		Node* right = Make_Huffman_tree(input);
		return(new Node(-1, left, right));
	}
}
void decode(ifstream& input, string filename, Node* Root, long long int Total_Freq) {
	ofstream output(filename.c_str(), ios::binary);
	if (!output.good()) {
		perror("Error:\t");
		exit(-1);
	}
	bool eof_flag = false;
	char bits_8;
	Node* pointer = Root;
	while (input.get(bits_8)) {
		int counter = 7;
		while (counter >= 0) {
			if (!pointer->left && !pointer->right) {
				output << pointer->character;
				Total_Freq--;
				if (!Total_Freq) {
					eof_flag = true;
					break;
				}
				pointer = Root;
				continue;
			}
			if ((bits_8 & (1 << counter))) {
				if (pointer->right) {
					pointer = pointer->right;
					counter--;
				}
			}
			else {
				if (pointer->left) {
					pointer = pointer->left;
					counter--;
				}
			}
		}
		if (eof_flag) {
			break;
		}
	}
	output.close();
}







class TrieNode {
public:
	bool eow;
	TrieNode* child[26];
	TrieNode()
	{
		eow = false;
		for (int i = 0; i < 26; i++)
			child[i] = NULL;
	}
	~TrieNode() {
		for (int i = 0; i < 26; i++) {
			delete child[i];
			child[i] = 0;
		}
	}
};

class Trie {
	TrieNode* root;

	void parseTree(TrieNode* current, char* s, vector<string>& res, bool& loop) {
		char k[100] = { 0 };
		char aa[2] = { 0 };
		if (loop) {
			if (current != NULL) {
				if (current->eow == true) {
					res.push_back(s);
					if (res.size() > 10000) {
						loop = false;
					}
				}
				TrieNode* child1[26] = { 0 };
				for (int i = 0; i < 26; i++) {
					child1[i] = current->child[i];
				}
				for (int jj = 0; jj < 26 && loop; jj++) {
					strcpy_s(k, s);
					aa[0] = jj + 'a';
					aa[1] = '\0';
					strcat_s(k, aa);
					if (loop) {
						parseTree(child1[jj], k, res, loop);
					}
				}
			}
		}
	}
	void deleteAllNodes(TrieNode*& ptr) {
		if (ptr != NULL) {
			deleteAllNodes(ptr->child[0]);
			deleteAllNodes(ptr->child[1]);
			deleteAllNodes(ptr->child[2]);
			deleteAllNodes(ptr->child[3]);
			deleteAllNodes(ptr->child[4]);
			deleteAllNodes(ptr->child[5]);
			deleteAllNodes(ptr->child[6]);
			deleteAllNodes(ptr->child[7]);
			deleteAllNodes(ptr->child[8]);
			deleteAllNodes(ptr->child[9]);
			deleteAllNodes(ptr->child[10]);
			deleteAllNodes(ptr->child[11]);
			deleteAllNodes(ptr->child[12]);
			deleteAllNodes(ptr->child[13]);
			deleteAllNodes(ptr->child[14]);
			deleteAllNodes(ptr->child[15]);
			deleteAllNodes(ptr->child[16]);
			deleteAllNodes(ptr->child[17]);
			deleteAllNodes(ptr->child[18]);
			deleteAllNodes(ptr->child[19]);
			deleteAllNodes(ptr->child[20]);
			deleteAllNodes(ptr->child[21]);
			deleteAllNodes(ptr->child[22]);
			deleteAllNodes(ptr->child[23]);
			deleteAllNodes(ptr->child[24]);
			deleteAllNodes(ptr->child[25]);
			delete ptr;
			ptr = 0;
		}
	}
public:
	Trie() {
		root = new TrieNode();
	}
	~Trie() {
		deleteAllNodes(root);
	}
	void insert(string str) {
		TrieNode* node = root;
		if (search(str) == true) {
			return;
		}
		int n = 0;
		for (int i = 0; i < str.length(); i++) {
			char c = str[i];
			n = c - 'a';
			if (node->child[n] == NULL) {
				node->child[n] = new TrieNode();
			}
			node = node->child[n];
		}
		node->eow = true;
	}

	bool search(string str) {
		int n = 0;
		TrieNode* node = root;
		for (int i = 0; i < str.length(); i++) {
			char c = str[i];
			n = c - 'a';
			if (node->child[n] == NULL) {
				return false;
			}
			node = node->child[n];
		}
		return node->eow;
	}

	bool startsWith(string str) {
		TrieNode* node = root;
		int n = 0;
		for (int i = 0; i < str.length(); i++) {
			char c = str[i];
			n = c - 'a';
			if (node->child[n] == NULL) {
				return false;
			}
			node = node->child[n];
		}
		return true;
	}

	void ReadTree(string word, vector<string>& res) {
		char* s = new char[100];
		char tem = 0;
		TrieNode* cur = 0;
		bool flag = 1;
		readFile();
		for (int i = 0; i < 100; i++) {
			s[i] = NULL;
		}
		for (int i = 0; i < word.length(); i++) {
			s[i] = word[i];
		}
		cur = root;
		for (int i = 0; i < word.length(); i++) {
			tem = word[i];
			if (cur->child[tem - 'a']) {
				cur = cur->child[tem - 'a'];
			}
			else {
				break;
			}
		}
		parseTree(cur, s, res, flag);
	}

	void readFile() {
		ifstream file;
		file.open("dictionary.txt", ios::app);
		if (!file.is_open()) {
			cout << "file not open\a\n";
			return;
		}
		string word;
		while (file >> word) {
			insert(word);
		}
		file.close();
	}
};
Trie dictionary;
vector<string>words(0);
int wordsIndex = 0;
string selectedWord = "";
#endif // !Tree