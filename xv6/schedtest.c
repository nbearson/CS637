#include "types.h"
#include "stat.h"
#include "user.h"

static int pickvalue = 8;

int
main(int argc, char *argv)
{
  int pid, n;

  int values[10] = {100, 900, 200, 800, 300, 700, 400, 600, 500, 500};
 
  // Create 10 child processes
  for(n=0; n<2; n++)
  {
    pid = fork();

    if(pid == 0)
    { 
      int counter;
      while(1 == 1)
      {
        counter = counter + 1;
        counter = counter - 1;
      }
      printf(1, "Child fork completed!\n");
      exit();
    }  
    
    else if (pid != 0)
    {
      int rc = setticks(pid, values[pickvalue]);

      if(rc != 0)
       printf(1, "setticks failed with rc: %d, pid: %d, numtickets: %d\n", rc, pid, values[pickvalue]);

      pickvalue++; 
    }
  }
  
  printf(1, "Forks created.  Waiting!\n");
  wait();
  printf(1, "All forks completed.  Goodbye!\n");

  exit();
}
