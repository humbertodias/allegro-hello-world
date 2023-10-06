.PHONY: release

libs:
	pkg-config --list-all | sort

win:
	$(eval CXX=i686-w64-mingw32-g++)
	$(eval CFLAGS=`pkg-config --cppflags allegro` -I/usr/i686-linux-gnu/include -I/usr/include/x86_64-linux-gnu)
	$(eval LIBS=`pkg-config --libs allegro` -L/usr/lib/aarch64-linux-gnu -L/usr/lib/x86_64-linux-gnu)
	${CXX} main.cpp -o main.exe ${CFLAGS} ${LIBS}

lin:
	$(eval CXX=g++)
	$(eval CFLAGS=`pkg-config --cppflags allegro`)
	$(eval LIBS=`pkg-config --libs allegro`)
	${CXX} main.cpp -o main ${CFLAGS} ${LIBS}

mac:
	$(eval CXX=clang)
	$(eval CFLAGS=`pkg-config --cppflags allegro`)
	$(eval LIBS=`pkg-config --libs allegro`)
	${CXX} main.cpp -o main ${CFLAGS} ${LIBS}

clean:
	rm -rf main build/* main-tty main-win

MUSL_ARCH=aarch64
docker:
	docker build . -t a4:${MUSL_ARCH}

shell:	docker
	docker run -it --rm -v `pwd`/..:/workdir -w /workdir a4:${MUSL_ARCH} ash

release:
	mkdir -p release
	$(eval CXX=g++)
	${CXX} main-tty.cpp -o release/main-tty --static `pkg-config --libs --cflags --static allegro-debug`
	${CXX} main-win.cpp -o release/main-win --static `pkg-config --libs --cflags --static allegro-debug`
	find /usr/local/lib -name "*allegro*.a" -exec cp "{}" release \;
	find / -name "libc.a" -exec cp "{}" release \;
	zip -r release-${MUSL_ARCH}.zip release
	