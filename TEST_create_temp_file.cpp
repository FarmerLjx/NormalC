#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string.h>

#include "create_temp_file.h"

int main(void)
{
    char szSysTempPath[256];
    char *pszSysTempPath;
    char szFileName[256];
    int  iLen;
    char szBuffer[1024] = "<html>\n<head>\n<title>Sample HTML Resource (UNICODE)</title>\n<body background=\"./bitmap.bmp\" body oncontextmenu=self.event.returnValue=false onselectstart=\"return false\">\n<p align=\"center\"><font color=\"#FFFFFF\">This is a sample HTML resource.</font></p>\n<p>The background image is a bitmap that is another resource in the .EXE.</p>\n<p>The resource is a UNICODE-encoded HTML document.</p>\n</html>";

    pszSysTempPath = getenv("TEMP");
    doGenerateTempFile(szFileName, szBuffer);
    sprintf(szSysTempPath, "%s", pszSysTempPath);
    iLen = strlen(szSysTempPath);
    if(szSysTempPath[iLen] != '\\'){
        szSysTempPath[iLen] = '\\';
        szSysTempPath[iLen + 1] = '\0';
    }
    printf("%s---%s\n", szSysTempPath, pszSysTempPath);
    getchar();

    doDeleteTempFile(szFileName);
    return 0;
}
