#include "MyLinkList.h"
#include <stack>
#include <iostream>
#include <unordered_set>
using namespace std;



class Trie {
public:
    struct TrieNode{
        struct TrieNode* children[26];
        bool isEndOfWord;
    };
    
    TrieNode* getNode(){
        TrieNode* node = new TrieNode;
        node->isEndOfWord = false;
        for(int i=0; i < 26; i++){
            node->children[i] = nullptr;
        }
        return node;
    }
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        struct TrieNode* n = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - (int)'a';
            if(n->children[idx] == nullptr){
                n->children[idx] = getNode();
            }
            n = n->children[idx];
        }
        n->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct TrieNode* n = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(n->children[idx] == nullptr){
                return false;
            }
            n = n->children[idx];
        }
        return (n != nullptr && n->isEndOfWord);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct TrieNode* n = root;
        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';
            if(n->children[idx] == nullptr){
                return false;
            }
            n = n->children[idx];
        }
        return (n != nullptr);
    }
};


void swap(vector<int>& nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    
    void permuteHelper(vector<vector<int>>& perms, vector<int>& nums, int start, int end){
        if(start == end){
            perms.push_back(nums);
        }
        else{
            for(int i = start; i <= end; i++){
                swap(nums, start, i);
                permuteHelper(perms, nums, start+1, end);
                swap(nums, start, i);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        permuteHelper(permutations, nums, 0, nums.size()-1);
        return permutations;
    }

int arrayNesting(vector<int>& nums) {
        int maxLength = std::numeric_limits<int>::min();
        int length = 0;
        std::unordered_set<int> visited;
        int idx;
        for(int i = 0; i < nums.size(); i++){
            visited.clear();
            idx = i;
            length = 0;
            while(true){
                if(visited.find(nums[idx]) == visited.end()){
                    visited.insert(nums[idx]);
                    length++;
                    idx = nums[idx];
                }
                else{
                    if(length > maxLength){
                        maxLength = length;
                    }
                    break;
                }
            }
        }
        return maxLength > length ? maxLength : length;
    }


int main()
{
  vector<int> v {5,4,0,3,1,6,2};
  cout << v[0] << endl;
  cout << "len : " << arrayNesting(v) << endl;
  return 0;
  Trie* trie = new Trie();
  cout << "True: " << true << " False " << false << endl;
  trie->insert("apple");
  cout << trie->search("apple")<< endl;   // returns true
  cout << trie->search("app")<< endl;     // returns false
  cout << trie->startsWith("app")<< endl; // returns true
  trie->insert("app");   
  cout << trie->search("app")<< endl;     // returns true
  return 0;
  MyLinkList<int> *myList = new MyLinkList<int>();
  myList->push_back(1);
  myList->push_back(2);
  myList->push_back(2);
  myList->push_back(3);
  myList->push_back(3);
  myList->push_back(4);
  myList->push_back(4);
  myList->push_back(5);
  myList->printList();

  myList->removeUnique_usingDataBuffer();
  myList->removeKthLastRecursive(2);

  for (auto it = myList->begin(); it != myList->end(); ++it)
  {
    cout << *it << endl;
  }

  cout << "Removing second node without access to head\n";
  myList->removeInMiddle();

  for (auto it = myList->begin(); it != myList->end(); ++it)
  {
    cout << *it << endl;
  }

  delete myList;
  myList = new MyLinkList<int>();
  myList->push_back(9);
  myList->push_back(32);
  myList->push_back(2);
  myList->push_front(8);
  myList->push_front(1);
  myList->push_front(7);
  myList->push_back(5);
  cout << "Before partition : ";
  myList->printList();
  myList->partitionAroundNum(5);
  cout << "After  partition : ";
  myList->printList();
  delete myList;

  int a = 2111111111;
  cout << a << endl;

  float b = a;
  cout << "float : " << b << endl;
  a = (int)b;
  cout << a << endl;

  return 1;
}