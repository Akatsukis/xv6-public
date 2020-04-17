#include "types.h"
#include "stat.h"
#include "user.h"

int 
main(int argc, char *argv[]) 
{
  if (argc != 2) {
    printf(1,
           "Usage: info {1|2|3}\n"
           "1: A count of the processes in the system;\n"
           "2: A count of the total number of system calls that the current "
           "process has made so far;\n"
           "3:The number of memory pages the current process is using.\n");
    exit();
  } else {
    int type = atoi(argv[1]);
    if (type < 1 || type > 3) {
      printf(1,
             "Usage: info {1|2|3}\n"
             "1: A count of the processes in the system;\n"
             "2: A count of the total number of system calls that the current "
             "process has made so far;\n"
             "3:The number of memory pages the current process is using.\n");
      exit();
    }
    printf(1, "%d\n", info(atoi(argv[1])));
    exit();
  }
}
