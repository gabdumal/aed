FROM fedora:latest

# Install system dependencies and generate locale
RUN dnf upgrade -y
RUN dnf install -y \
    git \
    curl \
    ca-certificates \
    libatomic \
    openssl-devel \
    gcc

# Create dummy xdg-open
RUN printf '#!/bin/sh\nexit 0\n' > /usr/local/bin/xdg-open && chmod +x /usr/local/bin/xdg-open

# Install LLVM tools
RUN sudo dnf install -y \
    llvm \
    clang \
    clang-analyzer \
    clang-devel \
    clang-libs \
    clang-resource-filesystem \
    clang-tools-extra \
    clang-tools-extra-devel \
    compiler-rt \
    git-clang-format \
    libcxx \
    libcxx-devel \
    libcxx-static \
    libcxxabi \
    libcxxabi-devel \
    libcxxabi-static \
    lld \
    lld-devel \
    lld-libs \
    lldb \
    lldb-devel \
    llvm-bolt \
    llvm-cmake-utils \
    llvm-devel \
    llvm-doc \
    llvm-filesystem \
    llvm-googletest \
    llvm-libs \
    llvm-static \
    llvm-test \
    mlir \
    mlir-devel \
    mlir-static \
    polly \
    polly-devel \
    python3-clang \
    python3-lit \
    python3-lldb \
    python3-mlir

# Install CMake
RUN sudo dnf install -y \
    cmake \
    ninja-build \
    python3-ninja
