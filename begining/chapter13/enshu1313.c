#include <stdio.h>
#include <ctype.h>
#define MSIZE 1

int main(void)
{
    int n;
    FILE *sfp, *dfp;
    unsigned char buf[16];

    if ((sfp = fopen("sfile13","rb")) == NULL){
        printf("sfile13を開けませんでした。\n");
    } else {
        if ((dfp = fopen("dfile13","wb")) == NULL) {
            printf("dfile13を開けませんでした。\n");
        } else {
            while ((n = fread(buf,1,MSIZE,sfp)) > 0) {
                int i;
                for (i=0; i<MSIZE; i++){
                    printf("%c",buf[i]);
                    fwrite(&buf,sizeof(unsigned char),MSIZE,dfp);
                }                
            }
            putchar('\n');            
            fclose(dfp);
        }
        fclose(sfp);
    }
    return 0;
}