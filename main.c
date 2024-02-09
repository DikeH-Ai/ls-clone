#include "main.h"

int main(int argc, char* argv[]){
    if (argc == 1)
    {
        /*
         Get the cwd using the getcwd function
         cwd: current working directory buffer 
        */
        char* cwd;
        cwd = get_cwd();
        ls_cwd(cwd);
        free(cwd);
    }else{
        ls_dir(argc,argv);
       // printf("Ls with arguments");
    }
    
    return (0);
}

int ls_dir(int argc, char* argv[]){
    /*
        Depricate using t0 three outcomes 
        -flag
        -flag & argument
        -argument
    */
    if ((argv[1][0] == '-') && (argv[2] == NULL))
    {
        /* code */
        printf("-Flag\n");
        //  get cwd
        char* cwd;
        cwd = get_cwd();
        if (strcmp(argv[1], "-a") == 0)
        {
            ls_a(cwd);
        }else if (strcmp(argv[1], "-d") == 0)
        {
            ls_d(cwd);
        }else if (strcmp(argv[1], "-al") == 0 | strcmp(argv[1], "-la") == 0)
        {
            ls_al(cwd);
        }else if (strcmp(argv[1], "-l") == 0)
        {
            ls_l(cwd);
        }else{
            fprintf(stderr,"Invalid Option: %s\n", argv[1]);
        }
        
    }else if ((argv[1][0] == '-') && (argv[2] != NULL))
    {
        /* code */
        printf("-Flag and argument\n");

        if (strcmp(argv[1], "-a") == 0)
        {
            if (argc > 3)
            {
                int n = 2;
                while (argv[n] != NULL)
                {
                    printf("%s: ", argv[n]);
                    ls_a(argv[n]);
                    printf("\n");
                    n++;
                }
                
            }else{

                ls_a(argv[2]);
            }
            /* ls_a(argv[2]); */
        }else if (strcmp(argv[1], "-d") == 0)
        {
            if (argc > 3)
            {
                int n = 2;
                while (argv[n] != NULL)
                {
                    printf("%s: ", argv[n]);
                    ls_d(argv[n]);
                    printf("\n");
                    n++;
                }
                
            }else{

                ls_d(argv[2]);
            }
        }else if (strcmp(argv[1], "-al") == 0)
        {
            if (argc > 3)
            {
                int n = 2;
                while (argv[n] != NULL)
                {
                    printf("%s: \n", argv[n]);
                    ls_al(argv[n]);
                    printf("\n");
                    n++;
                }
                
            }else{

                ls_al(argv[2]);
            }
        }else if (strcmp(argv[1], "-l") == 0)
        {
            if (argc > 3)
            {
                int n = 2;
                while (argv[n] != NULL)
                {
                    printf("%s: \n", argv[n]);
                    ls_l(argv[n]);
                    printf("\n");
                    n++;
                }
                
            }else{

                ls_l(argv[2]);
            }
        }else{
            fprintf(stderr,"Invalid Option: %s\n", argv[1]);
        }

    }else if ((argv[1][0] != '-'))
    {
        /* code */
        printf("argument\n");
        /*
            encounted a funny issue; when met with a
            abs-path that has a space within it, code
            does not behave as expected.
        */
        /* if (argv[2] != NULL)
        char* fullname;
        {
            // Calculate the length of the strings
            size_t firstNameLength = strlen(argv[1]);
            size_t lastNameLength = strlen(argv[2]);
            //allocate fullname buffer
            fullname = (char *)malloc(firstNameLength + lastNameLength + 1);

            //copy both names to fullname
            if (fullname != NULL) {

                // Copy the first name into the full name
                strcpy(fullname, argv[1]);
                // Add up th space 
                strcat(fullname, " ");
                // Concatenate the last name to the full name
                strcat(fullname, argv[2]);

                printf("Full Name: %s\n", fullname);
                free(fullname);
            }else {
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }
        } */
        if (argc > 2)
        {
            int n = 1;
            while (argv[n] != NULL)
            {
                printf("%s: ", argv[n]);
                ls_cwd(argv[n]);
                printf("\n");
                n++;
            }
            
        }else{

            ls_cwd(argv[1]);
        }
    }else{
       fprintf(stderr, "Usage: ls [Options] [Directory]\n");
    }
    return (0);
}
