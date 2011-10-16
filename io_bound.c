#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void read_local(char** readIn, char* location) {
  FILE *fp;
  fp=fopen(location, "r");
  fread(readIn, sizeof(readIn), sizeof(readIn)/sizeof(char), fp);
  fclose(fp);
}

void write_local(char** writeOut, char* location) {
  FILE *fp;
  fp=fopen(location, "w");
  fwrite(writeOut, sizeof(writeOut), sizeof(writeOut)/sizeof(char), fp);
  fclose(fp);
}

int main(int arg, char **argv) {
  int i = 0;
  while(i < 14000) {
    char* tmp1[9999];
    char* tmp2[9999];
    read_local(tmp1, "test1.txt");
    read_local(tmp2, "test2.txt");
    write_local(tmp1, "test2.txt");
    write_local(tmp2, "test1.txt");
    i++;
  }
  return 0;
}
