#include <stdio.h>  
   
//Show a node for a singly list 
struct node{  
    int data;  
    struct node *next;  
};      
   
//show the head and tail of the linked list  
struct node *head, *tail = NULL;  
   
//a function that will add new elements  
void addNode(int data) {  
    //find a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
      
    //see if the list is empty 
    if(head == NULL) {  
        //If yes, the head and tail will match the new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode will become new tail of the list  
        tail = newNode;  
    }  
}  
   
    //sortList will arrange nodes of the list in ascending order  
    void sortList() {  
        //current node will point to head  
        struct node *current = head, *index = NULL;  
        int temp;  
          
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                //Node index will point to node next to current  
                index = current->next;  
                  
                while(index != NULL) {  
                    /* If current node's data is greater than index's node data, swap the data between them */
                    if(current->data > index->data) {  
                        temp = current->data;  
                        current->data = index->data;  
                        index->data = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
    }  
   
//a function that will display all the nodes present in the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    }  
    while(current != NULL) {  
        //Displays each node by incrementing pointer  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
      
int main()  
{  
    //Adds elements to the list  
    addNode(45);  
    addNode(99);  
    addNode(24);  
    addNode(51);  
    addNode(42);  
    addNode(58);
    addNode(47);
    addNode(38);
    addNode(00);
    //Show the original element in the list  
    printf("Original: \n");  
    display();  
      
    //The sorted list  
    sortList();  
      
    //show the sorted list  
    printf("Sorted list: \n");  
    display();  
          
    return 0;  
}  