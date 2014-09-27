#include "my.h"

void my_panic(char *s)
{
  my_str(s);
  exit(2);
}

int main()
{
  char *s1;
  char *s2;
  char *s3;

  // TESTING DUP
  s1 = my_strdup(NULL); // returns NULL
  if (s1 == NULL)
    my_str("First test passed!\n");
  else
    my_panic("my_strdup(NULL)\n");
  s1 = my_strdup("my_strdup has worked!\n");
  my_str(s1); // should print "my_strdup has worked!"
  s2 = my_strdup("");
  if (*s2 == '\0')
    my_str("dup of empty string worked\n");
  else
    my_panic("Dup of empty string failed\n");

  // TESTING CPY
  free(s2);
  s2 = NULL;
  s2 = my_strcpy(s2, "hello");
  if (s2 == NULL)
    my_str("cpy into NULL works!\n");
  else
    my_panic("cpy into NULL\n");
  if (s1 != my_strcpy(s1, NULL))
    my_panic("cpy not returning the right stuff\n");
  else
    my_str(s1); // should print "my_strdup has worked!"
  my_str(my_strcpy(s1, "my_strcpy works!\n")); // should print "my_strcpy works!\n"
  
  // TESTING NCPY
  s2 = my_strncpy(s2, "hello", 42);
  if (s2 == NULL)
    my_str("ncpy into NULL works!\n");
  else
    my_panic("ncpy into NULL\n");
  if (s1 != my_strncpy(s1, NULL, 58))
    my_panic("cpy not returning the right stuff\n");
  else
    my_str(s1); // should print "my_strcpy works!\n"
  my_str(my_strncpy(s1, "hello", 0)); // should print "my_strcpy works!\n"
  my_str(my_strncpy(s1, "mystrncpy blah", 9)); // should print "mystrncpy works!\n"
  my_str(my_strncpy(s1, "really works\n", 15)); // should print "really works\n"
  
  // TESTING FIND
  if (my_strfind(NULL, 'a') == NULL)
    my_str("Finding in NULL works\n");
  else
    my_panic("Find in NULL\n");
  my_str(my_strfind("Hello\n", 'l')); // should print "llo\n"
  if (my_strfind("Hello\n", 'a') == NULL)
    my_str("Finding something not there works\n");
  else
    my_panic("Finding something not there\n");
  
  // TESTING RFIND
  if (my_strrfind(NULL, 'a') == NULL)
    my_str("RFinding in NULL works\n");
  else
    my_panic("RFind in NULL\n");
  my_str(my_strrfind("Hello\n", 'l')); // should print "lo\n"
  if (my_strrfind("Hello\n", 'a') == NULL)
    my_str("RFinding something not there works\n");
  else
    my_panic("RFinding something not there\n");

  // TESTING CMP
  my_int(my_strcmp(NULL, NULL)); // should print 0
  my_char('\n');
  my_int(my_strcmp(NULL, "")); // should print a negative number
  my_char('\n');
  my_int(my_strcmp("", NULL)); // should print a positive number
  my_char('\n');
  my_int(my_strcmp("abc", "ab")); // should print a positive number
  my_char('\n');
  my_int(my_strcmp("ab", "abc")); // should print a negative number
  my_char('\n');
  my_int(my_strcmp("ab", "ab")); // should print 0
  my_char('\n');
  
  // TESTING NCMP
  my_int(my_strncmp(NULL, NULL, 54)); // should print 0
  my_char('\n');
  my_int(my_strncmp(NULL, "", 24)); // should print a negative number
  my_char('\n');
  my_int(my_strncmp("", NULL, 43)); // should print a positive number
  my_char('\n');
  my_int(my_strncmp("abc", "ab", 42)); // should print a positive number
  my_char('\n');
  my_int(my_strncmp("ab", "abc", 4)); // should print a negative number
  my_char('\n');
  my_int(my_strncmp("ab", "ab", 82)); // should print 0
  my_char('\n');
  my_int(my_strncmp(NULL, "", 0)); // should print a negative number
  my_char('\n');
  my_int(my_strncmp("", NULL, 0)); // should print a positive number
  my_char('\n');
  my_int(my_strncmp("abc", "ab", 2)); // should print 0
  my_char('\n');
  my_int(my_strncmp("abc", "def", 0)); // should print 0
  my_char('\n');

  // SETTING UP FOR CAT
  my_strcpy(s1, "my_strcat ");
  
  // TESTING CAT
  if (my_strcat(NULL, "test") == NULL)
    my_str("cat to NULL worked\n");
  else
    my_panic("cat to NULL\n");
  if (s1 != my_strcat(s1, NULL))
    my_panic("cat from NULL\n");
  else
    my_str(s1); // should print "my_strcat "
  my_str(my_strcat(s1, "works!\n")); // should print "my_strcat works!\n"
  
  // TESTING CONCAT
  if (my_strconcat(NULL, NULL) == NULL)
    my_str("concat NULL to NULL ok!\n");
  else
    my_panic("concat NULL to NULL\n");
  if ((s3 = my_strconcat(NULL, "concat NULL and string works\n")) == NULL)
    my_str("concant NULL and string failed\n");
  else
    my_str(s3); // should print "concat NULL and string works\n"
  if ((s2 = my_strconcat("concat string and NULL works\n", NULL)) == NULL)
    my_str("concant string and NULL failed\n");
  else
    my_str(s2); // should print "concat string and NULL works\n"
  free(s2);
  s2 = my_strconcat("concat ", "really works!\n");
  my_str(s2); // prints "concat really works!\n"
  
  // TESTING NCONCAT
  free(s3);
  free(s2);
  if (my_strnconcat(NULL, NULL, 24) == NULL)
    my_str("nconcat NULL to NULL ok!\n");
  else
    my_panic("nconcat NULL to NULL\n");
  if ((s3 = my_strnconcat(NULL, "nconcat NULL & string works\n", 21)) == NULL)
    my_str("nconcant NULL and string failed\n");
  else
    my_str(s3); // should print "nconcat NULL & string"
  my_char('\n');
  if ((s2 = my_strnconcat("concat string and NULL works\n", NULL, 24)) == NULL)
    my_str("concant string and NULL failed\n");
  else
    my_str(s2); // should print "concat string and NULL works\n"
  free(s2);
  s2 = my_strnconcat("nconcat ", "really works!\n", 4534);
  my_str(s2); // prints "nconcat really works!\n"
  free(s3);
  s3 = my_strnconcat("nconcat ", "worked\ngreat!", 7);
  my_str(s3); // prints "nconcat worked\n"

  return 0;
}
