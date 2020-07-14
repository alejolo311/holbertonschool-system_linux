#ifndef LS_H
#define LS_H

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>


/* lib */
char *validate_args(char **argv);
char **validate_dir(int argc, char **argv, int *ret, int *fcount);
DIR *open_dir(char *folder);
char **read_dir(DIR *dir, char *folder, int *ret, char **errors);
int print_dir(char **files, char *args);

/* utils */
bool include(char *valid, char arg);

#endif /* LS_H */
