#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/times.h>

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
  printf("Mixed Process:\nReal: %jd\nSystem: %jd\nUser: %jd\n",
        (real_end - real_start),
        (end_sys.tms_stime - start_sys.tms_stime),
        (end_sys.tms_utime - start_sys.tms_utime));
}

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
  char* tmp1[9999];
  char* tmp2[9999];

  start_clock();

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
      while(i < 3500) {
          read_local(tmp1, "test1.txt");
          read_local(tmp2, "test2.txt");
          write_local(tmp1, "test2.txt");
          write_local(tmp2, "test1.txt");
          i++;
        }
    }
    super_i++;
  }

  end_clock();
  print_clock_results();
  return 0;
}
