# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.224.2/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version (use Debian 11, Ubuntu 18.04/21.04 on local arm64/Apple Silicon): debian-11, debian-10, ubuntu-21.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="bullseye"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# [Optional] Uncomment this section to install additional packages.
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends lcov \
    libssl-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

ARG version="3.22"
ARG build="2"
RUN mkdir ~/temp && cd ~/temp && wget https://cmake.org/files/v$version/cmake-$version.$build.tar.gz \
    && tar -xzvf cmake-$version.$build.tar.gz && cd cmake-$version.$build/ && ./bootstrap && make -j$(nproc) \
    && make install && cd .. && rm -rf cmake-$version.$build/
