#include "stdio.h"
#include <memory.h>
#include "my_string.h"

void my_string(int type, char *buf){
    char buf0[] = "(^O^) < Hello";
    char buf1[] = "(T_T) < goodby";
    char buf99[] = "(・v・) < seeyou";

    //printf("type=%d\n", type);

    if (type == 0) {
        //buf = "";
        memcpy(buf,buf0,sizeof(buf0));
    } else if (type == 1) {
        memcpy(buf,buf1,sizeof(buf1));
    } else {
        memcpy(buf,buf99,sizeof(buf99));
    }

    //printf("buf==%s\n", buf);
    
}
