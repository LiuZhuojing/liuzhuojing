#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
    int fd = -1;
    int ret = -1;
    int size = -1;
    char read_buf[1024] = {0};
    char write_buf[32] = "hello world";

    
    printf("READ\n");
    fd = open("lseek_test", O_RDWR | O_APPEND);
    if (fd == -1)
    {
        printf("open failed\n");
        exit(1);
    }

    ret = lseek(fd, 0, SEEK_SET);
    if (ret == -1)
    {
        printf("lseek function failed.\n");
        close(fd);
        exit(1);
    }
    printf("After lseek position is:%d\n", ret);

    
    size = read(fd, read_buf, sizeof(read_buf));
    if (size == -1)
    {
        printf("read failed\n");
        close(fd);
         exit(1);

    }
    printf("read number of character == %d\n", size);
    printf("read_buf:%s\n", read_buf);
    close(fd);


    
    printf("WRITE\n");
    fd = open("lseek_test", O_RDWR | O_APPEND);
    if (fd == -1)
    {
        printf("open failed\n");
    	exit(1);     
    }

    ret = lseek(fd, 0, SEEK_SET);
    if (ret == -1)
    {
        printf("lseek failed.\n");
        close(fd);
        exit(1);
    }
    printf("After lseek position is:%d\n", ret);

    
    size = write(fd, write_buf, strlen(write_buf));
    if (size == -1)
    {
        printf("write failed\n");
        close(fd);
        exit(1);

    }
    printf("write number of character == %d\n", size);
    close(fd);
    return 0;
}


