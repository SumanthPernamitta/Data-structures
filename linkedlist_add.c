#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *add_beg(struct node *);
struct node *display(struct node *);
struct node *add_end(struct node *);

int main()
{
    int option;

    do
    {
        printf("1. create_LL\n");
        printf("2. add_node_beg\n");
        printf("3. add_node_end\n");
        printf("3. display\n");
        printf("4. exit\n");
        printf("enter option\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            start = create_ll(start);
            printf("creatied ll\n");
            break;
        case 2:
            start = add_beg(start);
            printf("node is added at beg\n");
            break;
        case 3:
            start = add_end(start);
            printf("nodes is added at end\n");
            break;
        case 4:
            start = display(start);
            printf("nodes are displayed\n");
            break;
        }
    }while(option != 5);
    return 0;
}

struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("enter 1 to end\n");
    printf("enter the data\n");
    scanf("%d",&num);
    while(num != -1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        if(start == NULL)
        {
            new_node->next = NULL;
            start = new_node;

        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
    printf("Enter the data:\n");
    scanf("%d",&num);
    }
    return start;
}

struct node *add_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("enter the num\n");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *add_end(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("enter the num\n");
    scanf("%d",&num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return start;
}
