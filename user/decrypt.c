#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[])
{
    int fd =0;
    uint8 key = 9;
    fd = open(argv[1], 2);
    decryptcrypt(fd, key);
    exit(0);
}