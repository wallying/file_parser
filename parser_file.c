/**
 * file:    parser_file.c
 * author:  wallying@foxmail.com
 * date:    2019-12-27
 **/


#include <stdio.h>
#include <string.h>
#include "parser_file.h"


#define LINE_STR_NUM_MAX (1024)


#define isspace(c) \
    (((c) == ' ')  || ((c) == '\n') || ((c) == '\t') || \
     ((c) == '\r') || ((c) == '\f') || ((c) == '\v'))

static char *str_trim(char *str)
{
    char *ptr = str;
    char *end = str;

    while ((isspace(*ptr))) {
        ++ptr;
    }

    if (ptr == str) {
        for (; *end; ++end);
    } else {
        for (; (*end = *ptr); ++end, ++ptr);
    }

    do {
        --end;
    } while ((end >= str) && (isspace(*end)));
    *(end + 1) = '\0';

    return str;
}


int parser_line(char *str, lineInfo_t *line)
{
//    if ((lineStr[0] == ';') || (lineStr[0] == '#')) {
//        /* comment */
//        sscanf(lineStr, "[%[^]]", secBuf);
//    } else if ((lineStr[0] == '[') && (lineStr[lineLen-1] == ']')) {
//        /* section */
//        printf("%s", lineStr);
//    }
    return 0;
}


int parser_file(const char *name, fileInfo_t *file)
{
    lineInfo_t oneLine = {0x00};
    char lineStr[LINE_STR_NUM_MAX] = {0x00};
    unsigned int lineLen = 0;

    /*========================================================================*/
    strncpy(file->name, name, sizeof(file->name));
    if ((file->fp = fopen(file->name, "r")) == NULL) {
        printf(" ERROR: no \"%s\" file!!!\n", file->name);
        return -1;
    }

    fseek(file->fp, 0L, SEEK_END);
    file->len = ftell(file->fp);
    fseek(file->fp, 0L, SEEK_SET);

    file->line = 0;
    while (fgets(lineStr, sizeof(lineStr), file->fp) != NULL) {
        ++file->line;
        lineLen = strlen(lineStr);
        if (lineStr[lineLen-1] != '\n' && !feof(file->fp)) {
            printf(" ERROR: file:%s line:%d too long!!!\n", file->name, file->line);
        }

        str_trim(lineStr);
        lineLen = strlen(lineStr);

        parser_line(lineStr, &oneLine);
        printf("[%s:%s=%s]\n", oneLine.sec, oneLine.key, oneLine.val);
    }

    fclose(file->fp);

    return 0;
}


