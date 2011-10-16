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
  // real,system,user
  printf("%i,%jd,%jd\n",
        (int)(real_end - real_start),
        (intmax_t)(end_sys.tms_stime - start_sys.tms_stime),
        (intmax_t)(end_sys.tms_utime - start_sys.tms_utime));
}

void read_local(char** readIn, char* location) {
  FILE *fp;
  fp=fopen(location, "r");
  fread(readIn, sizeof(*readIn), sizeof(*readIn)/sizeof(char), fp);
  fclose(fp);
}

void write_local(char** writeOut, char* location) {
  FILE *fp;
  fp=fopen(location, "w");
  fwrite(writeOut, sizeof(*writeOut), sizeof(*writeOut)/sizeof(char), fp);
  fclose(fp);
}

int main(int arg, char **argv) {
  int i = 0;
  char* tmp1[9999];
  char* tmp2[9999];

  start_clock();

  while(i < 3500) {
    read_local(tmp1, "test1.txt");
    read_local(tmp2, "test2.txt");
    write_local(tmp1, "test2.txt");
    write_local(tmp2, "test1.txt");
    i++;
  }

  end_clock();
  print_clock_results();
  return 0;
}
