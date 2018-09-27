#include "stdio.h"
#include <math.h>
#include "my_math.h"

int my_math(long val){
    long ret_val = 0;

    if (val == 0){
        ret_val = 1;
    } else if (val <= 0){
        ret_val = -1;
    } else if (val > 10){
        ret_val = -100;
    } else {
        ret_val = pow(2, val);
    }
    return ret_val;
}
