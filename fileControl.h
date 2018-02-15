#ifndef FILECONTROL_H
#define FILECONTROL_H
#include <fcntl.h> //open function
#include <sys/stat.h> //pattern opersate bitsr
#include <stdlib.h>
#include <unistd.h>
#define WRITE_FLAGS (O_WRONLY|O_CREAT|O_TRUNC)
#define WRITE_PERMS (S_IRUSR|S_IWUSR)
ssize_t r_write(int fd,void*buff,size_t size);//restart_write
ssize_t r_write(int fd,void*buff,size_t size){
	char *buffp;
	size_t bytesToWrite;
	ssize_t bytesWritten;
	size_t totalBytes;
	for(buffp=buff,bytesToWrite=size,totalBytes=0;
		bytesToWrite>0;
		buffp+=bytesWritten,bytesToWrite-=bytesWritten){
		bytesWritten=write(fd,buffp,bytesToWrite);
		if((bytesWritten==-1)&&errno!=EINTR) return 1;
		if(bytesWritten==-1)
			bytesWritten=0;
		totalBytes+=bytesWritten;
	}
	return totalBytes;
}
#endif