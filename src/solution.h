#ifndef WEEK7_TREE_H
    class Trie
    {
    public:
        Trie* children[26];
        bool isFinal = false;
        bool contains(const char ch) const
        {
            return children[ch - 'a'] != nullptr;
        }
        void addChar(const char ch)
        {
            children[ch - 'a'] = new Trie();
        }
        bool isEnd() const { return isFinal; }
        void copy(const Trie& other);
        Trie() 
        {  
            for (int i = 0; i < 26; ++i) { children[i] = nullptr; }
        }

        void insert(const char* ch);
        bool search(const char* ch) const;
        Trie& operator=(const Trie& other);
        ~Trie();
    private:
        void clean();
    };


#define WEEK7_TREE_H

#endif //WEEK7_TREE_H
