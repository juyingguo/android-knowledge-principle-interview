

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
 int i;
 for (i = 0; i < len; i++)
 printf(" %.2x", start[i]);
 printf("\n");
 }

 void show_int(int x) {
 show_bytes((byte_pointer) &x, sizeof(int));
 }

 void show_float(float x) {
 show_bytes((byte_pointer) &x, sizeof(float));
 }
 void show_pointer(void *x) {
 show_bytes((byte_pointer) &x, sizeof(void *));
 }
 int main(){
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp, 1); /* A. */
    show_bytes(valp, 2); /* B. */
    show_bytes(valp, 3); /* C. */

    getchar();
    return 0;
 }
