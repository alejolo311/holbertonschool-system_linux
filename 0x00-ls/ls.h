#ifndef LS_H
#define LS_H

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char **validate_dir(int argc, char **argv);
DIR *open_dir(char *folder);
void read_dir(DIR *dir);



#endif /* LS_H */
