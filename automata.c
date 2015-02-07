#include <stdio.h>
#include <time.h>
#define CONT 60

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
void reverse(int i);

int main() {
    int i;
    init();
    for(i = 0; i < 250; i++)
          step(1);
    printf("\n");
    for(i = 0; i <0; i++)
          step(0);
    //display();
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
          if (way) local(i) ;
              else reverse(i);
     
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
     
     if (i<0) left = _cur + CONT; else left = _cur + i - 1;
     int *self = (_cur + i);
     if (i>=CONT) right = _cur; else right = _cur + i + 1;
     
     int *next =  (_next + i);
     
     if (*left &&  *self && *right)
        *next = 1;
        else 
        if (*left &&  !*self && *right)
           *next = 1;
           else 
           if (!*left &&  !*self && !*right)
              *next = 1;
     else
         *next = 0;
         
         return *next;
}

void reverse(int i) {
     int *next =  (_next + i);
     int pre =   *(_pre + i);
     int cur =   *(_cur + i);
//     local(i);
        //*next = (*next  + pre)%2;
        *next = local(i) ^ pre;
    // *next = local(i) ^ pre;
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
          }*/
    
    printf("\n");
}

