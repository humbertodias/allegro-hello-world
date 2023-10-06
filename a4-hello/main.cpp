#define ALLEGRO_NO_MAGIC_MAIN
#include <allegro.h>

// https://www.allegro.cc/manual/4/

/**
CC=i686-w64-mingw32-g++
CFLAGS="`allegro-config --cflags`"
LIBS="`allegro-config --libs --static`"
$CC main.cpp -o main $CFLAGS $LIBS
*/
int main(int argc, char **argv)
{
    allegro_init();
    allegro_message("Hello World!");
    return 0;
}
END_OF_MAIN()