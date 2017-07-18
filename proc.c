#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
{
    printf("mem:%d,%d%% ",(int)(100*(atoi(argv[2])-atoi(argv[8]))/atoi(argv[2])),(int)(1000*(atoi(argv[2])-atoi(argv[8]))/atoi(argv[2]))-10*(int)(100*(atoi(argv[2])-atoi(argv[8]))/atoi(argv[2])));
    if(atoi(argv[14])>0)printf("swap:%d,%d%% | ",(int)(100*(atoi(argv[14])-atoi(argv[17]))/atoi(argv[14])),(int)(1000*(atoi(argv[14])-atoi(argv[17]))/atoi(argv[14]))-10*(int)(100*(atoi(argv[14])-atoi(argv[17]))/atoi(argv[14])));
}
{
	int k=0,freq=0;
	for(int i=22;i<argc;i=i+4)
	{
		k+=1;
		freq+=atoi(argv[i]);
	}
	freq=(int)freq/k;
	printf("cpu freq:%d MHz | loadavg: ",freq);
}
{
FILE *stat=fopen("/proc/loadavg","r");
float d;
for(int i=0;i<3;i+=1)
{
fscanf(stat,"%f",&d);
printf("%.2f ",d);
}
fclose(stat);
}
return 0;
}
