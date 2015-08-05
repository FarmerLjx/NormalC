
#ifndef __CREATE_TEMP_FILE_H__
#define __CREATE_TEMP_FILE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void doGenerateTempFile(char *szFileName, char *szBuffer);
void GenerateRandomFileName(char *szFileName);
void doDeleteTempFile(char *wzFileName);

#endif  //!__CREATE_TEMP_FILE_H__