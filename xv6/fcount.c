#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv)
{
  int fc = fcount();
  printf(1, "Number of files open: %d\n", fc);
  exit();
}
