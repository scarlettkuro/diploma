#include <stdio.h>
#include <time.h>
#define CONT 70

int a[CONT];
int b[CONT];
int c[CONT];

int *_next = &a;
int *_cur = &b;
int *_pre = &c;

void init();
void step();
void swip();
void display();
int local(int i);
void reverse();

int main() {
    int i,j;
    init();
   // for(j=0; j<1; j++) {
//    printf("%d\n",!0);
    for(i = 0; i < 4; i++)
          step(0);
    //printf("\n");
    reverse();
    for(i = 0; i <4-2; i++)
          step(0);
          
    printf("\n");
          //}
    getch();
}

void init() { 
    srand(time(0));
    
    int i;
    for(i = 0; i < CONT; i++)
          *(_cur + i) = rand()%2;
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
          
     int *temp = _cur;
    _cur = _next;
    _next = temp;
}

int local(int i) {
    int *left,*right ;
    int *self = (_cur + i);
    if (i<0) left = _cur + CONT; else left = _cur + i - 1;
    if (i>=CONT) right = _cur; else right = _cur + i + 1;
    
    int pre =   *(_pre + i);
     
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
    for(i = 0; i < CONT; i++) {
          if (!*(_cur + i)) s = '0';
                    else s = '_';
          printf("%c", s);
          }/*
    printf("|");
    for(i = 0; i < CONT; i++) {
          if (!*(_pre + i)) s = '0';
                    else s = '_';
          printf("%c", s);
          }
    */
    printf("\n");
}

