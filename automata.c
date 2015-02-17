#include <stdio.h>
#include <time.h>
#define LONGS 5
#define CONT LONGS*8
#define longway 10

typedef char item;

FILE *input; 
FILE *output; 
    
item a[CONT];
item b[CONT];
item c[CONT];

item *_next = &a;
item *_cur = &b;
item *_pre = &c;

void init();
void init(char* text);
void fileread(int decrypt);
void filewrite(int decrypt);
void step(int reversible);
void swip();
void display();
item local(int i,int reversible);
void reverse();
void decode(char bytes[], item* to);
void encode(item* bits, char* to);
void encodep(item* bits);

int main(int argc, char *argv[]) {
  if(argc<2)  exit(1);
  int i,j;
  
  
  printf("%s\n", argv[1]);
  input = fopen(argv[1], "r");  
  output = fopen(argv[3], "w");  
  
    //if (!) {
       fileread(strcmp(argv[2], "-e"));
        for(i = 0; i < longway; i++)
              step(1); 
        filewrite(strcmp(argv[2], "-e"));
   /* }
    if (!strcmp(argv[2], "-d")) { 
       fileread(1);  
        for(i = 0; i <longway; i++)
              step(1);
        filewrite(1);
    }*/
    fclose(input);
    fclose(output);
    printf("\n");
    getch();
}


void fileread(int decrypt) {
    int i;
    char bytes[LONGS];
    
    if(input != NULL) {
        for(i=0; i<LONGS;i++) 
           bytes[i] = getc(input); 
        decode(&bytes[0],_pre);   
        //decryption additional reading for previous step  
        if (decrypt) { 
            for(i=0; i<LONGS;i++) 
            bytes[i] = getc(input); 
            decode(&bytes[0],_cur); 
        }
    }        
}



void filewrite(int decrypt) {
    int i;
    char bytes[LONGS];
    if(output != NULL) {
       encode(_cur,&bytes[0]);
       for(i=0; i<LONGS;i++) 
           putc(bytes[i],output); 
           
       if (!decrypt) {
           encode(_pre,&bytes[0]);
           for(i=0; i<LONGS;i++) 
               putc(bytes[i],output); 
       }
    }
}


void init(char* text) { 
    decode(text,_next);
    swip();
}

void decode(char* bytes, item* bits) {
    int i,j;
    for(i=0; i<LONGS;i++) 
       for(j=0;j<8;j++)
          *(bits + 8*i + j) = !!(*(bytes+i) & (1<<j));

}

void encode(item* bits, char* bytes) {
    int i,j;
    for(i=0; i<LONGS;i++){
       char a = 0;
       for(j=0;j<8;j++)
          a+= *(bits + 8*i + j) <<j; 
       *(bytes + i) = a;
    }
}

void encodep(item* bits) {
    int i,j;
    for(i=0; i<LONGS;i++){
       char a = 0;
       for(j=0;j<8;j++)
          a+= *(bits + 8*i + j) <<j; 
       printf("%c",a);
    }
}

void step(int reversible) {
     printf("step\n");
    int i;
    for(i = 0; i < CONT; i++)
          *(_next + i) = local(i,reversible) ;
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

item local(int i, int reversible) {
    item *left,*right ;
    item *self = (_cur + i);
    if (i<0) left = _cur + CONT; else left = _cur + i - 1;
    if (i>=CONT) right = _cur; else right = _cur + i + 1;
    
    item pre = 0;
    if (reversible)
        pre =   *(_pre + i);
     
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
     int bitch = 0;
     for(i = 0; i < CONT; i++) 
          bitch+=*(_pre + i) ;
     if (!bitch) {  //printf("bitch!");
      step(0);
      }
     for(i = 0; i < CONT; i++) 
          *(_next + i) = *(_pre + i) ;
    display();
     swip();
     
}

void display() {
    int i;
    char s;
    int count =0;
    //for(i = 0; i < longway; i++) {
    printf("pre:"); encodep(_pre);printf("\n");
    printf("cur:"); encodep(_cur);printf("\n");
    printf("next:"); encodep(_next);printf("\n");
    printf("\n");
          //count += *(_cur+i) ^ *(_cur+i+1);
          /*if (!*(_cur + i)) s = '0';
                    else s = '_';
          printf("%c", *(_cur + i));*/
      //    }
    //printf("\n");
}

