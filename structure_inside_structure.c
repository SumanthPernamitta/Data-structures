#include<stdio.h>

typedef struct
{
    int a;
    char b[10];
}userdata;

typedef struct
{
    userdata data;
}testing;

main()
{
        userdata somedata;
        scanf("%d",&somedata.data.a );        
        scanf("%s",somedata.data.b);
        printf("The struture values are %d and %s",somedata.data.a,structure.data.b);
}
