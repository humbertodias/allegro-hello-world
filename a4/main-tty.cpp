// https://www.allegro.cc/manual/4/

/**
CC=i686-w64-mingw32-g++
CC=g++
$CC --static main-tty.cpp -o main-tty `pkg-config --libs --cflags --static allegro`

$CC main-tty.cpp -o main-tty `pkg-config --libs --cflags --static allegro`

$CC main-tty.cpp -o main-tty -lalleg -L _deps/allegro4-build/lib
*/
#define ALLEGRO_NO_MAGIC_MAIN
#define ALLEGRO_STATICLINK
#include <allegro.h>
#include <stdio.h>

int main(int argc, char **argv)
{

    if (!allegro_init()) {
        printf("Could not init Allegro.\n");
    }

    allegro_message("Allegro 4\n");
    return 0;
}
END_OF_MAIN()