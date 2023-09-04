#!/bin/sh

command -v cmake >/dev/null 2>&1 || { echo "CMake não está instalado. Abortando compilação."; exit 1; }
command -v gcc >/dev/null 2>&1 || { echo "GCC não está instalado. Abortando compilação."; exit 1; }

build()
{
  echo "Building..."
  mkdir -p build
  cd build
  cmake ../
  make
  cp discloner ../
  echo "Done."
}

clean()
{
  echo "Cleaning..."
  rm -r build
  rm discloner
  echo "Done."
}

install()
{
  echo "Not implemented yet."
}

uninstall()
{
  echo "Not implemented yet."
}


case $1 in 
  --build)    build ;;
  --clean)    clean ;;
  --install)  install ;;
  --uninstall) uninstall ;;
  *) build ;;
esac

