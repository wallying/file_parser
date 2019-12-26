/**
 * file:    main.c
 * author:  wallying@foxmail.com
 * date:    2019-12-26
 **/


#include <stdio.h>
#include "parser_file.h"


int main(int argc, char *argv[])
{
    int status = 0;

    status = parser_file((argc < 2) ? "config.ini" : argv[1]);

    getchar();
    return status;
}

