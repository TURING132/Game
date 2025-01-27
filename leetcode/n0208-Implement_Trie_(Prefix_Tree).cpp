#include <iostream>
#include <string>
using namespace std;


class Trie {
public:

    const int N = 3 * 10010;
    int (*son)[26]; 
    int *cnt;        
    int idx;  
    Trie() {
        son = new int[N][26]();  
        cnt = new int[N](); 
        idx = 0;
    }
    
    void insert(string word) {
        int p = 0;
        for(char &c : word){
            int s = c - 'a';
            if(son[p][s] == 0)son[p][s] = ++idx;
            p = son[p][s];
        }
        cnt[p]++;
    }
    
    bool search(string word) {
        int p = 0;
        for(char &c : word){
            int s = c - 'a';
            if(son[p][s] == 0) return false;
            p = son[p][s];
        }
        return cnt[p] > 0;
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        for(char &c : prefix){
            int s = c - 'a';
            if(son[p][s] == 0) return false;
            p = son[p][s];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */