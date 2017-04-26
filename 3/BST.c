#include "BST.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void add_to_tree (char *new_string, Node *root) {
	
	if (strcmp(new_string, root -> str) > 0) {

		if (root -> left != NULL) {
			add_to_tree(new_string, root -> left);
		}
		else {
			Node *new_node = (Node *)malloc(sizeof(Node));
                            if (new_node == NULL) {
                              printf("Can't allocate memory");
				return;                                
}
			new_node -> str = (char*)malloc(sizeof(char) * 50);
                            if (new_node -> str == NULL) {
                               printf("Can't allocate memory");
                                }
			strcpy(new_node -> str, new_string);
			new_node -> left = NULL;
			new_node -> right = NULL;
			root -> left = new_node;
		}
	}
	else {
		if (root -> right != NULL) {
			add_to_tree(new_string, root -> right);
		}
		else {
			Node *new_node = (Node *)malloc(sizeof(Node));
                            if (new_node == NULL) {
                               printf("Can't allocate memory");
                                }
			new_node -> str = (char*)malloc(sizeof(char) * 50);
                            if (new_node -> str == NULL) {
                               printf("Can't allocate memory");
                                }
			strcpy(new_node -> str, new_string);
			new_node -> left = NULL;
			new_node -> right = NULL;
			root -> right = new_node;
		}
	}
}

void print_tree (Node *root, FILE * output_file) {
	if (root -> left != NULL)
		print_tree (root -> left, output_file);
	
	fprintf (output_file, "%s ", root -> str);

	if (root -> right != NULL)
		print_tree (root -> right, output_file);
}

void clear_tree (Node *root) {
	if (root -> left != NULL)
		clear_tree (root -> left);

	if (root -> right != NULL)
		clear_tree (root -> right);

	free (root -> str);
	free (root);
}

Node* set_root (char *tmp_str) {
        Node *root = (Node *)malloc (sizeof(Node));
            if (root == NULL) {
            printf("Can't allocate memory.");
            }
	root -> str = (char*)malloc(sizeof(char) * 50);
            if (root -> str == NULL) {
            printf("Can't allocate memory.");
            }
	strcpy (root -> str, tmp_str);
	root -> left = root -> right = NULL;
        return root;
}



