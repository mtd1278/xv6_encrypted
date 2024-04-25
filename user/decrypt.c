#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[])
{
    uint8 key = 9;
    int fd = open(argv[1], 2);
    decrypt(fd, key);
    struct stat status;
    fstat(fd, &status);
    printf("encryptStat = %d\n", status.encryptStat);
    exit(0);
}