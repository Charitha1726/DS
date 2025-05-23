#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL, *new = NULL;

int len; // Global length variable

// Function to calculate the length of the linked list
int length() 
{
    struct node *temp = head;
    int count = 0;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Insert at the beginning
void Begin(int a) 
{
    new = (struct node*)malloc(sizeof(struct node));
    new->data = a;
    new->prev = NULL;
    new->next = NULL;

    if (head == NULL) 
    { 
        head = new;
    } 
    else {
        new->next = head;  
        head->prev = new;  
        head = new;         // Update head to new node
    }
}

// Insert at the end
void End(int a) 
{
    struct node *temp = head;
    new = (struct node*)malloc(sizeof(struct node));
    new->data = a;
    new->next = NULL;

    if (head == NULL) {
        new->prev = NULL;
        head = new;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new;
    new->prev = temp;
}

// Insert in the middle
void Middle(int a) 
{
    struct node *temp;
    int loc, i = 1;
    len = length();

    if (len == 0) {
        printf("The list is Empty\n");
        return;
    }

    printf("Enter the location to be inserted: ");
    scanf("%d", &loc);

    if (loc > len || loc < 1) {
        printf("Invalid Location\n");
        return;
    }

    temp = head;
    while (i < loc) {
        temp = temp->next;
        i++;
    }

    new = (struct node*)malloc(sizeof(struct node));
    new->data = a;

    new->next = temp->next;
    new->prev = temp;
    
    if (temp->next != NULL) 
    {
        temp->next->prev = new;
    }

    temp->next = new;
}

// Search for an element
void Search(int key) {
    struct node *temp = head;
    int pos = 1, found = 0;

    if (head == NULL) {
        printf("The list is empty. Cannot search.\n");
        return;
    }

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found) {
        printf("Element %d not found in the list.\n", key);
    }
}

// Delete from the beginning
void DBegin() {
    struct node *temp;
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
}

// Delete from the middle
void DMid() {
    struct node *temp;
    int loc, i = 1;
    len = length();

    if (len == 0) {
        printf("The list is empty\n");
        return;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &loc);

    if (loc > len || loc < 1) {
        printf("Invalid Location\n");
        return;
    }

    temp = head;
    while (i < loc) 
    {
        temp = temp->next;
        i++;
    }

    if (temp->prev != NULL) 
    {
        temp->prev->next = temp->next;
    } 
    else 
    { 
        head = temp->next; // If deleting the first node, update head
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Delete from the end
void DEnd() {
    struct node *temp = head;

    if (head == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    if (head->next == NULL) { // Only one node in the list
        free(head);
        head = NULL;
        printf("Last node deleted, list is now empty.\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL; // Second last node becomes last
    free(temp);
    printf("Last node deleted successfully.\n");
}

// Display the linked list
void Display() 
{
    struct node *temp;
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    len = length();
    printf("Total Elements: %d\n", len);
}

int main() {
    int a, ch;

    while (1) {
        printf("\n1. Insert Beginning\n");
        printf("2. Insert Middle\n");
        printf("3. Insert End\n");
        printf("4. Display\n");
        printf("5. Search\n");
        printf("6. Delete Beginning\n");
        printf("7. Delete Middle\n");
        printf("8. Delete End\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                Begin(a);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                Middle(a);
                break;
            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                End(a);
                break;
            case 4:
                Display();
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &a);
                Search(a);
                break;
            case 6:
                DBegin();
                break;
            case 7:
                DMid();
                break;
            case 8:
                DEnd();
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Enter a valid choice!\n");
        }
    }
}
