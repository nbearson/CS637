#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv)
{
  int pid, n;
  
  // Create 5 child processes
  for(n=0; n<5; n++)
  {
    pid = fork();
    if(pid == 0)
      break;
  }
  
  // Child processes will count to 10000 while the parent waits
  if(pid==0)
  {
    for(n=0; n<10000; n++)
    {
      continue;
    }
  }
  else
  {
    wait();
  }

  return 0;
}
