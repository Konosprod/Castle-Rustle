#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* in = fopen(argv[1], "rb+");
    FILE* out = fopen(argv[2], "wb");
    int i = 0;
    int o = 0;
    int signature = 0xFFFE;
    
    fwrite(&signature, sizeof(char), 2, out);
    
    while(!feof(in))
    {
        fread(&i, sizeof(char), 1, in);
        fwrite(&i, sizeof(char), 1, out);
        fwrite(&o, sizeof(char), 1, out);
    }
    
    return 0;

}
