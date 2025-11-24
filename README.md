# An Open-Source c++ VR Engine

> Currently in a very early stage of development, eventually, it will become a
> cross-platform VR engine that will hopefully support many, or potentially all
> VR platforms.

###### Note: Currently only builds for X11 windowing systems!

## Dependencies:
> - findutils  [find --version]
> - gcc        [g++ --version]
> - xcb        [pkg-config --exists xcb && echo "Yes" || echo "No"]

## Building:
>  ./build.sh -m (debug | release), [-h]
##### Constructs a .clangd for editor-diagnostics.
##### Builds the project into ./bin/(build | release).exe.