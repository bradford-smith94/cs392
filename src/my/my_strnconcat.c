/*Bradford Smith (bsmith8)
*my_strnconcat.c libmy project part 2
*9/13/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in two strings and a number
*post: returns a newly allocated string that is the concatenation of the first string
and up to the given number of characters in the second string
*/
char* my_strnconcat(char *s1, char *s2, unsigned int n)
{
    char *result;
    unsigned int i;
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    if(s1 != NULL && s2 != NULL){
        if(len2 < n)
            result = (char*)xmalloc(len1 + len2 + 1);
        else
            result = (char*)xmalloc(len1 + n);
        for(i = 0; i < len1; i++)
            result[i] = s1[i];
        if(len2 < n)
            for(i = 0; i <= len2; i++)
                result[i + len1] = s2[i];
        else
            for(i = 0; i < n; i++)
                result[i + len1] = s2[i];
    }else if(s1 == NULL && s2 != NULL){
        if(len2 < n){
            result = (char*)xmalloc(len2 + 1);
            for(i = 0; i <= len2; i++)
                result[i] = s2[i];
        }else{
            result = (char*)xmalloc(n);
            for(i = 0; i < n; i++)
                result[i] = s2[i];
        }
    }else if(s1 != NULL && s2 == NULL){
        result = (char*)xmalloc(len1  + 1);
        for(i = 0; i <= len1; i++)
            result[i] = s1[i];
    }else/*both NULL*/
        result = NULL;
    return result;
}
