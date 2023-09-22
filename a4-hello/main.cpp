#include <allegro.h>

// https://www.allegro.cc/manual/4/

/**
CC=i686-w64-mingw32-g++
CFLAGS="`allegro-config --cflags`"
LIBS="`allegro-config --libs`"
$CC main.cpp -o main $CFLAGS $LIBS
*/
int main(void)
{
    allegro_init();
    allegro_message("Hello World!");
    return 0;
}
END_OF_MAIN()