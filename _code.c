//don't forget to declare 
//typedef char item

void decode(char bytes[], item* to, int LONGS);
void encode(item* bits, char* to, int LONGS);
void encodep(item* bits, int LONGS);

void decode(char* bytes, item* bits, int LONGS) {
    int i,j;
    for(i=0; i<LONGS;i++) 
       for(j=0;j<8;j++)
          *(bits + 8*i + j) = !!(*(bytes+i) & (1<<j));

}

void encode(item* bits, char* bytes, int LONGS) {
    int i,j;
    for(i=0; i<LONGS;i++){
       char a = 0;
       for(j=0;j<8;j++)
          a+= *(bits + 8*i + j) <<j; 
       *(bytes + i) = a;
    }
}

void encodep(item* bits, int LONGS) {
    int i,j;
    for(i=0; i<LONGS;i++){
       char a = 0;
       for(j=0;j<8;j++)
          a+= *(bits + 8*i + j) <<j; 
       printf("%c",a);
    }
}
