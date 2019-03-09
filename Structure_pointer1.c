#include<stdio.h>

/* created  a structure under the name example */
typedef struct
{
    int i;
}example;

/*declaring a function of structure type and pointer structure as argument*/
example location(example *);

main()
{
    example *start;
    scanf("%d",&start); // giving values a pointer structure
    location(start); // calling the function
}

example location(example *ex)
{
    printf("%d",ex);
}
