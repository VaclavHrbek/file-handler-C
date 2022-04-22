#ifndef FILE_H
#define FILE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


const char* create_file(const char* name);
const char* delete_file(const char* name);
char* read_last_line_from_file(const char* name);
void add_line_to_file(const char* name, char* line);

#endif
