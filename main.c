#include "dictutils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    Collection *col = initdict();
    
    addrec("key 1", "ATGCCATGACCAAGT", col);
    addrec("key 2", "\"id\":\"3ao1\"", col);
    addrec("key 3", (int*)15930240785, col);
    addrec("key 4", "landscape1.jpeg", col);
    printf("added 4 keys\n");

    printf("key 1 retrieved: %s\n", getrec("key 1", col));
    printf("key 3 retrieved: %d\n", getrec("key 3", col));

    delrec("key 2", col);
    delrec("key 4", col);
    printf("key 2 and key 4 deleted\n");

    freedict(col);
    printf("dictionary emptied\n");

    return 0;
}