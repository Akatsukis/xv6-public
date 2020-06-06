#include "types.h"
#include "stat.h"
#include "user.h"
int player;
int pass;
int round;
lock_t lk;

void frisbee(void* arg) {
  int id = *(int*)arg;
  while(round < pass) {
    if(round%player == id) {
      lock_acquire(&lk); 
      round++;
      int nid = (id+1)%player;
      printf(1, "Pass number no: %d, Thread %d is passing the token to thread %d\n", round, id, nid);
      lock_release(&lk);
    }
    sleep(10);
  }
  exit();
}

int 
main(int argc, char *argv[]) 
{
  if(argc != 3) {
    printf(1, "Usage: frisbee <num_players> <num_passes>\n");
    exit();
  }
  player = atoi(argv[1]);
  pass = atoi(argv[2]);
  lock_init(&lk);
  int i;
  for(i = 0; i < player; i++) {
    int curid = i;
    thread_create((void*)frisbee, (void*)&curid);
    sleep(10);
  }
  for(int i = 0; i < player; i++) {
    wait();
  }
  printf(1, "Simulation of Frisbee game has finished, %d rounds were played in total\n", round);
  exit(); 
}
