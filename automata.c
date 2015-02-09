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
void step(int way);
void swip();
void display();
int local(int i);
int reverse(int i);

int main() {
    int i,j;
    init();
   // for(j=0; j<1; j++) {
//    printf("%d\n",!0);
    for(i = 0; i < 4; i++)
          step(0);
    //printf("\n");
    for(i = 0; i < CONT; i++) 
          *(_next + i) = *(_pre + i) ;
          swip();
     
    display();
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

void step(int way) {
    int i;
    for(i = 0; i < CONT; i++)
          if (way) *(_next + i) = local(i) ;
              else *(_next + i) =  reverse(i);
     
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
    
    if (*left && *self && *right)
       return 1;
       else
       if (*left && !*self && *right)
          return 1;
          else
          if (!*left && !*self && !*right)
             return 1;
    else
        return 0;
}

int reverse(int i) {
     int *next =  (_next + i);
     int pre =   *(_pre + i);
     int cur =   *(_cur + i);
     return pre ^ local(i);
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

