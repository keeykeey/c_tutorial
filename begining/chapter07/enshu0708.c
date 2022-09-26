#include <stdio.h>

int main(void) {
   float f = 1.11;
   double d = 2.22;
   long double ld = 3.33;

   int intf,intd,intld;
   intf = sizeof(f);
   intd = sizeof(d);
   intld = sizeof(ld);

   printf("size\n");
   printf("float : %d\n",intf);
   printf("double : %d\n",intd);
   printf("long double : %d\n",intld);

   return 0;
}