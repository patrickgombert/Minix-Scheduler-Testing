#include <stdlib.h>
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

int main(int arg, char **argv) {
  int super_i = 0;
  while(super_i < 150) {
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
    super_i++;
  }
}
