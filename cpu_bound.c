#include <stdlib.h>
#include <string.h>

static time_t real_start;
static time_t real_end;

static struct tms start_sys;
static struct tms end_sys;
static clock_t start;
static clock_t end;

void start_clock() {
  time(&real_start);
  start = times(&start_sys);
}

void end_clock() {
  time(&real_end);
  end = times(&end_sys);
}

void print_clock_results() {
  printf("CPU Process:\nReal: %jd\nSystem: %jd\nUser: %jd\n",
        (real_end - real_start),
        (end_sys.tms_stime - start_sys.tms_stime),
        (end_sys.tms_utime - start_sys.tms_utime));
}

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

  start_clock();

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

  end_clock();
  print_clock_results();
  return 0;
}
