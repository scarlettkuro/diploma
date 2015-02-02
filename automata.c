#include <stdio.h>
#include <time.h>
#define CONT 20

int a[CONT];
int b[CONT];

int *_next = &a;
int *_cur = &b;

void init();
void step();
void display();
void local(int i);

int main() {
    int i;
    init();
    for(i = 0; i < 20; i++)
          step();
    display();
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
          local(i);
     
    int *temp = _cur;
    _cur = _next;
    _next = temp;
   // display();
}

void local(int i) {
     int *left ;
     if (i<0) left = _cur + CONT;
          else left = _cur + i - 1;
     int *self = (_cur + i);
     int *right ;
     if (i>=CONT) right = _cur;
        else right = _cur + i + 1;
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
    // *next = *self;
}

void display() {
    int i;
    char s;
    for(i = 0; i < CONT; i++) {
          if (!*(_cur + i)) s = '0';
                    else s = '_';
          printf("%c", s);
          }
    printf("\n");
}

