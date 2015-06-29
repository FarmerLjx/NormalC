#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void GenerateRandomFileName(char *szFileName);
void WriteToFile(char *szFileName, char *szBuffer);

int main(void)
{
    char szSysTempPath[256];
    char *pszSysTempPath;
    char szFileName[256];
    int  iLen;
    char szBuffer[1024] = "<html>\n<head>\n<title>Sample HTML Resource (UNICODE)</title>\n<body background=\"./bitmap.bmp\" body oncontextmenu=self.event.returnValue=false onselectstart=\"return false\">\n<p align=\"center\"><font color=\"#FFFFFF\">This is a sample HTML resource.</font></p>\n<p>The background image is a bitmap that is another resource in the .EXE.</p>\n<p>The resource is a UNICODE-encoded HTML document.</p>\n</html>";

    pszSysTempPath = getenv("TEMP");
    WriteToFile(szFileName, szBuffer);
    sprintf(szSysTempPath, "%s", pszSysTempPath);
    iLen = strlen(szSysTempPath);
    if(szSysTempPath[iLen] != '\\'){
        szSysTempPath[iLen] = '\\';
        szSysTempPath[iLen + 1] = '\0';
    }
    printf("%s---%s\n", szSysTempPath, pszSysTempPath);
    getchar();

    remove(szFileName);
    return 0;
}

void WriteToFile(char *szFileName, char *szBuffer)
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