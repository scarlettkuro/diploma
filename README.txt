automata.c contains second-order celullar automata (CA)

void init(); - will be deleted next time
void init(char* text);  - will be deleted next time
void fileread(int decrypt); - reads a bunch from file and fill the arrays (layers of CA) with it
void filewrite(int decrypt); - writes a bunch from arrays to file
void step(int reversible); apply local rule to each element and swip layers
void swip(); - swips layers for next step
void display(); - shows the contents of layers to console
item local(int i,int reversible); - local rule of CA (reversible shows the direction; may be deleted next time)
void reverse(); - make CA go inverse (for the dynamical decision; does not need for file I/O)
void decode(char bytes[], item* to); - bytes to bits decode
void encode(item* bits, char* to); - bytes from bits encode
void encodep(item* bits); - bytes from bits ecnode to console

LONGS - number of bytes in bunch
CONT - number of bits in bunch
longway - count of steps for CA

FILE *input; - input file
FILE *output; - output file 
    
a[CONT],b[CONT],c[CONT]; - layers

*_next - layer for writing a result of local rules
*_cur - layer from which we take information for local rule
*_pre - layer of previous step