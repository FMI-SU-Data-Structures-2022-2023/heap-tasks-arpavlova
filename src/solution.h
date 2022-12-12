#ifndef WEEK7_TREE_H

class Trie {
public:
    void insert(const char*);
    bool search(const char*);
    Trie& operator=(const Trie& other) = delete;
    ~Trie();
};

#define WEEK7_TREE_H

#endif //WEEK7_TREE_H
