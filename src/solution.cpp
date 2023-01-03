#include "solution.h"

void Trie::insert(const char* word)
{
    Trie* node = this;
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

bool Trie::search(const char* word) const
{
    const Trie* node = this;
    while (*word)
    {
        if (!node || !node->contains(*word))
        {
            return false;
        }
        node = node->children[*word - 'a'];
        ++word;
    }
    return node->isEnd();
};

void Trie::clean() 
{
    for (int i = 0; i < 26; i++) {
        if (children[i] != nullptr) {
            children[i]->clean();
            delete children[i];
            children[i] = nullptr;
        }
    }

    isFinal = false;
}

Trie::~Trie()
{
    clean();
}

void Trie::Trie::copy(const Trie& other)
{
    isFinal = other.isFinal;

    for (int i = 0; i < 26; i++) {
        if (other.children[i] != nullptr) {
            children[i] = new Trie();
            children[i]->copy(*other.children[i]);
        }
    }
}

Trie& Trie::operator=(const Trie& other)
{
    if (this != &other)
    {
        clean();
        copy(other);
    }

    return *this;
}
