#include <stdio.h>
#include <stdlib.h>

struct node { //Structure Linked List
    int data;
    struct node *next;
};
void insertNodeSorted(struct node **head, int curVal){ //Takes in head pointer & new Value
    struct node *temp = (struct node *)malloc (sizeof(struct node)); //Allocates memory
    if (temp ==NULL){
        printf("Error: Memory allocation failed!");
        exit(1);
    }
    temp->data = curVal; //sets new value to temp
    temp->next = NULL; // temp has no pointer yet
    if (*head == NULL){ // if head is Null
        *head = temp; // Temp is first value in the list
    }else{
        struct node *val; // pointer value
        struct node *preval; //pointer prevalue
        val = *head; // value is set = to head pointer
        if ((val->data < curVal) || (val->data == curVal)){ // checks if new value is greater than or equal
            if (val->next != NULL){ // checks if next value is NULL
                while (val->next != NULL){ // Goes through Linked List
                    preval = val; // sets current value to preval
                    val = val->next; // sets value to next value in list
                    if ((val->data > curVal) || (val->data == curVal)){ // checks if next value is greater or equal
                        temp->next = val; // sets temp pointer to new val
                        preval->next = temp; // sets previos pointer to temp
                        break; // breaks
                    }
                    if (val->next == NULL){ // cehcks if next value is null
                        val->next = temp; // sets last poiner to temp
                        break; // breaks
                    }
                }
            }else{
                val->next = temp; // sets next value pointer to temp
            }
        }else{
            temp->next = val; // sets temp pointer to head
            *head =temp; // head is set to temp
        }

    }
}
void printList(struct node **head){ //Takes the Head goes through the list & prints out the values
    struct node *val; // struct pointer 
    val = *head; // val pointer = to head of linked list pointer
    printf("After Insert & Sort:\n"); //prints message
    printf("%d ", val->data); // prints first value in list
    while(val->next != NULL){ // goes through list
        val = val->next; // sets value to next value in list
        printf("%d ", val->data); // prints value
    }
    printf("\n"); // print break
}
void deleteList(struct node **head){ //Takes the Head goes through the list & deletes the values
    struct node *temp; //struct pointer
    struct node *val; //struct pointer
    val = *head; // val pointer = to head of linked list pointer
    while(val->next != NULL){ //goes through list
        temp = val; //temp pointer is set = to head
        val = val->next; // next list value set to val
        temp->next = NULL; // head pointer set to null
        free(temp); // head freed
    }
    free(val); // last value freed
}
int main (int argc, char *argv[]){ // Main Takes in 3 Arguments
    if (argc != 4){ // Checks that 3 Arguments were given
        printf("Error: Incorrect Argument Input!"); //Prints Error Message
        exit(0); // Exits Program
    }
    int i; //loop variable
    int curVal; //current value
    int seed; //seed for random
    int length; //length of list
    int max_val; // max value for rand
    sscanf(argv[1], "%d", &seed); //sets argument to seed
    sscanf(argv[2], "%d", &length); // sets argument to length
    sscanf(argv[3], "%d", &max_val); //sets argument to max_val
    srandom(seed); //seed random
    struct node *head = NULL; // head node set to null
    printf("Pre Insert & Sort:\n"); //print message
    for (i=0; i<length; i++){ // creates the length
        curVal = random()%(max_val+1); //generate rand num from 0 to max_val (inclusive);
        printf("%d ", curVal); // prints current value
        insertNodeSorted(&head, curVal); //sends head pointer & new value
    }
    printf("\n"); // prints break
    printList(&head); //sends head pointer
    deleteList(&head); //sends head pointer
    exit(0); //exits program
}