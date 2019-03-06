#include<stdio.h>
typedef struct
{
    int a;
    char b[10];
}*userdata;

typedef struct
{
    userdata * data;
}*testing;

main()
{
        userdata somedata;//,element;
      //  somedata = &element;
        scanf("%d",&somedata->a );        //scanf("%s",somedata->b);
        printf("value is %d ",&somedata->a);

}
