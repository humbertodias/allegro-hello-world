.PHONY: shell-a4, shell-a5

#ARCH=$(shell uname -m)
ARCH=i686
ARCH=aarch64
TYPE=native

archs:
	curl https://musl.cc

shell-a4:	build-a4
	docker run -it --rm -v ${PWD}/a4:/workdir \
	-w /workdir \
	-u `id -u`:`id -g` \
	-e CC=gcc \
	-e CXX=g++ \
	a4:${TYPE}-${ARCH} \
	bash

shell-a5:	build-a5
	docker run -it --rm -v ${PWD}/a5:/workdir \
	-w /workdir \
	-u `id -u`:`id -g` \
	-e CC=gcc \
	-e CXX=g++ \
	a5:${TYPE}-${ARCH} \
	bash

build-a4:
	cd a4 && docker build . \
	--build-arg ARCH=${ARCH} \
	--build-arg TYPE=${TYPE} \
	-t a4:${TYPE}-${ARCH}

build-a5:
	cd a5 && docker build . \
	--build-arg ARCH=${ARCH} \
	--build-arg TYPE=${TYPE} \
	-t a5:${TYPE}-${ARCH}
