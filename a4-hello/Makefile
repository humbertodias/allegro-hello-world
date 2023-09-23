libs:
	pkg-config --list-all | sort

win:
	$(eval CXX=i686-w64-mingw32-g++)
	$(eval CFLAGS=`allegro-config --cppflags release` -I/usr/i686-linux-gnu/include -I/usr/include/x86_64-linux-gnu)
	$(eval LIBS=`allegro-config --libs release` -L/usr/lib/aarch64-linux-gnu -L/usr/lib/x86_64-linux-gnu)
	${CXX} main.cpp -o main.exe ${CFLAGS} ${LIBS}

lin:
	$(eval CXX=g++)
	$(eval CFLAGS=`allegro-config --cppflags release`)
	$(eval LIBS=`allegro-config --libs release`)
	${CXX} main.cpp -o main ${CFLAGS} ${LIBS}

mac:
	$(eval CXX=clang)
	$(eval CFLAGS=`allegro-config --cppflags release`)
	$(eval LIBS=`allegro-config --libs release`)
	${CXX} main.cpp -o main ${CFLAGS} ${LIBS}

clean:
	rm -rf main build/*

docker:
	docker build . -t a4-mingw

shell:	docker
	docker run -it --rm -v `pwd`/..:/tmp/workdir -w /tmp/workdir a4-mingw bash
