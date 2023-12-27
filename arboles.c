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
      node->right = insert(node->left,data);
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
int main(){
    struct node* arbol;
    insert(arbol,5);
    insert(arbol,3);
    insert(arbol,9);
    int argc=0;
    char arreglo[3];
    int* a = &arreglo[0];
    inOrder(arbol,&argc,a);
}
