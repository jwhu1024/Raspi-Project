#include <stdio.h>
#include <time.h>

void get_time_to_file_name(char *szout)
{
    int hour=0, min=0, sec=0;

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    hour = timeinfo->tm_hour;
    min = timeinfo->tm_min;
    sec = timeinfo->tm_sec;

    sprintf(szout, "%d-%d-%d.jpg", hour, min, sec);
    return;
}

void main(void)
{
    char szfname[64]={0}, cmd[128]={0};

    printf("===Starting to Monitor===\n");

    while(1)
    {
        get_time_to_file_name(szfname);

        sprintf(cmd, "picasa /home/pi/projects/fswebcam/first.jpg %s", \
	szfname);

	printf("cmd - %s\n", cmd);

 	printf("===Command processing===\n");
	system(cmd); 

	memset(szfname, 0, sizeof(szfname));
	memset(cmd, 0, sizeof(cmd));
	sleep(10);
        //printf("===Command Done===\n");
    }
}
