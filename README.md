#  _printf

​

##  Description

Recieves a string with format patterns and a set of values, and then prints the formatted string replacing the patterns with the values.

###  Usage

​

    _printf("format  string  with  patterns",  arg1,  arg2,  ...);

​

###  Patterns

 -  %s  -  Replaces  the  token  with  a  string  on  the  position  of  the  flag.

 **For  example:**

`_printf("My  name  is  %s  %s\n",  "John",  "Doe");`

Will print "My name is John Doe".

  %c  -  Replaces  the  token with a character.

 **For example**

`_printf("Open your %cind", 'm');`

Will print "Open your mind".

   %i - Replaces the token with an integer.

 **For example**

`_printf("I'm %i years old", 24);`

Will print "I'm 24 years old".

%d - Replaces the token with a decimal.

 **For example**

`_printf("my favorite number is %d", 11);`

Will print "my favorite number is 11".

%% - Prints only one percentage

 **For example**

`_printf("My chances of winning are %%5");`

Will print "My chances of winning are %5".

**How it works?**





 1. First we need to check if the string isn't empty and if is empty the function returns an error message.
  2. We itterate the string looking for the percentage simbol.
   3. We check if after finding the next position is a char '\0' and if it is return an error message.
    4. if is not '\0' we call the function print_functions.c for check if the's a match between the character and the filter.
     5. If there is a match, the respective function is called from print_functions.c
      6. if the character is 's', 'c', 'd', 'i', '%', NULL will print a string, a character, a number, a percentaje or NULL respectively.
      ## Requirements

### General

-   Allowed editors:  `vi`,  `vim`,  `emacs`
-   All your files will be compiled on Ubuntu 20.04 LTS using  `gcc`, using the options  `-Wall -Werror -Wextra -pedantic -std=gnu89`
-   All your files should end with a new line
-   A  `README.md`  file, at the root of the folder of the project is mandatory
-   Your code should use the  `Betty`  style. It will be checked using  betty-style  and  betty-doc
-   You are not allowed to use global variables
-   No more than 5 functions per file
-   In the following examples, the  `main.c`  files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own  `main.c`  files at compilation. Our  `main.c`  files might be different from the one shown in the examples
-   The prototypes of all your functions should be included in your header file called  `main.h`
-   Don’t forget to push your header file
-   All your header files should be include guarded
-   Note that we will not provide the  `_putchar`  function for this project

#### Authorized functions and macros

-   write (man 2 write)
-   malloc (man 3 malloc)
-   free (man 3 free)
-   va_start (man 3 va_start)
-   va_end (man 3 va_end)
-   va_copy (man 3 va_copy)
-   va_arg (man 3 va_arg)


**Files**

 - _printf.c
  - _putchar.c
   - main.h
    - print_functions.c


**Authors**

Miguel Damasco

Lorena Nuñez
