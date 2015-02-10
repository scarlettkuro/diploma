#include <stdio.h>
#include <time.h>
#define LONGS 5
#define CONT LONGS*8
#define longway 100

typedef char item;

item a[CONT];
item b[CONT];
item c[CONT];

item *_next = &a;
item *_cur = &b;
item *_pre = &c;

void init();
void init(char* text);
void fileinit(char* text);
void step();
void swip();
void display();
item local(int i);
void reverse();
void decode(char bytes[], item* to);
void encode(item* to);

int main(int argc, char *argv[]) {
  if(argc<2)  exit(1);
  printf("%s\n", argv[1]);

    int i,j;
    
    fileinit(argv[1]);
    for(i = 0; i < longway; i++)
          step(0);
    reverse();
    for(i = 0; i <longway-1; i++)
          step(0);
    encode(_cur);
          
    printf("\n");
    getch();
}
/*

void init() { 
    char text[LONGS];
    scanf("%s",&text);
    decode(&text[0],_next);
    swip();
}
*/
void fileinit(char *name) {
    int i;
    FILE *fp; 
    char bytes[LONGS];
    if((fp = fopen(name, "r")) != NULL)
           for(i=0; i<LONGS;i++) 
           //printf("%c", getc(fp));
                     bytes[i] = getc(fp); 
    decode(&bytes[0],_next);    
    swip();
}
void init(char* text) { 
    decode(text,_next);
    swip();
}

void decode(char* bytes, item* to) {
    int i,j;
    for(i=0; i<LONGS;i++) 
       for(j=0;j<8;j++)
          *(to + 8*i + j) = !!(*(bytes+i) & (1<<j));

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

