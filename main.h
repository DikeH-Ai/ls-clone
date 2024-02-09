#ifndef MAIN_H
#define MAIN_H

/*Header FILES*/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// GET WORKING DIRECTORY
char* get_cwd();

// LIST DIRECTORY CONTENTS
int ls_cwd(char* directory);

/* 
FUNCTION HANDLES POSSIBLE OUTCOMES
with -flag
with -flag and argument 
with -argument 
*/
int ls_dir(int argc, char* argv[]);

// PRINT PERMISSION FUNCTION
void permission(mode_t mode);

// CONVERT USER ID TO NAMES
char* get_usrid(struct stat filestat);

// CONVERT GROUP ID TO  GROUP NAME 
char* get_grpid(struct stat filestat);

// CONVERT EPOCH UNIX TIME TO STD TIME
char* get_mtime(struct stat filestat);

// ls FLAGS
int ls_a(char* directory);
int ls_d(char* directory);
int ls_al(char* directory);
int ls_l(char* directory);

#endif /*MAIN_H*/
