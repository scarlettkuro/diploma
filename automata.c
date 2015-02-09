#include <stdio.h>
#include <time.h>
#define LONGS 5
#define CONT LONGS*8
#define longway 10

typedef char item;

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
void decode(char bytes[], item* to);
void encode(item* to);

int main() {
    int i,j;
    
    init();
    for(i = 0; i < longway; i++)
          step(0);
    reverse();
    for(i = 0; i <longway-1; i++)
          step(0);
    encode(_cur);
          
    printf("\n");
    getch();
}

void decode(char bytes[], item* to) {
    int i,j;
    for(i=0; i<LONGS;i++) 
       for(j=0;j<8;j++)
          *(to + 8*i + j) = !!(bytes[i] & (1<<j));

}

void encode(item* from) {
    int i,j;
    for(i=0; i<LONGS;i++){
       char a = 0;
       for(j=0;j<8;j++)
          a+= *(from + 8*i + j) <<j; 
       printf("%c",a);
       
    }
}

void init() { 
    char text[LONGS];
    scanf("%s",&text);
    decode(text,_next);
    swip();
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
    for(i = 0; i < CONT; i++) {
          //count += *(_cur+i) ^ *(_cur+i+1);
          if (!*(_cur + i)) s = '0';
                    else s = '_';
          printf("%c", *(_cur + i));
          }
    printf("\n");
}

