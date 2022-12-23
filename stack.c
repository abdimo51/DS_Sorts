#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack operations
void push();       
int pop();         
int peek();        
bool isEmpty(); 

struct node{
    int val;
    struct node *next;
};

struct node *head;

int main (){
    int choice=0;
    printf("THIS IS DYNAMIC STACK");
    while(1){
        printf("\n\nChoose the blelow operations:\n");
        printf("\n 0: Exit 1: Push 2: Pop 3: Peek\n 4: Check if stack is empty\n");
        scanf("%d",&choice);
        switch(choice){
            case 0: exit(0);
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: isEmpty(); break;
            default: printf("Please try a correct operation!");
        }
    }
}

void push (){
    int val;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter a val to be inserted: ");
    scanf("%d", &val);

    if(head == NULL){
        ptr->val = val;
        ptr->next = NULL;
        head = ptr;
    }
    else{
        ptr->val = val;
        ptr->next = head;
        head=ptr;
    }
}

int pop(){
    int item;
    struct node *ptr;
    if (head == NULL)
        printf("Sorry! Underflow State: cannot remove any element");
    else{
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("%d is removed out of the stack", item);
        return item;
    }
    return -1;
}

int peek(){
    int x = head->val;
    printf("%d is the topmost element \n", x);
    return x;
}

bool isEmpty(){
    if(head == NULL){
        printf("Sorry! The stack is empty: Underflow State\n");
        return true;
    }
    printf(" Is not an empty stack\n");
    return false;
}

