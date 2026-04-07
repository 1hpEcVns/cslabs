{
  description = "CS:APP Cache Lab (lab5) development environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        buildInputs = [
          pkgs.gcc
          pkgs.gnumake
          pkgs.python3
          pkgs.git
          pkgs.zip
        ];
      };
    };
}