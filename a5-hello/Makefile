.PHONY: release

libs:
	pkg-config --list-all | sort

win:
	$(eval CXX=i686-w64-mingw32-g++)
	$(eval CFLAGS=`i686-w64-mingw32-pkg-config --cflags allegro-5 allegro_main-5 allegro_font-5`)
	$(eval LIBS=`i686-w64-mingw32-pkg-config --libs allegro-5 allegro_main-5 allegro_font-5`)
	${CXX} main.cpp -o main.exe ${CFLAGS} ${LIBS}

lin:
	$(eval CXX=x86_64-linux-musl-g++)
	$(eval CFLAGS=`pkg-config --cflags allegro_monolith-static-5`)
	$(eval LIBS=`pkg-config --libs allegro_monolith-static-5`)
	${CXX} main.cpp -o main ${CFLAGS} ${LIBS}

mac:
	$(eval CXX=clang)
	$(eval CFLAGS=`pkg-config --cflags allegro-5 allegro_main-5 allegro_font-5`)
	$(eval LIBS=`pkg-config --libs allegro-5 allegro_main-5 allegro_font-5`)
	${CXX} main.cpp -o main ${CFLAGS} ${LIBS}

clean:
	rm -rf main main.exe build/* main-tty main-win

MUSL_ARCH=aarch64
docker:
	docker build . -t a5:${MUSL_ARCH}

shell:	docker
	docker run -it --rm -v `pwd`/..:/workdir -w /workdir a5:${MUSL_ARCH} ash

release:
	mkdir -p release
	$(eval CXX=g++)
	${CXX} main-tty.cpp -o release/main-tty --static `pkg-config --cflags --libs --static allegro_monolith-debug-static-5`
	${CXX} main-win.cpp -o release/main-win --static `pkg-config --cflags --libs --static allegro_monolith-debug-static-5`
	find /usr/local/lib -name "*allegro_monolith*.a" -exec cp "{}" release \;
	find / -name "libc.a" -exec cp "{}" release \;
	zip -r release-${MUSL_ARCH}.zip release
