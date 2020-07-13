#ifndef LS_H
#define LS_H

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

char **validate_dir(int argc, char **argv, int *ret, int *fcount);
DIR *open_dir(char *folder);
void read_dir(DIR *dir, char *folder, int argc, int *ret, char **errors);



#endif /* LS_H */
