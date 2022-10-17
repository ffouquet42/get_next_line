# get_next_line

*Version: 10*

## Grade - ?/125

Mandatory Part : ?/100

Bonus Part : ?/25

## Description

This project is about programming a function that returns a line
read from a file descriptor. This project introduces the static variable and the read() function.

## What's in this project

It was realized with all the bonuses. All the files are normed following the standard of 42.

This project contains the necessary get_next_line code to open and read following a file descriptor (fd) given, or many.

* Mandatory Part

`get_next_line.h`
`get_next_line.c`
`get_next_line_utils.c`

* Bonus Part

`get_next_line_bonus.h`
`get_next_line_bonus.c`
`get_next_line_utils_bonus.c`

## How to use it

You can create a text file .txt and fill it in the main. get_next_line will read the entire file.

The program also works by reading several fd at the same time.

You can initialize `BUFFER_SIZE` to a value greater than or equal to 0.

## Testing

This project respects the norm of 42 and has been tested with the norminette.

This project has been tested with valgrind and contains no leaks.
All tests return : `All heap blocks were freed -- no leaks are possible`

This project contains a custom `main.c` and `main_bonus.c` containing several tests for each part.

Tests can be run with the `file_1.txt`, `file_2.txt`, `file_3.txt`, `file_4.txt` and `file_5.txt`.

* Mandatory Part

run `cc -g -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c && valgrind --leak-check=yes --log-file=valgrind.rpt ./a.out && cat valgrind.rpt && rm valgr*`

* Bonus Part

run `cc -g -D BUFFER_SIZE=5 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c && valgrind --leak-check=yes --log-file=valgrind.rpt ./a.out && cat valgrind.rpt && rm valgr*`

== == ==
This project has also been tested with two testers from github. All the tests carried out return OK.  

* [printfTester](https://github.com/Tripouille/printfTester) from Tripouille  
* [ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester) from paulo-santana
== == ==

## Credit

Project made by [ffouquet42](https://github.com/ffouquet42)