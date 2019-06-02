#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
void foo();
int main() {
   struct timespec clava_timing_start_0, clava_timing_end_0;
   clock_gettime(CLOCK_MONOTONIC, &clava_timing_start_0);
   #pragma monitor start
   foo();
   #pragma monitor stop
   clock_gettime(CLOCK_MONOTONIC, &clava_timing_end_0);
   double clava_timing_duration_0 = ((clava_timing_end_0.tv_sec + ((double) clava_timing_end_0.tv_nsec / 1000000000)) - (clava_timing_start_0.tv_sec + ((double) clava_timing_start_0.tv_nsec / 1000000000))) * (1000000000);
   printf("time:%f\n", clava_timing_duration_0);
   
   return 10;
}
