#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* BuildOneTwoThree(){
  struct node* head = NULL;
  struct node* second = NULL;
  struct node* third = NULL;

  head = malloc(sizeof(struct node));
  second = malloc(sizeof(struct node));
  third = malloc(sizeof(struct node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  return head;
}

void print(struct node* head){
  while(head){
    printf("%d",  head -> data);
    head = head->next; 
  }
}

int Length(struct node* head){
  struct node* current = head;
  int count =  0;

  while (current != NULL){
    count++;
    current = current->next;
  }
  return count;
}

void LengthTest() {
  struct node* myList = BuildOneTwoThree();

  int len = Length(myList);
}

int main(){
  struct node* lista = BuildOneTwoThree();
  Length(lista);
  LengthTest();
  print(lista);

  return 0;
}
