#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[]) {
  int pid;
  int fds[2];
  char buf[512];

  // Create pipe descriptors
  pipe(fds);

  pid = fork();
  if (pid == 0) {
    printf("%d: received ping\n", getpid());
    write(fds[1], "this is pipe2\n", 14);
  } else {
    read(fds[0], buf, sizeof(buf));
    printf("%d: received pong\n", getpid());
  }

  exit(0);
}
