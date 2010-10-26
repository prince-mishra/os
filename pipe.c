#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {

int fildes[2];
const int BSIZE = 100;
char buf[BSIZE];
ssize_t nbytes;
int status;
status = pipe(fildes);
if (status == -1 ) {
    /* an error occurred */
    printf("\nERROR CREATING PIPE.");
}

switch (fork()) {
case -1: /* Handle error */
    printf("\nERROR FORKING.");
    break;


default:  /* Parent - reads from pipe */
    close(fildes[1]);                       /* Write end is unused */
    nbytes = read(fildes[0], buf, BSIZE);   /* Get data from pipe */
    /* At this point, a further read would see end of file ... */
    printf("\nREAD %d bytes. Message read is : %s",nbytes,buf);
    close(fildes[0]);                       /* Finished with pipe */
 //   exit(EXIT_SUCCESS);
 break;


case 0:  /* Child - writes to pipe */
    close(fildes[0]);                       /* Read end is unused */
    write(fildes[1], "Hello world\n", 12);  /* Write data on pipe */
    close(fildes[1]);
    printf("\nWRITTEN ON PIPE.");                       /* Child will see EOF */
    //exit(EXIT_SUCCESS);
}
return 0;
}
