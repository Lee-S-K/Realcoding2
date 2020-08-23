#include <stdio.h>
#include "func.h"

int func_name_or_id(){
#ifdef PRINT_ID
	printf("201723267\n");
	return 0;

#else 
	printf("LEESANGKYEONG\n");
	return 1;
#endif
}

