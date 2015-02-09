#include <stdio.h>
#include <time.h>
#define CONT 5
#define longway 20

typedef  char item;

item a[CONT];
item b[CONT];
item c[CONT];

item *_next = &a;
item *_cur = &b;
item *_pre = &c;

void init();
void step();
void swip();
void display();
item local(int i);
void reverse();

int main() {
    int i,j;
    init();
    for(i = 0; i < longway; i++)
          step(0);
    reverse();
    for(i = 0; i <longway-1; i++)
          step(0);
          
    printf("\n");
    getch();
}

void init() { 
     /*
    srand(time(0));
    
    int i;
    for(i = 0; i < CONT; i++)
          *(_cur + i) = (item)rand()%2;
          */
        int i;  
    item text[CONT];
    scanf("%s",&text);
    item *t = &text[0];
    for(i = 0; i < CONT; i++)
          *(_next + i) =  *(t + i) ;
          swip();
    printf("\n");
}

void step() {
    int i;
    for(i = 0; i < CONT; i++)
          *(_next + i) = local(i) ;
     
    swip();
    display();
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
    
    item pre =   *(_pre + i);
     /*
    if (*left && *self && *right)
       return pre ^ 1;
       else
       if (*left && !*self && *right)
          return pre ^ 1;
          else
          if (!*left && !*self && !*right)
             return pre ^ 1;
    else
        return pre ^ 0;
        */
        return pre ^ (*left ^ *self * *right) ;
}

void reverse() {
     int i;
     for(i = 0; i < CONT; i++) 
          *(_next + i) = *(_pre + i) ;
          swip();
     
    display();
}

void display() {
    int i;
    char s;
    int count =0;
    for(i = 0; i < CONT; i++) //{
         // count += *(_cur+i);
          //if (!*(_cur + i)) s = '0';
                    //else s = '_';
          printf("%c", *(_cur + i));
         // }
         /*
    printf("|");
    for(i = 0; i < CONT; i++) {
          if (!*(_pre + i)) s = '0';
                    else s = '_';
          printf("%c", s);
          }
    */
    printf("\n");
}

