with import <nixpkgs> { };

mkShell {

  # Package names can be found via https://search.nixos.org/packages
  nativeBuildInputs = [
    SDL2
    SDL
    SDL2_mixer
    SDL2_image
    SDL2_ttf
    curlFull
    cmake
    clang
    gdb
    emscripten
  ];

  NIX_ENFORCE_PURITY = true;

  shellHook = ''
  '';
}
