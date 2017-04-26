#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BST.h"

#pragma stack_check(off)

void secret()
{
	printf("Seceret\n");
}

int main (int argc, char* argv[]) {
       printf("Secret address %p\n",secret);
       
      /* if (argc != 3) {
          printf("Incorrect number of arguments");
          exit(EXIT_FAILURE);
       } */
        char tmp_str[2]={};
        strcpy(tmp_str, argv[1]);
	FILE * input_file = fopen (tmp_str, "r+t");
          if (input_file == NULL) {
              perror("Can't open file");
              exit(EXIT_FAILURE);
          }

	//char tmp_str[50] = {};
	fscanf (input_file, "%s", tmp_str);
	set_root(tmp_str);
        Node *root = set_root(tmp_str);
	while (fscanf (input_file, "%s", tmp_str) != EOF) {
	       add_to_tree (tmp_str, root);
	}
        fclose(input_file);

	FILE * output_file = fopen (argv[2], "w+t");
           if (input_file == NULL) {
               perror("Can't open file");
               exit(EXIT_FAILURE);
           }
	print_tree(root, output_file);
	clear_tree (root);
        fclose(output_file);
   
       
	return 0;
}
