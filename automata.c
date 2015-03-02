#include <stdio.h>
#include "um.c"
#include "_code.c"
#include "_file.c"
#define longway 10
#define MAX_CONT 20

FILE *input; 
FILE *output; 

int LONGS;
int CONT;
    
item a[MAX_CONT];
item b[MAX_CONT];
item c[MAX_CONT];

item *_next = &a;
item *_cur = &b;
item *_pre = &c;

void step();
void block();
void swip();
void display();
item local(int i);


int main(int argc, char *argv[]) {
    if(argc<2)  exit(1);
    int i,j;
    LONGS  = strlen(argv[4]);
    CONT = LONGS*8;
    printf("%d",LONGS);
  
    printf("%s\n", argv[1]);
    input = fopen(argv[1], "r");  
    output = fopen(argv[3], "w");  
    
    for(j=0;j<6/LONGS;j++) {
       // printf("\n%d---\n",j);
        block(strcmp(argv[2], "-e"));
    }
    
    fclose(input);
    fclose(output);
    printf("\n");
    getch();
}

void block(int decrypt) {
    int i;
    if (!decrypt)
     for(i = 0; i < CONT; i++) 
          *(_pre + i) = NULL;
    fileread(input,_cur,_pre,decrypt,LONGS);
    for(i = 0; i < longway; i++)
          step(); 
    filewrite(output,_cur,_pre,decrypt, LONGS);
}


void step() {
     printf("step\n");
    int i;
    for(i = 0; i < CONT; i++)
          *(_next + i) = local(i) ;
    display();
    swip();
}

void swip() {
     int i;
     for(i = 0; i < CONT; i++) 
          *(_pre + i) = *(_cur + i) ;
          
     item *temp = _cur;
    _cur = _next;
    _next = temp;
}

item local(int i) {
    item *left,*right ;
    item *self = (_cur + i);
    if (i<0) left = _cur + CONT; else left = _cur + i - 1;
    if (i>=CONT) right = _cur; else right = _cur + i + 1;
    
    item pre = *(_pre + i);
     
    if (*left && *self && *right)
       return (pre + 1) %2;
       else
       if (*left && !*self && *right)
          return (pre + 1) %2;
          else
          if (!*left && !*self && !*right)
             return (pre + 1) %2;
    else
        return (pre + 0) %2;
        
        //return pre ^ (*left ^ *self * *right) ;
}


void display() {
    printf("pre:"); encodep(_pre, LONGS);printf("\n");
    printf("cur:"); encodep(_cur, LONGS);printf("\n");
    printf("next:"); encodep(_next, LONGS);printf("\n");
    printf("\n"); 
}

