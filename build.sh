#!/bin/bash
set -eux

BUILDFILE=$0
ARGNUMS=$#
TARGET=$@

if [ ${ARGNUMS} = 0 ];then
	TARGET="make"
fi
build_docker(){
	if [ -f Dockerfile ];then
		echo "start build docker image"
		docker build -t zhou:0.1 .
	else
		echo "no search Dockerfile"
		exit -1
	fi
}

if [[ "$(docker images -q zhou:0.1 2> /dev/null)" == "" ]];then
	echo "no search build docker"
	build_docker
else
	echo "find build docker"
	echo "target is ${TARGET}"
	docker run --rm \
		-it \
		-v $PWD/:$PWD \
		-v /usr1/cache:/usr1/cache \
		-e CCACHE_DIR=/usr1/cache \
		-e CXX="ccache g++" \
		-e CC="ccache gcc" \
		-w $PWD \
		zhou:0.1 \
		${TARGET}
fi
