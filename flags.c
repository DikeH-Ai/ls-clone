#include "main.h"

//FLAG DEF

/*
    Functions defines -a flag
*/
int ls_a(char* directory){
    /*
        folder: DIR stream
        dir_struct: readdir return value
    */
    //open directory
    DIR* folder;
    folder = opendir(directory);
    if (folder == NULL)
    {
        perror("Failed to open directory\n");
        exit(1);
    }
    
    //read directory contents
    struct dirent* dir_stuct;
    while ((dir_stuct = readdir(folder)))
    {
       printf("%-10s",dir_stuct->d_name);
    }
    printf("\n");
    //close folder
    closedir(folder);
    return (0);
}


/*
    Functions defines -d flag
*/
int ls_d(char* directory){
    /*
        folder: DIR stream
        dir_struct: readdir return value
    */
    //open directory
    DIR* folder;
    folder = opendir(directory);
    if (folder == NULL)
    {
        perror("Failed to open directory\n");
        exit(1);
    }
    
    //read directory contents
    struct dirent* dir_stuct;
    while ((dir_stuct = readdir(folder)))
    {

        struct stat file;
        char full_path[PATH_MAX];
        // READ READ THE FULL PATH OF DIRECTORY
        snprintf(full_path, sizeof(full_path), "%s/%s", directory, dir_stuct->d_name);

        if ((stat(full_path, &file) == 0))
        {
            if (S_ISDIR(file.st_mode) & dir_stuct->d_name[0] != '.')
            {
                printf("%-10s",dir_stuct->d_name);       
            }
        }else
        {
            perror("Error retriving file metadata\n");
            return (1);
        }
    }
    printf("\n");
    //close folder
    closedir(folder);
    return (0);
}

/*
    ls -al list all with long format - show permissions.
*/
int ls_al(char* directory){
    /*
        folder: DIR stream
        dir_struct: readdir return value
    */
    //open directory
    DIR* folder;
    folder = opendir(directory);
    if (folder == NULL)
    {
        perror("Failed to open directory\n");
        exit(1);
    }
    //read directory contents
    struct dirent* dir_stuct;

    printf("Permission| %-5s | %5s | %-5s | %-5s | %-5s | %-15s\n", "HARDLINK", "OWNER", "GROUP", "SIZE", "FILE NAME", "LAST-MOD");

    while ((dir_stuct = readdir(folder)))
    {
	// READ READ THE FULL PATH OF DIRECTORY
	char full_path[PATH_MAX];
	snprintf(full_path, sizeof(full_path), "%s/%s", directory, dir_stuct->d_name);

        // sys/stat function
        struct stat filestat;

        if (stat(full_path, &filestat) == 0)
        {
            if (S_ISDIR(filestat.st_mode)){
                printf("d");
            }else{
	    	printf("-");
	    }
            permission(filestat.st_mode);
        }

	char* usrid = get_usrid(filestat);
	char* grpid = get_grpid(filestat);
	char* mtime = get_mtime(filestat);
	printf("| %-5ld | %5s | %-5s | %-5lld | %-5s | %-5s", filestat.st_nlink, usrid, grpid, filestat.st_size, dir_stuct->d_name, mtime);
    }
    printf("\n");
    //close folder
    closedir(folder);
    return (0);
}


/*
    ls -l list with long format - show permissions.
*/
int ls_l(char* directory){
    /*
        folder: DIR stream
        dir_struct: readdir return value
    */
    //open directory
    DIR* folder;
    folder = opendir(directory);
    if (folder == NULL)
    {
        perror("Failed to open directory\n");
        exit(1);
    }
    //read directory contents
    struct dirent* dir_stuct;

    printf("Permission| %-5s | %5s | %-5s | %-5s | %-5s | %-15s\n", "HARDLINK", "OWNER", "GROUP", "SIZE", "FILE NAME", "LAST-MOD");

    while ((dir_stuct = readdir(folder)))
    {
	// READ READ THE FULL PATH OF DIRECTORY
	char full_path[PATH_MAX];
	snprintf(full_path, sizeof(full_path), "%s/%s", directory, dir_stuct->d_name);

        // sys/stat function
        struct stat filestat;

        if (stat(full_path, &filestat) == 0 && dir_stuct->d_name[0] != '.')
        {
            if (S_ISDIR(filestat.st_mode)){
                printf("d");
            }else{
	    	printf("-");
	    }
            permission(filestat.st_mode);
    	    char* usrid = get_usrid(filestat);
	    char* grpid = get_grpid(filestat);
	    char* mtime = get_mtime(filestat);
	    printf("| %-5ld | %5s | %-5s | %-5lld | %-5s | %-5s", filestat.st_nlink, usrid, grpid, filestat.st_size, dir_stuct->d_name, mtime);
        }
    }
    printf("\n");
    //close folder
    closedir(folder);
    return (0);

}
