#ifndef LS_H
#define LS_H

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


DIR *open_dir(int argc, char **argv);
void read_dir(DIR *dir);



#endif /* LS_H */
