FROM ubuntu

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y \
        scons \
        libsdl1.2-dev \
        libboost-dev \
        openjdk-8-jre-headless \
        curl

RUN curl -L -o /tmp/antlr.tar.gz https://www.antlr2.org/download/antlr-2.7.7.tar.gz && \
    cd /tmp && \
    tar -zxf antlr.tar.gz && \
    cd antlr-2.7.7 && \
    sed -i '1s;^;#include <strings.h>\n;' /tmp/antlr-2.7.7/lib/cpp/antlr/CharScanner.hpp && \
    ./configure && \
    make && \
    make install && \
    cp /tmp/antlr-2.7.7/antlr.jar /usr/local/lib/antlr.jar

WORKDIR /root/ren

COPY . .

RUN scons

CMD ./build/src/ren/testCompiler
