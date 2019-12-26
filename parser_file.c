/**
 * file:    parser_file.c
 * author:  wallying@foxmail.com
 * date:    2019-12-26
 **/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "parser_file.h"


#define LINE_STR_NUM_MAX (1024)


int parser_file(const char *name)
{
    fileInfo_t srcFile = {0x00};
    char label = '\0';
    char lineStr[LINE_STR_NUM_MAX] = {0x00};
    unsigned int lineNum = 0;
    unsigned int lineLen = 0;
    char keyBuf[LINE_STR_NUM_MAX] = {0x00};

    memset(&srcFile, 0x00, sizeof(srcFile));

    /*========================================================================*/
    strncpy(srcFile.name, name, sizeof(srcFile.name));
    if ((srcFile.fp = fopen(srcFile.name, "r")) == NULL) {
        printf(" ERROR: no \"%s\" file!!!\n", srcFile.name);
        return -1;
    }

    fseek(srcFile.fp, 0L, SEEK_END);
    srcFile.len = ftell(srcFile.fp);
    fseek(srcFile.fp, 0L, SEEK_SET);

    lineNum = 0;
    while (fgets(lineStr, sizeof(lineStr), srcFile.fp) != NULL) {
        ++lineNum;
        lineLen = strlen(lineStr);
        if (lineStr[lineLen-1] != '\n' && !feof(srcFile.fp)) {
            printf(" ERROR: file:%s line:%d too long!!!\n", srcFile.name, lineNum);
        }

        sscanf(lineStr, "%*[ \t\n]%s", keyBuf);

        switch (label) {
        case ' ':
        case '\t':
        case '\n':
            break;

        case ';': /* comment */
        case '#': /* comment */
        default:
            printf("%s", lineStr);
            break;
        }
    }

    fclose(srcFile.fp);

    /*========================================================================*/
    printf("\n srcFile => \"%s\" %.2fKB(%ld-byte)\n",
           srcFile.name, srcFile.len / 1024.0, srcFile.len);

   return 0;
}


void strtrim(char *str)
{
    char *ptr = str;

    if (isspace(*ptr)) {

    }
}