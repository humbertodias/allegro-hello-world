A4_VERSION=4.4.3.1
A5_VERSION=5.2.8.0

a4-shell:
	docker run --rm -v ${PWD}:/tmp/workdir \
	-w /tmp/workdir \
	-e CC=i686-w64-mingw32-gcc \
	-e CXX=i686-w64-mingw32-g++ \
	-ti hldtux/allegro-compiler:${A4_VERSION}-mingw-w64-i686

a5-shell:
	docker run --rm -v ${PWD}:/tmp/workdir \
	-w /tmp/workdir \
	-e CC=i686-w64-mingw32-gcc \
	-e CXX=i686-w64-mingw32-g++ \
	-ti hldtux/allegro-compiler:${A5_VERSION}-mingw-w64-i686