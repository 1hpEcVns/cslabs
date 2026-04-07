{
  description = "CS:APP Bomb Lab (lab3) development environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
      pkgs_i686 = import nixpkgs { system = "i686-linux"; };
    in
    {
      devShells.${system}.default = pkgs_i686.mkShell {
        buildInputs = [
          pkgs_i686.gcc
          pkgs_i686.gnumake
          pkgs_i686.gdb
          pkgs_i686.binutils
        ];
      };
    };
}