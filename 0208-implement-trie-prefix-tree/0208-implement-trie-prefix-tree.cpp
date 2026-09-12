struct Node{
    Node* links[26];
    bool flag;

    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
        flag = false;
    }

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void putchar(char ch, Node* newNode){
        links[ch-'a'] = newNode;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};
class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *ptr = root;
        for(int i=0;i<word.size();i++){
            if(!ptr->containsKey(word[i])){
                ptr->putchar(word[i],new Node());
            }
            ptr = ptr->get(word[i]);
        }
        ptr->setEnd();
    }
    
    bool search(string word) {
        Node* ptr = root;
        for(int i=0;i<word.size();i++){
            if(!ptr->containsKey(word[i])){
                return false;
            }
            ptr = ptr->get(word[i]);
        }
        return ptr->isEnd();

    }
    
    bool startsWith(string prefix) {
        Node* ptr = root;
        for(int i=0;i<prefix.size();i++){
            if(!ptr->containsKey(prefix[i])) return false;
            ptr = ptr -> get(prefix[i]);
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