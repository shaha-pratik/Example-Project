# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.224.2/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version (use Debian 11, Ubuntu 18.04/21.04 on local arm64/Apple Silicon): debian-11, debian-10, ubuntu-21.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="bullseye"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# [Optional] Uncomment this section to install additional packages.
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends lcov \
    libssl-dev \
    python3 \
    python3-pip \
    clang-format \
    && pip3 install --upgrade setuptools \
    && pip3 install --upgrade pip \
    && pip3 install --ignore-installed PyYAML \
    && pip3 install pre-commit pandas numpy\
    && apt-get clean && rm -rf /var/lib/apt/lists/*

ARG CAMKE_VERSION="3.22"
ARG CMAKE_VERSION_BUILD="2"
RUN mkdir ~/temp && cd ~/temp && wget https://cmake.org/files/v$CAMKE_VERSION/cmake-$CAMKE_VERSION.$CMAKE_VERSION_BUILD.tar.gz \
    && tar -xzvf cmake-$CAMKE_VERSION.$CMAKE_VERSION_BUILD.tar.gz && cd cmake-$CAMKE_VERSION.$CMAKE_VERSION_BUILD/ && ./bootstrap && make -j$(nproc) \
    && make install && cd .. && rm -rf cmake-$CAMKE_VERSION.$CMAKE_VERSION_BUILD/
