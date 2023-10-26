#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head_node;
int list_length = 0;

void create_head(int element){
    head_node = (struct Node *)malloc(sizeof(struct Node));
    head_node->data = element;
    head_node->next = NULL;
    list_length++;
}

void insert_end(int value){
    struct Node *temp, *newNode;
    temp = head_node;
    if (head_node == NULL)
    {
        printf("create head node first\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;   
        }

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL; 
        temp->next = newNode;
        list_length++;
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
        list_length++;
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
        list_length++;
    }
}

int delete_front()
{
    struct Node *temp, *prev_node;
    int value;
    temp = head_node;
    temp = head_node;
    if (head_node == NULL)
    {
        printf("List is empty. Create head node first\n");
    }
    else
    {
        prev_node = temp;
        value = prev_node->data;
        head_node = head_node->next;
        free(prev_node);
        list_length--;
    }
    return value;
}

int delete_end()
{
    struct Node *temp, *prev_node;
    int value;
    temp = head_node;
    if (head_node == NULL)
    {
        printf("List is empty. Create head node first\n");
    }
    else
    {
        while (temp->next!= NULL)
        {
            prev_node = temp;
            temp = temp->next;
        }
        value = temp->data;
        prev_node->next = NULL;
        free(temp);
        list_length--;
    }
    return value;
}

int delete_between(int position)
{
    struct Node *temp, *prev_node, *next_node;
    int value, index = 0;
    temp = head_node;
    
    if (head_node == NULL) 
    {
        printf("List is empty. Create head node first\n");
        return -1;
    } 
    
    if (position == 0)
    {
        return delete_front();
    }
    
    while ((temp != NULL) && (index < position)) 
    {
        prev_node = temp;
        temp = temp->next;
        index++;
    }

    if (temp == NULL)
    {
        printf("Position not found in the list.\n");
        return -1;
    }

    next_node = temp->next;
    value = temp->data;
    prev_node->next = next_node;
    free(temp);
    list_length--;
    
    return value;
}


void search_list(int value)
{
    struct Node *temp;
    int index = 0;
    temp = head_node;
    if (head_node == NULL)
    {
        printf("List is empty. Create head node first\n");
    }
    else
    {
        while (temp!= NULL && temp->data!= value)
        {
            temp = temp->next;
            index++;
        }
        if (temp == NULL)
        {
            printf("Element not found\n");
        }
        else
        {
            printf("Element found. Element at %d index\n", index);
        }
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
            printf("Deleted value: %d\n", delete_between(position));
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
