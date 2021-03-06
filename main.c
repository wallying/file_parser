/**
 * file:    main.c
 * author:  wallying@foxmail.com
 * date:    2019-12-30
 **/


#include <stdio.h>
#include "parser_file.h"


int main(int argc, char *argv[])
{
    int status = 0;
    fileInfo_t srcFile = {0x00};

    status = parser_file("config.ini", &srcFile);

    printf("\n srcFile => \"%s\" %.2fKB(%ld-byte)\n",
           srcFile.name, srcFile.len / 1024.0, srcFile.len);

    getchar();
    return status;
}

