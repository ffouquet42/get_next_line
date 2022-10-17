GNL

cc -g -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c && valgrind --leak-check=yes --log-file=valgrind.rpt ./a.out && cat valgrind.rpt && rm valgr*

cc -g -D BUFFER_SIZE=5 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c && valgrind --leak-check=yes --log-file=valgrind.rpt ./a.out && cat valgrind.rpt && rm valgr*