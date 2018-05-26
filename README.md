# cola

###How TO:

#### Compilar todo el código:
    
    gcc -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror -o pruebas *.c

#### Verificar que no pierden memoria:

    valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas