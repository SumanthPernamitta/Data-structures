#include <stdio.h>

//function callback
typedef void (*new_cb)(void);

new_func(void)
{
    printf("control comes here\n");
}

main()
{
 new_cb cb_new = new_func;
 printf("Main_func\n");
 call_func_cb(&cb_new);
}

call_func_cb(new_cb *Cb_func)
{
    printf("Calling from Lower level func\n");
    (*Cb_func)();
}
