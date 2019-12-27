/**
 * file:    parser_file.h
 * author:  wallying@foxmail.com
 * date:    2019-12-27
 **/


#ifndef __PARSER_FILE_H__
#define __PARSER_FILE_H__


typedef struct {
    FILE *fp;
    char name[128];
    unsigned int line;
    unsigned long len;
    /* other info for file */
} fileInfo_t;

typedef struct {
    char sec[128];
    char key[128];
    char val[128];
    /* other info for line */
} lineInfo_t;


int parser_file(const char *name, fileInfo_t *file);
int parser_line(char *str, lineInfo_t *line);

#endif /* __PARSER_FILE_H__ */

