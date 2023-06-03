#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef TRIE_H
#define TRIE_H
#define ALPHABET_SIZE (26)
#define ARRAY_SIZE (a) sizeof(a)/sizeof(a[0])
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')


struct Trie {
    bool isEndOfWord;
    struct Trie *children[ALPHABET_SIZE];
};

struct Trie *getTrie();
void insert(struct Trie *root, const char *key);
bool search(struct Trie *root, const char *key);

#endif