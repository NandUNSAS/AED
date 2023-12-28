#include <stdio.h>
#include <stdlib.h>


typedef struct node* List;
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

int Count(struct node* current,int data) {
    int count = 0;
    
    while (current) {
      if(current->data == data)
	  count++;
      current = current->next;
    }
    return count;
}

void CountTest() {
    List myList = BuildOneTwoThree ();
    int count = Count(myList,2);
}



int main(){

}
