// Create a zombie process that 
// must be reparented at exit.

#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int *x = (int*)malloc(700);
  int counter = 0;
  int pid = thread();

  if(pid > 0)
  {
    while(1==1)
    {
      *x = *x + 1;  
      printf(1, "x = %d, pid = %d, counter = %d\n", *x, pid, counter);
      counter++;
    }
    wait();
  } 
  else
  {
    while(1==1)
    {
      *x = *x - 1;
      printf(1, "x = %d, pid = %d, counter = %d\n", *x, pid, counter);
      counter++;
    }
  }
  exit();
}
