#ifndef WEEK7_TREE_H


class Trie {
private:
    class NodeTrie
    {
    public:
        NodeTrie* children[26];
        bool isFinal = false;
        bool isEmpty = true;
        bool contains(const char ch) const
        {
            return children[ch - 'a'] != nullptr;
        }
        void addChar(const char ch)
        {
            children[ch - 'a'] = new NodeTrie();
            isEmpty = false;
        }
        bool isEnd() const { return isFinal; }
        NodeTrie() 
        {  
            for (size_t i = 0; i < 26; ++i) { children[i] = nullptr; }
        }
    };
private:
    NodeTrie* root = new NodeTrie;
private:
    void clean();
    void cleanNodeTrie(NodeTrie* node);
public:
    Trie() = default;


    void insert(const char* ch);
    bool search(const char* ch);
    Trie& operator=(const Trie& other) = delete;
    ~Trie();
};

#define WEEK7_TREE_H

#endif //WEEK7_TREE_H
