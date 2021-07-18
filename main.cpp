#include <stdio.h>
#include <stdint.h>
#include "modules/add_nbo.h"

#define ALLOWED_INPUT_PARAM 3

int main(int argc, char* argv[]){
    if(argc != ALLOWED_INPUT_PARAM){
        bool isMore = (argc > ALLOWED_INPUT_PARAM);
        int diffCount = (isMore) ? argc - ALLOWED_INPUT_PARAM : ALLOWED_INPUT_PARAM - argc;
        printf("[ERR] File entered %d %s than allowed\nPlease check input again.", diffCount, (isMore)?"more":"less");
        return 1;
    }

    FILE *fp, *fp2;
    fp  = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");

    uint32_t bin, bin2;

    fread(&bin, sizeof(uint32_t), 1, fp);
    fread(&bin2, sizeof(uint32_t), 1, fp2);

    add_nbo(bin, bin2);

    fclose(fp);
    fclose(fp2);

    return 0;
}