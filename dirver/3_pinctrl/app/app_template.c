#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


static void on_off_led(int fd, char *string)
{
	printf("sdf\n");
	int status;

	/* 3. 写文件 */
	if (0 == strcmp(string, "on"))
	{
		status = 0;
	}
	else
	{
		status = 1;
	}
	printf("user--->wite: %d\n", status);
	write(fd, &status, sizeof(status));
}

static void delay_ms(int milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}

/*
 * ./ledtest /dev/100ask_led0 on
 * ./ledtest /dev/100ask_led0 off
 */
int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		printf("can not open file %s\n", argv[1]);
		return -1;
	}

	if (argc != 3) 
	{
		printf("blink led...");
		int cnt = 10;
		while (cnt--) {
			on_off_led(fd, "on");
			delay_ms(100);
			on_off_led(fd, "off");
			delay_ms(100);
		}
	} else {
		on_off_led(fd, argv[2]);
	}
	
	close(fd);
	
	return 0;
}


