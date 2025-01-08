#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CAL_SIZE(u) (char *)(u+1) - (char *)u
#define DEFAULT_SIZE 10

struct primary{
    char m;
    long n;
    int *p;
};

struct secondary{
    int q;
    struct primary *r;
};

int main()
{ 
    /* pointers*/
    void *void_ptr;
    char *char_ptr;
    long *long_ptr;
    
    /* structures */
    struct primary x;
    struct primary *y;
    struct secondary w;
    struct secondary *z;

    /* arrays */
    int a[10];      //1-D Array
    int *b[10];     //Array of pointers
    int (*c)[10];   //Pointer to an array
    int d[10][10];  //2-D Array
    int *e;         //Pointer to a integer
    int *f;         //Pointer to a integer
    
    /*representing large variable data with small variabled*/
    long l = 0x1111222233334444;  // long
    
    e = (int *)malloc(sizeof(int)*10);  //allocate memory from heap and assign to 'e' 
    c = &a;         //assign addr of 1-D array 'a' to Pointer 'c'
    y = &x;         //assign addr of struct 'x' to structure pointer 'y'
    z = &w;         //assign addr of struct 'w' to structure pointer 'z'
    f = (int *)&l;  //assign addr of long 'l' to pointer(int) 'f'
    x.m = 'h';      //assign a char to 'struct primary' member 
    x.n = l;        //assign a long to 'struct primary' member
    x.p = e;        //assign a int pointer to struct primary member
    e[0] = 10;      //assign a value to 'e'
    w.r = y;        //assign "struct primary" pointer to member of "struct secondary" structure
      
    printf("\n");
    printf("Addr : a = %p\n",a);
    printf("Addr : &a = %p\n",&a);
    printf("Addr : *a = %d\n",*a);
    printf("Addr : a+1 = %p\n",a+1);
    printf("Addr : &a+1 = %p\n",&a+1);
    
    printf("\n");
    printf("Addr : b = %p\n", b);
    printf("Addr : &b = %p\n", &b);
    printf("Addr : *b = %p\n", *b);
    printf("Addr : b+1 = %p\n", b+1);
    printf("Addr : &b+1 = %p\n", &b+1);
    
    printf("\n");
    printf("Addr : c = %p\n", c);
    printf("Addr : &c = %p\n", &c);
    printf("Addr : *c = %p\n", *c);
    printf("Addr : c+1 = %p\n", c+1); //c+1 is equal to &a+1
    printf("Addr : &c+1 = %p\n", &c+1);

    printf("\n");
    printf("Addr : d = %p\n", d);
    printf("Addr : &d = %p\n", &d);
    printf("Addr : *d = %p\n", *d);
    printf("Value : **d = %d\n", **d);
    printf("Addr : d+1 = %p\n", d+1);
    printf("Addr : d+2 = %p\n", d+2);
    printf("Addr : &d+1 = %p\n", &d+1);
    
    printf("\n");
    printf("Addr : e = %p\n", e);
    printf("Addr : &e = %p\n", &e); // addr in stack 
    printf("Addr : e+1 = %p\n", e+1);
    printf("Addr : &e+1 = %p\n", &e+1); // addr in stack + 1
    
    printf("\n");
    printf("sizeof : void ptr = %ld\n", sizeof(void_ptr));
    printf("sizeof : char ptr = %ld\n", sizeof(char_ptr));
    printf("sizeof : long ptr= %ld\n", sizeof(long_ptr));
    printf("sizeof : long = %ld\n", sizeof(l));
    
    printf("\n");
    printf("sizeof struct : x = %ld\n", sizeof(x));
    printf("sizeof struct pointer : y = %ld\n", sizeof(y));
    printf("sizeof structure without sizeof : y = %ld\n", CAL_SIZE(y));
    printf("Addr struct pointer : &y= %p\n", &y);
    printf("struct member : x.m = %c\n", x.m);
    printf("struct member : (*y).m = %c\n", (*y).m);
    printf("struct member : y->m = %c\n", y->m);
    printf("struct member : &y->p = %p\n", &y->p);
    printf("struct member : &w.r->p = %p\n", w.r->p);
    printf("struct member : &z->r->p = %p\n", &z->r->p);
    printf("struct member : x.p = %p\n", x.p);
    printf("struct member : y->p = %p\n", y->p);
    printf("struct member : z->r->p = %p\n", z->r->p);
    printf("struct member : w.r->p = %p\n", w.r->p);
    printf("struct member : *y->p = %d\n", *y->p);
    printf("struct member : *z->r->p = %d\n", *w.r->p);
    printf("struct member : *z->r->p = %d\n", *z->r->p);

    printf("\n");
    printf("LSB : %x\n", *f);
    printf("MSB : %x\n", *(f+1));
    
    return 0;
}
