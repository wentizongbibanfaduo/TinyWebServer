#!/bin/bash
set -ex

BUILDFILE=$0
ARGNUMS=$#
build(){
	if [-f server ];then
		rm server
	fi
	if [ -d build ];then
		rm build -rf
	fi
	mkdir build
	pushd build
	cmake .. -DCMAKE_BUILD_TYPE=Debug
	make -j8
	make install
	popd
}
build_docker(){
	if [ -f Dockerfile ];then
		echo "start build docker image"
		docker build -t zhou:0.1 .
		echo "build docker successful! need restart bash build.sh"
	else
		echo "no search Dockerfile"
		exit -1
	fi
}

if [ "${BUILD_TYPE}" = "docker" ];then
	build
	exit 0
fi

if [[ "$(docker images -q zhou:0.1 2> /dev/null)" = "" ]];then
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
		-e BUILD_TYPE="docker" \
		-w $PWD \
		zhou:0.1 \
		bash build.sh
fi

