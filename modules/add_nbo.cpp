#include <stdio.h>
#include "add_nbo.h"

uint32_t add_nbo(uint32_t bin, uint32_t bin2){
    uint32_t localBin[4] = {
        (bin & 0xFF000000) >> 24,
        (bin & 0x00FF0000) >>  8,
        (bin & 0x0000FF00) <<  8,
        (bin & 0x000000FF) << 24
    };
    uint32_t localBin2[4] = {
        (bin2 & 0xFF000000) >> 24,
        (bin2 & 0x00FF0000) >>  8,
        (bin2 & 0x0000FF00) <<  8,
        (bin2 & 0x000000FF) << 24
    };

    uint32_t returnData  = localBin[0]  | localBin[1]  | localBin[2]  | localBin[3];
    uint32_t returnData2 = localBin2[0] | localBin2[1] | localBin2[2] | localBin2[3];
    uint32_t dataSum     = returnData + returnData2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", returnData, returnData, returnData2, returnData2, dataSum, dataSum);

    return 0;
}