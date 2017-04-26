#ifndef _BST_H_
#define _BST_H_

#include <stdio.h>

typedef struct Node {
	char *str;
	struct Node *left, *right;
} Node;

void add_to_tree (char *new_string, Node *root);
void print_tree (Node *root, FILE * output_file);
void clear_tree (Node *root);
Node* set_root (char *tmp_str);

#endif //_BST_H_






