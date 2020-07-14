#ifndef LS_H
#define LS_H

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <time.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <grp.h>

/* lib */
char *validate_args(char **argv);
char **validate_dir(int argc, char **argv, int *ret, int *fcount);
DIR *open_dir(char *folder);
char **read_dir(DIR *dir, char *folder, int *ret, char **errors);
int print_dir(char **files, char *args, char *folder);

/* utils */
bool include(char *valid, char arg);
char *permissions(struct stat file);
char *get_date(struct stat file);
int get_nodes(char **files, char *folder);


/* flags */

void flag_l(char **files, char *folder);
void flag_1(char **files, char *folder);
void flag_a(char **files, char *folder);
void flag_A(char **files, char *folder);
void without_flags(char **files, char *folder);

#endif /* LS_H */
