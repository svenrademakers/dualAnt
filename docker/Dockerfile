FROM debian:latest
RUN apt-get update && apt-get install -y \
gcc \
g++ \
build-essential

# download and compile cmake 3.8
ADD https://cmake.org/files/v3.8/cmake-3.8.1.tar.gz /tmp
RUN cd /tmp && tar xzf cmake-3.8.1.tar.gz
WORKDIR /tmp/cmake-3.8.1
RUN ./bootstrap
RUN make install

#cleanup cmake install
WORKDIR /
RUN rm -rf /tmp/cmake*

#crosscompile image
FROM debian:stable-slim
RUN apt-get update && apt-get install -y \
libgtest-dev \
lib32stdc++6  lib32z1 lzop u-boot-tools \
build-essential gcc \
libncurses5-dev 

RUN mkdir -p /opt/toolchains
ADD http://releases.linaro.org/archive/14.09/components/toolchain/binaries/gcc-linaro-arm-linux-gnueabihf-4.9-2014.09_linux.tar.xz /tmp
RUN tar xvf tmp/gcc-linaro-arm-linux-gnueabihf-4.9-2014.09_linux.tar.xz -C /opt/toolchains/
#ENV

