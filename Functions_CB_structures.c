#include <stdio.h>

typedef void (*func_cb)(void);
typedef void (*func_cb_two)(void);

typedef struct{
    func_cb func_cb_t;
    func_cb_two func_cb_u;
}cb_struct;


void old_func2(void)
{
    printf("In old callback function 2\n");
}

void old_func(void)
{
    printf("in callback function 1\n");
}

cb_struct new_struct =
{
    old_func,
    old_func2
};

void calling_func(cb_struct *);

main()
{
    printf("I am in main function\n");
    calling_func(&new_struct);
}

void calling_func(cb_struct *newss)
{
    printf("I am at calling function\n");
    newss->func_cb_t();
    newss->func_cb_u();
}



