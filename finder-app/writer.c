#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd;
    int nr;

    openlog(NULL, LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Must specify both writefile and writestr on the command line");

        return 1;
    }

    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);

    if (fd == -1) {
        syslog(LOG_ERR, "Unable to open file %s error %s", argv[1], strerror(errno));

        return 1;
    }

    
    nr = write(fd, argv[2], strlen(argv[2]));

    if (nr == -1) {
        syslog(LOG_ERR, "Error in writing to file %s error %s", argv[1], strerror(errno));

        return 1;
    }

    syslog(LOG_DEBUG, "Successfuly wrote string %s to file %s", argv[2], argv[1]);

    close(fd);

    return 0;
}
