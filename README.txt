run parametrs: input_name [-e/-d] output_name password
input_name - input file
-e - encrypt input_name to output_name
-d - decrypt input_name to output_name
output_name - output file 

automata.c contains second-order celullar automata (CA)

void step(); - apply local rule to each element and swip layers
void block(); - proccess a single block
void swip(); - swips layers for next step
void display(); - shows the contents of layers to console
item local(int i); - local rule of CA 

_file.c contains procedures for reading/writing files

void fileread(FILE *input, item* _cur, item* _pre, int decrypt, int LONGS) ; - read a block from file 
void filewrite(FILE *output, item* _cur, item* _pre, int decrypt, int LONGS); - writes a block to file
(_cur, _pre - current and pre-current layers of automata, LONGS - size of the block)

_code.c contains procedures for bit/byte encode/decode
void decode(char bytes[], item* to, int LONGS); - bytes to bits decode
void encode(item* bits, char* to, int LONGS); - bytes from bits encode
void encodep(item* bits, int LONGS); - bytes from bits ecnode to console
(LONGS - size of the block)

um.c must serve for initialization purposes
contains item definition for now

LONGS - number of bytes in block
CONT - number of bits in block
longway - count of steps for CA

FILE *input; - input file
FILE *output; - output file 
    
a[CONT],b[CONT],c[CONT]; - layers

*_next - layer for writing a result of local rules
*_cur - layer from which we take information for local rule
*_pre - layer of previous step