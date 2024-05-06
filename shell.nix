with import <nixpkgs> { };

mkShell {

  # Package names can be found via https://search.nixos.org/packages
  nativeBuildInputs = [
    SDL2
    SDL2_mixer
    SDL_mixer
    cmake
    gdb
    emscripten
  ];

  NIX_ENFORCE_PURITY = true;

  shellHook = ''
  '';
}
