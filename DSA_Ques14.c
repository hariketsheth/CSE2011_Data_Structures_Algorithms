4#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char data [30];
  struct node *left, *right;
};

struct node *newNode(char value[30]) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  strcpy(temp->data, value);
  temp->left = temp->right = NULL;
  return temp;
}

void increase(struct node *bst_root) {
  if (bst_root != NULL) {
    increase(bst_root->left);
    printf("%s -> ", bst_root->data);
    increase(bst_root->right);
  }
}

void binary_Search (struct node *bst_root, char search [20]){
    if(strcmp(bst_root -> data, search) == 0)
        printf("Element Found: %p\n",bst_root);
    else{
    if(strcmp(bst_root -> data, search) > 0 && bst_root -> left != NULL)
        binary_Search (bst_root -> left, search);
    else if(strcmp(bst_root -> data, search) < 0 && bst_root -> right != NULL)
        binary_Search (bst_root -> right, search);
    else
        printf("Element not Found\n");
    }
}

struct node *insert(struct node *node, char key [30]) {
  if (node == NULL) return newNode(key);

  if (strcmp(key,node->data)<0)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}


int main() {
    int i;
  struct node *bst_root = NULL;
  char elements[7][20] = {"INDIGO", "GREEN", "CYAN", "YELLOW", "RED", "ORANGE", "VIOLET"};
  for(i=0; i<7; i++){
      bst_root = insert(bst_root, elements[i]);
  }
  printf("Increasing Order ");
  increase(bst_root);
  char search [20];
  printf("\n\nEnter the element to be searched (in Binary Tree): ");
  scanf("%s",search);
  binary_Search(bst_root,search);

}
