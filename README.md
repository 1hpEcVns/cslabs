# CS:APP Labs - Nix Development Environment

CS:APP (Computer Systems: A Programmer's Perspective) labs with reproducible Nix flake development environments.

## Prerequisites

- [Nix](https://nixos.org/download/) with flakes enabled

## Labs

| Lab | Name | Architecture | Description |
|-----|------|-------------|-------------|
| lab1 | Data Lab | i686 (32-bit) | Bit manipulation and floating point |
| lab2 | Data Lab | i686 (32-bit) | Bit manipulation and floating point |
| lab3 | Bomb Lab | i686 (32-bit) | Reverse engineering with GDB |
| lab4 | Attack Lab | i686 (32-bit) | Buffer overflow attacks |
| lab5 | Cache Lab | x86_64 (64-bit) | Cache simulation and matrix optimization |

## Usage

Enter a lab's development environment:

```bash
cd lab<N>
nix develop -i
```

Build and test (for labs with Makefiles):

```bash
cd lab1 && nix develop -i && make
cd lab2 && nix develop -i && make
cd lab5 && nix develop -i && make
```

Debug with GDB (lab3, lab4):

```bash
cd lab3 && nix develop -i
gdb ./bomb

cd lab4 && nix develop -i
gdb ./ctarget
```

## Flake Dependencies

- **lab1, lab2**: gcc (i686), gnumake, perl, git, zip
- **lab3, lab4**: gdb, binutils (i686)
- **lab5**: gcc (x86_64), gnumake, python3, git, zip

All packages are sourced from `nixpkgs` unstable channel.

## Clean Build

```bash
cd lab<N>
nix develop -c make clean
nix develop -c make
```
