#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int arg, char **argv) {
  long i = 0;
  while(i < 700000) {
    char* tmp1[9999];
    char* tmp2[9999];
    FILE *fp;
    fp=fopen("test1.txt", "r");
    fread(tmp1, sizeof(tmp1), sizeof(tmp1)/sizeof(char), fp);
    fclose(fp);
    fp=fopen("test2.txt", "r");
    fread(tmp2, sizeof(tmp2), sizeof(tmp2)/sizeof(char), fp);
    fclose(fp);
    fp=fopen("test2.txt", "w");
    fwrite(tmp1, sizeof(tmp1), sizeof(tmp1)/sizeof(char), fp);
    fclose(fp);
    fp=fopen("test1.txt", "w");
    fwrite(tmp2, sizeof(tmp2), sizeof(tmp2)/sizeof(char), fp);
    fclose(fp);
    i++;
  }
}
