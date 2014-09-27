/*Bradford Smith (bsmith8)
*my_strncmp.c libmy project part 2
*9/13/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in two strings and an unsigned integer
*post: returns a number < 0 if the first string is alphabetically before the second
up to the given number of characters, a number > 0 if the second string is before the
first up the the given number of characters, and 0 if the strings are the same up to
the given number of characters
*/
int my_strncmp(char *s1, char *s2, unsigned int n)
{
    int ans = 0;
    unsigned int i;
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    if(s1 != NULL && s2 != NULL){
        if(n != 0){
            for(i = 0; i < len1 && i < len2 && i < n && ans == 0; i++)
                ans = s1[i] - s2[i];
            if(ans == 0 && i < n && i < len1)/*s2 is shorter*/
                ans = 1;
            else if(ans == 0 && i < n && i < len2)/*s1 is shorter*/
                ans = -1;
        }
    }else if(s1 == NULL && s2 != NULL){
        ans = -1;
    }else if(s1 != NULL && s2 == NULL){
        ans = 1;
    }
    return ans;
}
