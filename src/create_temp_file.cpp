
#include "create_temp_file.h"

void doGenerateTempFile(char *szFileName, char *szBuffer)
{
    FILE *fp;

    GenerateRandomFileName(szFileName);
    
    if(NULL == (fp=fopen(szFileName,"w+")))
    {
        //printf("can't create a temp file\n");
        fclose(fp);
        exit(1);
    }
    fprintf(fp,"%s", szBuffer);
    fclose(fp);
}

void GenerateRandomFileName(char *szFileName)
{
    time_t tCurrentTime;
    struct tm *TimeInfo;

    time(&tCurrentTime);
    TimeInfo = localtime(&tCurrentTime);
    srand((unsigned) time(NULL));

    sprintf(szFileName, "%%T%%M%%E%%P%04x%02x%02x%02x%02x%04x.html", 
        (TimeInfo->tm_year + 1900), 
        (TimeInfo->tm_mon + 1), 
        TimeInfo->tm_mday, 
        TimeInfo->tm_hour, 
        TimeInfo->tm_min, 
        (rand()%10000));

    return ;
}

void doDeleteTempFile(char *wzFileName)
{
    //DeleteFile(wzFileName);
    remove(wzFileName);
    return ;
}