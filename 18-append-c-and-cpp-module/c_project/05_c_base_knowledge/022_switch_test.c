#include <stdio.h>
int main(void)
{
    int num     = 0;
	switch(0/*lcdc->data_width*/){
		case 0:
		num     = 24;
		break;
		case 1:
		num     = 18;
		break;
		case 2:
		num     = 16;
		break;
	}

	printf("num=%d\n",num);
    return 0;
}
