/**
 * file:    parser_file.h
 * author:  wallying@foxmail.com
 * date:    2019-12-26
 **/


#ifndef __PARSER_FILE_H__
#define __PARSER_FILE_H__


typedef struct {
    FILE *fp;
    char name[128];
    unsigned long len;
    /* other info for file */
} fileInfo_t;


int parser_file(const char *name);


#endif /* __PARSER_FILE_H__ */

