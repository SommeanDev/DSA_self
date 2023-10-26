#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *head_node;
int list_length = 0;

void create_head(int data)
{
    if (head_node != NULL) 
    {
        printf("Head node already created\n");
    }
    else
    {
        head_node = (Node *)malloc(sizeof(Node));
        head_node->data = data;
        head_node->next = NULL;
        head_node->prev = NULL;
        list_length++;
    }
}

void insert_begin(int data)
{
    Node *new_node, *temp;
    temp = head_node;
    if (head_node == NULL)
    {
        printf("Create head node first\n");
    }
    else
    {
        new_node = (Node *)malloc(sizeof(Node));
        new_node->data = data;
        new_node->next = temp;
        new_node->prev = NULL;
        temp->prev = new_node;
        head_node = new_node;
        list_length++;
    }    
}

void insert_end(int data)
{
    Node *new_node, *temp;
    temp = head_node;
    if(head_node == NULL)
    {
        printf("Create head node first\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new_node = (Node *)malloc(sizeof(Node));
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = temp;
        temp->next = new_node;
        list_length++;
    }
}

void insert_after(int data, int position)
{
    Node *new_node, *temp, *prev;
    int index = 0;
    temp = head_node;
    if(head_node == NULL)
    {
        printf("Create head node first\n");
    }
    else
    {
        while (temp->next != NULL && index != position)
        {
            prev = temp;
            temp = temp->next;
            index++;
        }
        
        new_node = (Node *)malloc(sizeof(Node));
        new_node->data = data;
       
        new_node->prev = prev;
        prev->next = new_node;
       
        new_node->next = temp;
        temp->prev = new_node;
       
        list_length++;
    }
}

int delete_front()
{
    Node *temp;
    int data;
    if(head_node == NULL)
    {
        printf("Create head node first\n");
    }
    else
    {
        temp = head_node;
        data = temp->data;
        head_node = head_node->next;
        free(temp);
        list_length--;
        return data;
    }
}

int delete_end()
{}

int delete_after(int position){}

void search_list(int value){}

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
            printf("<- %d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    
}

void menu_List()
{
    int value, position, reply, breakloop = 0;
    
    while (breakloop != 1)
    {
        printf("\nWhat do you want to do?:\n");
        printf("1 - create head node\n");
        printf("2 - insert value in front\n");
        printf("3 - insert value in between\n");
        printf("4 - insert value at end\n");
        printf("5 - delete value from front\n");
        printf("6 - delete value from end\n");
        printf("7 - delete value from between\n");
        printf("8 - Search an element in the list\n");
        printf("9 - View List Length\n");
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
            insert_after(value, position);
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
        case 5:
            printf("Deleted value: %d\n", delete_front());
            traverse();
            break;
        case 6:
            printf("Deleted value: %d\n", delete_end());
            traverse();
            break;
        case 7:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            printf("Deleted value: %d\n", delete_after(position));
            traverse();
            break;
        case 8:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search_list(value);
            break;
        case 9:
            printf("Length of the List is: %d\n",list_length);
            traverse();
            break;
        default:
            printf("Exiting ...\n");
            breakloop = 1;
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    menu_List();
    return 0;
}


