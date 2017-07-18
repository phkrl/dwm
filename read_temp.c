#include <stdio.h>
#include <stdlib.h>

int main(void)
{
for (short i=0;i<8;i++)
    {
        char *add;
        add=(char *)malloc(30*sizeof(char));
        sprintf(add,"/sys/class/thermal/thermal_zone%d/temp",i);
        FILE *f=fopen(add,"r");
        int t;
        fscanf(f,"%d",&t);
        printf("%d,",(int)(t/1000));
        printf("%d ",(int)(t/100)-10*(int)(t/1000));
        fclose(f);
        free(add);
    }
return 0;
}
