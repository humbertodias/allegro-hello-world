// https://www.allegro.cc/manual/4/

/**
CC=i686-w64-mingw32-g++
CC=g++
$CC main-tty.cpp -o main-tty --static `pkg-config --libs --cflags --static allegro`
*/
// #define ALLEGRO_NO_MAGIC_MAIN
#define ALLEGRO_STATICLINK
#include <allegro.h>

int main(int, char **)
{
    allegro_init();
    allegro_message("Allegro 4\n");
    return 0;
}
END_OF_MAIN()