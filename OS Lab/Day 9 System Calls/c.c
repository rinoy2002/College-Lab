#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
void main() {
  printf("Parent A: %d\n", getpid());
  if (fork() == 0) {
     printf(" Child B: %d forked by Parent A: %d\n", getpid(), getppid());
     if (fork() == 0) {
         printf(" Child D: %d forked by Parent B: %d\n", getpid(), getppid());
         if (fork() == 0) {
             printf(" Child H: %d forked by Parent D: %d\n", getpid(), getppid());
             if (fork() == 0) {
                 printf(" Child I: %d forked by Parent H: %d\n", getpid(), getppid());
             }else{
              wait(NULL);
             }
         }else{
             wait(NULL);
         }
     }else if (fork() == 0) {
         printf(" Child E: %d forked by Parent B: %d\n", getpid(), getppid());
     }else if (fork() == 0) {
         printf(" Child F: %d forked by Parent B: %d\n", getpid(), getppid());
     }else{
         wait(NULL);
     }
  }else if (fork() == 0) {
     printf(" Child C: %d forked by Parent A: %d\n", getpid(), getppid());
     if (fork() == 0) {
        printf(" Child G: %d forked by Parent C: %d\n", getpid(), getppid());
     }else{
        wait(NULL);
     }
  }else{
     wait(NULL);
  }
}