#include<stdlib.h>
#include<stdio.h>
void main(void) {
printf("Normal\n");
system("setterm -bold on");
printf("Bold text\n");
system("setterm -bold off");
 printf("\e[35m[");
 printf("\033[0;31mhello, world\033[0m\n");// color printing...
}

