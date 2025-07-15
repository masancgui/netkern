# Build

## Building the toolchain

Build the toolchain using the `build-toolchain` script located in the `scripts` directory. This script optionally accepts the `MIRROR` environment variable with a suitable GNU mirror, if not specified, the default is used.

```sh
cd scripts
./build-toolchain
```

The toolchain will be installed in `$HOME/.local/cross`, so you may want to modify your `PATH` variable by adding this line to your `.profile`:

```sh
export PATH="$PATH:$HOME/.local/cross/bin"
```

## Building Netkern

Once you have built the toolchain and added it to your `PATH` variable, you can build the kernel.

There is a `Makefile` in the root of the repository that builds the entire kernel. Running `make` will build the kernel binary. You can use `make run` to actually run Netkern on QEMU.
