#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

//TODO - There are a bunch of errors in this program.

// A statically allocated, pre-initialized variable 
int globalVariable= 7;

// A recursive function 
int recursiveFunction(int i) {
  // A stack allocated variable within a recursive function 
  int j = i;//DO NOT MODIFY

  // TODO 1: Fix this so it prints the address of j 
  printf("recursive call %d: stack variable is at: %p\n", i, &j);

  if (i < 10 && i > 0) {
    return recursiveFunction(i - 1);//DO NOT MODIFY
  }

  return 0;//DO NOT MODIFY
}

int main(int argc, char *argv[]) {
  int i;

  // Dynamicly allocated arrays
  char characterArray1 = malloc(100);
  char characterArray2 = malloc(100);

  // TODO 2: Print the addresses of the main function 'main()'
  printf("main function address: %p\n", main);

  // TODO 3: Print the addresses of the recursive function 'recursiveFunction()'
  printf("recursive function address: %p\n", recursiveFunction);

  // TODO 4: Print the address of the stack allocated variable 'i'
  printf("address of variable i (main stack address): %p\n", &i);

  // TODO 5: Print the address of the statically allocated global variable 'globalVariable'
  printf("static data address: %p\n", &globalVariable);

  // TODO 6: Print the addresses of the Dynamically allocated arrays
  printf("Heap malloc 1: %p\n", &characterArray1);
  printf("Heap malloc 2: %p\n", &characterArray2);


  recursiveFunction(3);//DO NOT MODIFY

  struct rlimit lim;

  //TODO 7: Print the stack size limits
    getrlimit(RLIMIT_STACK, &lim);
  printf("stack size  (soft limit): %ld\n", lim);

  //TODO 8: Print the maximum number of processes/threads that you can spawn limits
    getrlimit(RLIMIT_CPU, &lim);
  printf("process limit  (soft limit): %ld\n", lim);
    getrlimit(RLIMIT_CORE, &lim);
  printf("process limit  (hard limit): %ld\n", lim);

  //TODO 9: Print the maximum number of number of file descriptors that this process may allocate
    getrlimit(RLIMIT_FSIZE, &lim);
  printf("max file descriptors  (soft limit): %ld\n", lim);
  printf("max file descriptors  (hard limit): %ld\n", lim);
  return 0;
}
