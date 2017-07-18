#include <stdlib.h>
#include <stdio.h>
void main(int argc, char *argv[])
{
unsigned int a,b;
FILE *f1=fopen("/sys/class/power_supply/BAT0/energy_now","r"),*f2=fopen("/sys/class/power_supply/BAT0/energy_full","r");
fscanf(f1,"%u",&a);
fscanf(f2,"%u",&b);
if(argc==1)printf("%s%u\n","Текущий заряд батереи: ",100*a/b);
else printf("%s%u\n","Батерея: ",100*a/b);
}
