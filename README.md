## get next line

***get_next_line is a function that reads from a file descriptor.*** <br>
***Each time it’s called, it returns the next line until the end of the file.***

### How it works:
***It reads small chunks, stops at \n, returns one full line per call.<br>
saves the rest, and continues next time until it reaches the end of the file.***<br>
 
```Read → Newline → Return → Save → Repeat → EOF.```

### Notes / restrictions

###### Allowed:```read, malloc, free```

###### Forbidden:```lseek, global variables, libft```

[***Click here to open the pdf subject for more detail***](get_next_line_subject.pdf)


```
^&^ '\n' ? EOF ? (:
```

---

### Test:

#### Create test.txt
``` vim test.txt and put this```
```c
Hello
World
42
get_next_line test
```
### main.c:
```vim main.c and put this```
```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)))
        printf("%s", line), free(line);
}
```
### Compile & run:
``` 
BUFFER_SIZE: It defines the chunk size used during file reading.
You can replace 42 with any number greater than 0.
```

```c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
./a.out
```
### Output:
``` this <- just for explaination```
```c
Hello <- newline
World
42
get_next_line test <-end of file
```
