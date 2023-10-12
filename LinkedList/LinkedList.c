#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head_node;

void create_head(int element){
    head_node = (struct Node *)malloc(sizeof(struct Node));
    head_node->data = element;
    head_node->next = NULL;
}

void insert_end(int value){
    struct Node *temp, *newNode;
    temp = head_node;
    if (head_node == NULL)
    {
        printf("create head node first");
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;   
        }

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        temp->next = newNode;
    }
}

void insert_begin(int value)
{
    struct Node *temp, *newNode;
    
    if (head_node == NULL)
    {
        printf("create head node first\n");
    }
    else
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        temp = head_node;
        head_node = newNode;
        head_node->next = temp;
    }
}

void insert_between(int value, int position)
{
    struct Node *temp, *new_node, *prev_node;
    int index = 0;
    temp = head_node;
    if (head_node == NULL)
    {
        printf("create head node first\n");
    }
    else
    {
        while (temp != NULL && index != position)
        {
            prev_node = temp;
            temp = temp->next;
            index++;
        }
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = value;
        prev_node->next = new_node;
        new_node->next = temp;
    }
}

void traverse()
{
    struct Node *temp;
    temp = head_node;

    if (head_node == NULL)
    {
        printf("create head node first\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    
}

int main(int argc, char const *argv[])
{
    /* create_head(10);
    insert_begin(20);
    insert_begin(30);
    insert_between(40, 1);
    traverse(); */

    int value, position, reply, breakloop = 0;
    
    while (breakloop != 1)
    {
        printf("\nWhat do you want to do?:\n");
        printf("1 - create head node\n");
        printf("2 - insert value in front\n");
        printf("3 - insert value in between\n");
        printf("4 - insert value at end\n");
        printf("(Enter an other no. to exit)\n");
        printf("You: ");

        scanf("%d", &reply);

        switch (reply)
        {
        case 1:
            printf("Enter value to store in head: ");
            scanf("%d", &value);
            create_head(value);
            printf("created head\n");
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert_begin(value);
            printf("Current list: ");
            traverse();
            break;
        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("insert position to insert at (index): ");
            scanf("%d", &position);
            insert_between(value, position);
            printf("Current list: ");
            traverse();
            break;
        case 4:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert_end(value);
            printf("Current list: ");
            traverse();
            break;
        default:
            printf("Exiting ...\n");
            breakloop = 1;
            break;
        }
    }
    

    return 0;
}
