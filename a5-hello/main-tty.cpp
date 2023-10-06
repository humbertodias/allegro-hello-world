#include <iostream>
#include <allegro5/allegro5.h>

// https://www.allegro.cc/manual/5/system.html

/**
CXX=i686-w64-mingw32-g++
CXX=clang++
CXX=g++
$CXX main.cpp -o main --static `pkg-config --static --cflags --libs allegro_monolith-static-5`
*/
using namespace std;
int main(int, char **) {
    al_init();
    al_install_keyboard();
    cout << "Allegro 5" << endl;
    return 0;
}