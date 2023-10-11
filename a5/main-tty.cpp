#include <iostream>
#include <cstdio>
#include <allegro5/allegro5.h>

// https://www.allegro.cc/manual/5/system.html

/**
CXX=i686-w64-mingw32-g++
CXX=clang++
CXX=g++
$CXX --static -g main-tty.cpp -o main-tty `pkg-config --static --cflags --libs allegro-debug-static-5`
*/
using namespace std;
int main(int, char **) {
    printf("%0x\n%0x\n", ALLEGRO_VERSION_INT, al_get_allegro_version());
    if (!al_init()) {
        printf("Could not init Allegro.\n");
    }
    al_install_keyboard();
    cout << "Allegro 5" << endl;
    return 0;
}