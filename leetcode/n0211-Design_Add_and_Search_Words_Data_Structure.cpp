#include <string>
#include <iostream>
using namespace std;

const int N = 500000;
class WordDictionary {
public:
    int son[N][26] = {0}, cnt[N] = {0}, idx = 0;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        int p = 0;
        for(int i = 0; i < word.size(); i++){
            int u = word[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p] ++;
    }
    
    bool search(string word) {
        return search(word, 0, 0);
    }

    bool search(string word, int wi, int p){
        for(; wi < word.size(); wi++){
            if(word[wi] == '.'){
                int flag = false;
                for(int i = 0; i < 26; i++){
                    if(son[p][i] && search(word, wi + 1, son[p][i])){
                        flag = true;
                    }
                }
                return flag;
            }
            int u = word[wi] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
        }
        return cnt[p] != 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */