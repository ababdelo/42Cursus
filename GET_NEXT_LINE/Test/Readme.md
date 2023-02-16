Chapter III

Mandatory part

Function name get_next_line

Prototype char *get_next_line(int fd);

Turn in files get_next_line.c, get_next_line_utils.c, get_next_line.h

Parameters fd: The file descriptor to read from

Return value Read line: correct behavior

NULL: there is nothing else to read, or an error occurred

External functs. read, malloc, free

Description Write a function that returns a line read from a file descriptor

• Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.

• Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.

• Make sure that your function works as expected both when reading a file and when reading from the standard input.

• Please note that the returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.

• Your header file get_next_line.h must at least contain the prototype of the get_next_line() function.

• Add all the helper functions you need in the get_next_line_utils.c file. A good start would be to know what a static variable is. Get Next Line Reading a line from a fd is way too tedious.

• Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n It will define the buffer size for read(). The buffer size value will be modified by your peer-evaluators and the Moulinette in order to test your code.
We must be able to compile this project with and without the -D BUFFER_SIZE flag in addition to the usual flags. You can choose the default value of your choice.

• You will compile your code as follows (a buffer size of 42 is used as an example): cc -Wall  -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

• We consider that get_next_line() has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas read() didn’t reach the end of file.

• We also consider that get_next_line() has an undefined behavior when reading a binary file However, you can implement a logical way to handle this behavior if you want to.

Does your function still work if the BUFFER_SIZE value is 9999? If it is 1? 10000000? Do you know why?

Try to read as little as possible each time get_next_line() is called. If you encounter a new line, you have to return the current line.

Don’t read the whole file and then process each line.

				Forbidden
• You are not allowed to use your libft in this project.
• lseek() is forbidden.
• Global variables are forbidden.
 