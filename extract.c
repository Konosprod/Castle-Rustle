#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* in = fopen(argv[1], "rb+");
    FILE* out = fopen(argv[2], "wb");
    int i = 0;
    
    fseek(in, 0x02, SEEK_SET);
    
    while(!feof(in))
    {
        fread(&i, sizeof(char), 1, in);
        
        if(i)
        {
            fwrite(&i, sizeof(char), 1, out);
        }
    }
    
    return 0;

}
