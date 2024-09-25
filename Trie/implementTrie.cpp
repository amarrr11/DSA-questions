#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode;

        newNode->isEndOfWord = false;
        for(int i = 0; i < 26; i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    trieNode* root;
    
    Trie() {
        root = getNode();
    }

    void insert(string word) {
        trieNode* crawler = root;

        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            int idx = ch - 'a';
            if(crawler->children[idx] == NULL){
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndOfWord = true;
    }

    bool search(string word) {
        trieNode* crawler = root;

        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            int idx = ch - 'a';
            if(crawler->children[idx] == NULL){
                return false;
            }
            crawler = crawler->children[idx];
        }
        return (crawler != NULL && crawler->isEndOfWord);
    }

    bool startsWith(string prefix) {
        trieNode* crawler = root;

        for(int i = 0; i < prefix.size(); i++){
            char ch = prefix[i];
            int idx = ch - 'a';
            if(crawler->children[idx] == NULL){
                return false;
            }
            crawler = crawler->children[idx];
        }
        return true;
    }
};

int main() {
    Trie* trie = new Trie();

    // Insert words into the trie
    trie->insert("apple");
    trie->insert("app");
    trie->insert("application");

    // Search for words
    cout << trie->search("apple") << endl;       // Output: 1 (true)
    cout << trie->search("app") << endl;         // Output: 1 (true)
    cout << trie->search("appl") << endl;        // Output: 0 (false)

    // Check prefix
    cout << trie->startsWith("app") << endl;     // Output: 1 (true)
    cout << trie->startsWith("apx") << endl;     // Output: 0 (false)

    return 0;
}
