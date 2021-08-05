#include<iostream>
#include<string.h>
using namespace std;
class Trie {
private:
    bool isEnd;
    Trie*next[26];
public:

    /** Initialize your data structure here. */
    Trie() {
        isEnd=false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie*t=this;
        for(char c:word){
            if(t->next[c-'a']==NULL){
                t->next[c-'a']=new Trie();
            }
            t=t->next[c-'a'];
        }
        t->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie*t=this;
        for(char c:word){
            t=t->next[c-'a'];
            if(t==NULL)
            return false;
        }
        return t->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie*t=this;
        for(char c:prefix){
            t=t->next[c-'a'];
            if(t==NULL){
                return false;
            }
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