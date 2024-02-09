#include "main.h"


/*
    ls_cwd; function to list directory content
    passsed as an argument.
    directory: to be read.
*/
int ls_cwd(char* directory){
    /*
        folder: DIR stream
        dir_struct: readdir return value
    */
    //open directory
    DIR* folder;
    folder = opendir(directory);
    if (folder == NULL)
    {
        perror("Failed to open directory");
        exit(1);
    }
    
    //read directory contents
    struct dirent* dir_stuct;
    while ((dir_stuct = readdir(folder)))
    {
        if (dir_stuct->d_name[0] != '.')
        {
            /* code */
            printf("%-10s",dir_stuct->d_name);
        }
        
    }
    //close folder
    closedir(folder);
    return (0);
}


/*
    Get current working directory function
*/
char* get_cwd(){
    /*
        Get the cwd using the getcwd function
        cwd: current working directory buffer 
    */
    char* cwd;
    cwd = getcwd(NULL, 0);

    if (cwd == NULL)
    {
        perror("Failed to get cwd");
        exit(1);
    }
    return (cwd);
}

// Get USERID NAME
char* get_usrid(struct stat filestat){
	struct passwd *pwd;
	if ((pwd = getpwuid(filestat.st_uid)) != NULL){
		return (pwd->pw_name);
	}
	return (NULL);
}

// Get GROUP NAME
char* get_grpid(struct stat filestat){
	struct group *grp;
	if ((grp = getgrgid(filestat.st_gid)) != NULL){
		return (grp->gr_name);
	}
	return (NULL);
}

// Convert modified time
char* get_mtime(struct stat filestat){
	time_t epoch = filestat.st_mtime;
	char *timestring = ctime(&epoch);
	if (timestring != NULL){
		return (timestring);

	} else{
		return (NULL);
	}
}

// Print file type and permission
void permission(mode_t mode){

    // FOR OWNER/USER GROUP
    // Read mode
    if (mode & S_IRUSR)
    {
        printf("r");
    }else{
        printf("-");
    }
    // Write mode
    if (mode & S_IWUSR)
    {
        printf("w");
    }else{
        printf("-");
    }
    // execute mode
    if (mode & S_IXUSR)
    {
        printf("x");
    }else{
        printf("-");
    }

    // Group permission
    // Read mode
    if (mode & S_IRGRP)
    {
        printf("r");
    }else{
        printf("-");
    }
    // Write mode
    if (mode & S_IWGRP)
    {
        printf("w");
    }else{
        printf("-");
    }
    // execute mode
    if (mode & S_IXGRP)
    {
        printf("x");
    }else{
        printf("-");
    }
    //Others permission
    // Read mode
    if (mode & S_IROTH)
    {
        printf("r");
    }else{
        printf("-");
    }
    // Write mode
    if (mode & S_IWOTH)
    {
        printf("w");
    }else{
        printf("-");
    }
    // execute mode
    if (mode & S_IXOTH)
    {
        printf("x");
    }else{
        printf("-");
    }
}
