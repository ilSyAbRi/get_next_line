## get next line

***get_next_line is a function that reads from a file descriptor.*** <br>
***Each time it’s called, it returns the next line until the end of the file.***

### How it works:
***It reads small chunks, stops at \n, returns one full line per call, saves the rest, and continues next time until it reaches the end of the file.***<br>
```Read → Newline → Return → Save → Repeat → EOF.```

### Notes / restrictions

##### Allowed:
```read, malloc, free```

#### Forbidden:
```lseek, global variables, libft```

[Click here to open the pdf subject](get_next_line_subject.pdf)
