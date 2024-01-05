#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int data){
    struct node* node = malloc(sizeof(struct node));
    node->data = data; 
    node->left = NULL;
    node->right = NULL;
    return node;
}    


int lookup(struct node* node, int target ){
    if(node == NULL)
      return false;
    if(target == node->data)
      return true;
    if(target<node->data)
      return lookup(node->left,target);
    else
      return lookup(node->right,target);
}

struct node* insert(struct node* node, int data){
    if(node == NULL)
      return newNode(data);

    if(data <= node->data)
      node->left = insert(node->left,data);

    else
      node->right = insert(node->right,data);
    return node;
}


void inOrder(struct node* node, int* argc, int* argv){
    if(node == NULL)
      *argc = 0;
    else{
      inOrder(node->left, argc, argv++);
      (*argc)++;
      *argv = node->data;
      inOrder(node->right, argc, argv++);
    }    
}

int size(struct node* node){
  if(node == NULL){
      return 0;
  }
  
  return 1 + size(node->left) + size(node->right);
}

void printTree(struct node* root){
    if(!root)
	printf(" ");
    else{ 
      printTree(root->left);
      printf("%d",root->data);
      printTree(root->right);
    }
}

int main(){
    struct node* arbol=NULL;
    arbol=insert(arbol,10);
    arbol=insert(arbol,5);
    arbol=insert(arbol,2);
    arbol=insert(arbol,1);
    arbol=insert(arbol,3);
    arbol=insert(arbol,12);
    arbol=insert(arbol,11);
    arbol=insert(arbol,13);
    arbol=insert(arbol,14);
    printTree(arbol);
    printf("\n");
    int cant = size(arbol);
    printf("numero de nodos : %d \n",cant);
}
