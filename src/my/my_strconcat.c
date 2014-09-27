/*Bradford Smith (bsmith8)
*my_strconcat.c libmy project part 2
*9/13/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in two strings
*post: returns a newly allocated string of the concatenation of the given strings
*/
char* my_strconcat(char *s1, char *s2)
{
    char *result;
    unsigned int i;
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    if(s1 != NULL && s2 != NULL){
        result = (char*)xmalloc(len1 + len2 + 1);
        for(i = 0; i < len1; i++)
            result[i] = s1[i];
        for(i = 0; i <= len2; i++)
            result[i + len1] = s2[i];
    }else if(s1 == NULL && s2 != NULL){
        result = (char*)xmalloc(len2 + 1);
        for(i = 0; i <= len2; i++)
            result[i] = s2[i];
    }else if(s1 != NULL && s2 == NULL){
        result = (char*)xmalloc(len1 + 1);
        for(i = 0; i <= len1; i++)
            result[i] = s1[i];
    }else/*both NULL*/
        result = NULL;
    return result;
}
