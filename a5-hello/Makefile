win:
	CXX=i686-w64-mingw32-gcc
	$(eval CFLAGS=`pkg-config --cflags allegro-5 allegro_main-5 allegro_font-5`)
	$(eval LIBS=`pkg-config --libs allegro-5 allegro_main-5 allegro_font-5`)
	${CXX} main.cpp -o main ${CFLAGS} ${LIBS}

lin:
	$(eval CXX=g++)
	$(eval CFLAGS=`pkg-config --cflags allegro-5 allegro_main-5 allegro_font-5`)
	$(eval LIBS=`pkg-config --libs allegro-5 allegro_main-5 allegro_font-5`)
	${CXX} main.cpp -o main ${CFLAGS} ${LIBS}

mac:
	$(eval CXX=clang)
	$(eval CFLAGS=`pkg-config --cflags allegro-5 allegro_main-5 allegro_font-5`)
	$(eval LIBS=`pkg-config --libs allegro-5 allegro_main-5 allegro_font-5`)
	${CXX} main.cpp -o main ${CFLAGS} ${LIBS}
