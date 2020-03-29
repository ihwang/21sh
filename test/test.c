#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		main(void)
{
	int fd = open(ttyname(1), O_RDWR);
	char buf[6000];
	read(fd, buf, sizeof(buf));
	printf("%s\n", ttyname(1));


	return (0);
}
