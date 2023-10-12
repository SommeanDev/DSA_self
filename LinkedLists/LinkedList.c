#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head_node;

void create_headNode(int element)
{
    head_node = (struct Node *)malloc(sizeof(struct Node));
    head_node->data = element;
    head_node->next = NULL;
    printf("created headNode\n");
}

void append(int element){
    printf("Entered append\n");
    struct Node *temp, *temp1;
    temp = head_node;

    if (head_node == NULL)
    {
        printf("create the head node first\n");
    }
    else
    {
        printf("entered else\n");
        while (temp->next != NULL)
        {
            printf("Entered while\n");
            temp1 = temp->next;
        }
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = element;
        printf("created %d\n", temp->data);
        temp1->next = temp;
    }    
}

void traverse(){
    struct Node *temp;
    temp = head_node;

    int evenNode = 0;
    if (head_node == NULL)
    {
        printf("create the head node first\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            if (evenNode == 0)
            {
                printf("%d -> ", temp->data);
            }
            else
            {
                printf("%d -> ", temp->data);
                evenNode = 0;
            }
            temp = temp->next;
            evenNode = 1;
        } 
    }
}

int main(int argc, char const *argv[])
{
    create_headNode(10);
    append(20);
    append(30);
    append(40);
    traverse();
    return 0;
}
