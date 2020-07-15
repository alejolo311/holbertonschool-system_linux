#include "ls.h"
/**
 * sort - read the files and sort
 * Description: this function sort files
 * @files: double pointer to the arguments passed in the call
 * @mode: in which way is the info sorted
 * section header: the header of this function is ls.h
 * Return: a string with al the valid args
 */
char **sort(char **files, int mode)
{   
    lfile_s *lfile = NULL;;
    
    lfile = to_list(files);
    nsort(&lfile);

    if (mode == 2)
        reverse(&lfile);

    files = to_array(&lfile);
    
    free_list(&lfile);
    return files;
}   