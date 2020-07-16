gcc -std=c99 -Wall -Wextra -c src/armstrong_numbers.c -o armstrong.o
gcc -std=c99 -Wall -Wextra -c main.c -o main.o 
gcc -std=c99 -Wall -Wextra main.o armstrong.o -I./src -o run
