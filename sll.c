//Implementation of linked list  

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}sll;

sll *head = NULL;

void insert_at_first();
void insert_at_last();
void delete_at_first();
void delete_at_last();
void reverse_list();
void display_list();

int main()
{
    int choice;
    while(1)
    {
        printf("1.Insert at frist\n2.Insert at last\n3.Delete at first\n4.Delete at last\n5.Reverse list\n6.Display\n7.Exit\n");
        printf("Enter the option\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insert_at_first();
            break;
            case 2 : insert_at_last();
            break;
            case 3 : delete_at_first();
            break;
            case 4 : delete_at_last();
            break;
            case 5 : reverse_list();
            break;
            case 6 : display_list();
            break;
            case 7 : exit(0);
        }
    }

    return 0;
}

void insert_at_first()
{
    int data;
    sll *newnode = (sll *)malloc(sizeof(sll));
    if(newnode == NULL)
    printf("Unable to allocate memory\n");
    else
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
}

void insert_at_last()
{
    int data;
    sll *temp;
    sll *newnode = (sll *)malloc(sizeof(sll));
    if(newnode == NULL)
    printf("Unable to allocate memory\n");
    else
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void display_list()
{
    sll *temp = head;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("List contains:\n");
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void delete_at_first()
{
    sll *temp;
    if(head == NULL)
    printf("List is empty\n");
    else if(head->next == NULL)
    {
        temp = head;
        head = NULL;
        free(temp);
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    
}
void delete_at_last()
{
    sll *temp, *temp1;
    if(head == NULL)
    printf("List is empty\n");
    else if(head->next == NULL)
    {
        temp = head;
        head = NULL;
        free(temp);
    }
    else
    {
        temp = head;
        while(temp->next->next != NULL)
        temp = temp->next;
        temp1 = temp->next;
        temp->next = NULL;
        free(temp1);
    }
}
void reverse_list()
{
    sll *prevnode, *currnode, *nextnode;
    prevnode = NULL;
    nextnode = currnode = head;
    while(nextnode != NULL)
    {
        nextnode = nextnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    head = prevnode;
}