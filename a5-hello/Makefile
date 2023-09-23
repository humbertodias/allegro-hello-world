libs:
	pkg-config --list-all | sort

win:
	$(eval CXX=i686-w64-mingw32-g++)
	$(eval CFLAGS=`i686-w64-mingw32-pkg-config --cflags allegro-5 allegro_main-5 allegro_font-5`)
	$(eval LIBS=`i686-w64-mingw32-pkg-config --libs allegro-5 allegro_main-5 allegro_font-5`)
	${CXX} main.cpp -o main.exe ${CFLAGS} ${LIBS}

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

clean:
	rm -rf main main.exe build/*

docker:
	docker build . -t a5-mingw

shell:	docker
	docker run -it --rm -v `pwd`/..:/tmp/workdir -w /tmp/workdir a5-mingw bash
