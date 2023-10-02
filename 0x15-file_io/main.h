#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <fcntl.h> /* For open function */
#include <unistd.h> /* For read, write, close functions */
#include <stdio.h> /* For perror */

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
