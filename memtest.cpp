#include <iostream>
#include <stdio.h>
#include <unistd.h>

#define VMRSS_LINE 17

#define pid_t int 


int get_phy_mem(const pid_t p)
{
	char file[64] = {0};
	FILE *fd;
	char buf[256] = {0};
	sprintf(file, "/proc/%d/status", p);
	fprintf(stderr, "current pid is : %d\n", p);
	fd = fopen(file, "r");

	int i;
	char name[64];
	int vmrss;
	for(int i=0; i<VMRSS_LINE-1; i++)
	{
		char *ret = fgets(buf, sizeof(buf), fd);
	}
	char *ret1 = fgets(buf, sizeof(buf), fd);
	sscanf(buf, "%s %d", name, &vmrss);
	fprintf(stdout, "===%s : %d====\n", name, vmrss);
	fclose(fd);
	return vmrss;
}	

int main()
{
	int mem = get_phy_mem(getpid());
	return 0;
}
