#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_palindrome(int subject) {
  char str[6];
  sprintf(str, "%d", subject);
  int len = strlen(str);
  int i = 0;
  while(i < len/2) {
    if (str[i] != str[len - i - 1]){
      return 1;
    }
    i++;
  }
  return 0;
}

int main(int args, char** argv) {
  int super_i = 0;
  while(super_i < 4) {
    if(super_i % 2 == 0) {
      int super_j = 0;
      while(super_j < 37) {
          int i = 100;
          int j = 100;
          int largest_i = 0;
          int largest_j = 0;
          int largest = 0;
          while(i <= 999) {
            while(j <= 999) {
              j++;
              int tmp = i * j;
              if(is_palindrome(tmp) == 0 && tmp > largest) {
                largest_i = i;
                largest_j = j;
                largest = tmp;
              }
            }
            i++;
            j = 100;
          }
          super_j++;
        }
    } else {
      long i = 0;
      while(i < 175000) {
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
    super_i++;
  }
  return 0;
}
