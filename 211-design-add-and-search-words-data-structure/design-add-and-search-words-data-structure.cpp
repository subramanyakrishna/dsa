class TrieNode {
    
    public:
    bool isWord;
    TrieNode* mp[26];
    TrieNode():isWord(false){
        std::fill(mp,mp+26,nullptr);
    }
};
class WordDictionary {
    TrieNode *root;
    void deleteTrie(TrieNode * root){
        if(!root) return;
        for(int i = 0 ; i < 26;i++){
            deleteTrie(root->mp[i]);
        }
        delete root;
    }
    bool searchHelper(const string &word, int idx , TrieNode *node) {
        if(!node)  return false;
        if(idx == word.size()) return node->isWord;
        if(word[idx] == '.' ) {
            for(int i = 0; i < 26;i++) { 
                if(searchHelper(word,idx+1,node->mp[i])) return true;
            }
        }
        else {
            return searchHelper(word, idx + 1, node->mp[word[idx] - 'a']);
        }
        return false;
    }
public:
    WordDictionary() : root(new TrieNode()){}
    ~WordDictionary() {
        deleteTrie(root);
    }
    void addWord(string word) {
        TrieNode *ptr = root;
        for(char c:word) {
            if(!ptr->mp[c-'a']) ptr->mp[c-'a'] = new TrieNode();
            ptr = ptr->mp[c-'a'];
        }
        ptr->isWord = true;
    }
    
    
    bool search(string word) {
        return searchHelper(word,0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */