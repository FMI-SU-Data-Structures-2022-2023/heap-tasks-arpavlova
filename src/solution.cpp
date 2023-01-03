#include "solution.h"

void Trie::insert(const char* word) 
{
    NodeTrie* node = root;
    while (*word)
    {
        if (!node->contains(*word))
        {
            node->addChar(*word);
        }
        node = node->children[*word - 'a'];
        ++word;
    }
    node->isFinal = true;
};

bool Trie::search(const char* word) 
{
    NodeTrie* node = root;
    while (*word)
    {
        if (!node->contains(*word))
        {
            return false;
        }
        node = node->children[*word - 'a'];
        ++word;
    }
    return node->isEnd();
};
void Trie::cleanNodeTrie(NodeTrie* node)
{
    if (node != nullptr)
    {
        if (node->isEmpty)
        {
            // delete the leaf node
            delete(node);
            return;
        }

        for (NodeTrie* child : node->children)
        {
            cleanNodeTrie(child);
        }
    }
}
void Trie::clean()
{
    cleanNodeTrie(root);
}

Trie::~Trie() 
{
    clean();
}

void Trie::NodeTrie::copy(const NodeTrie& other) 
{
    isFinal = other.isFinal;
    isEmpty = other.isEmpty;

    for (int i = 0; i < 26; i++) {
        if (other.children[i] != nullptr) {
            children[i] = new NodeTrie();
            children[i]->copy(*other.children[i]);
        }
    }
}


Trie& Trie::operator=(const Trie& other)
{
    if (this != &other)
    {
        clean();
        root->copy(*(other.root));
    }

    return *this;
}
