#include <stdio.h>
#include <stdint.h>
#include "add_nbo.h"

#define ALLOWED_INPUT_PARAM 3

int main(int argc, char* argv[]){
    FILE *fp, *fp2;
    fp  = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");

    uint32_t bin;
    uint32_t bin2;

    fread(&bin, sizeof(uint32_t), 1, fp);
    fread(&bin2, sizeof(uint32_t), 1, fp2);

    add_nbo(bin, bin2);

    fclose(fp);
    fclose(fp2);

    return 0;
}