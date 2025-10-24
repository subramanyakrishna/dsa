class TrieNode {
public:
    bool isWord;
    TrieNode *mp[26];   
    TrieNode():isWord(false) {
        std::fill(mp,mp+26,nullptr);
    }
};

class Trie {
public:
    TrieNode *root;
    Trie():root(new TrieNode()){}    
    void insert(string word) {
        int idx = 0, size = word.size();
        TrieNode *ptr = root;
        while(idx < size) {
            TrieNode *nn =  ptr->mp[word[idx]-'a'];
            if (nn) ptr = nn;
            else { 
                nn = new TrieNode();
                ptr = ptr->mp[word[idx]-'a'] = nn;
            }
            idx++;
        }
        ptr->isWord = true;
    }

    bool search(string word,bool isPrefix = false) {
        int idx = 0, size = word.size();
        TrieNode *ptr = root;
        while(idx<size) {
            TrieNode *nn =  ptr->mp[word[idx]-'a'];
            if(!nn) return false;
            ptr = nn;
            idx++;
        }
        return ptr->isWord || isPrefix;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */