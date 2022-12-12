FROM ubuntu:20.04

COPY . /Puzzle

WORKDIR /Puzzle

RUN apt-get update && \
    DEBIAN_FRONTEND="noninteractive" apt-get install -y git \
    gcc cmake build-essential \
    qt5-default \
    && \
    # Build Project
    rm -rf build && \
    ./genqt.sh && \
    mkdir build && cd build && \
    cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build .
