name: Build pedestrians GLIBC 2.17

on:
  workflow_dispatch:
  push:
    paths:
      - 'src/**'
      - 'sdk/**'
      - 'build_glibc217.sh'

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4

      - name: Build 32-bit plugin against GLIBC 2.17
        run: |
          docker run --rm \
            -v "$GITHUB_WORKSPACE:/src" \
            -w /src \
            quay.io/pypa/manylinux2014_i686 \
            /bin/bash -lc './build_glibc217.sh'

      - name: Verify binary
        run: |
          file build_glibc217/pedestrians.so
          strings build_glibc217/pedestrians.so | grep -o 'GLIBC_[0-9.]*' | sort -Vu | tail -20 || true

      - uses: actions/upload-artifact@v4
        with:
          name: pedestrians-direction-fix-glibc217
          path: build_glibc217/pedestrians.so
