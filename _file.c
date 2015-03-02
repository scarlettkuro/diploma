void fileread(FILE *input, item* _cur, item* _pre, int decrypt, int LONGS) ;
void filewrite(FILE *output, item* _cur, item* _pre, int decrypt, int LONGS);

void fileread(FILE *input, item* _cur, item* _pre, int decrypt, int LONGS) {
    int i;
    char bytesa[LONGS], bytesb[LONGS];
    
    if(input != NULL) {
        for(i=0; i<LONGS;i++) {
            bytesa[i] = getc(input); 
        //decryption additional reading for previous step  
            if (decrypt)  
                bytesb[i] = getc(input); 
        }
        
        
            if (decrypt)   {
        decode(&bytesb[0],_cur, LONGS);
        decode(&bytesa[0],_pre, LONGS);   
        } else {
               
        decode(&bytesa[0],_cur, LONGS);
        decode(&bytesa[0],_pre, LONGS);   
               }
        
    }        
}

void filewrite(FILE *output, item* _cur, item* _pre, int decrypt, int LONGS) {
    int i;
    char bytesa[LONGS], bytesb[LONGS];
    
    if(output != NULL) {
              
       encode(_cur,&bytesa[0], LONGS);
       if (!decrypt)  
          encode(_pre,&bytesb[0], LONGS);
          
       for(i=0; i<LONGS;i++)  {
           putc(bytesa[i],output); 
           if (!decrypt) 
               putc(bytesb[i],output); 
       }
       
    }
}
