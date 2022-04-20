# DISCLONER
Program to easily clone your disk, with visual progress output and the possibility to resume right where it was interrupted.

## Usage

    discloner [-s | --size <SIZE>/<PERCENTAGE>] [-c | --count <NUMBER OF BLOCK>]
              [-b | --blocksize <SIZE>] [-i | --input <INPUT FILE>]
              [-o | --output <OUTPUT FILE>] --continue <INPUT FILE> <OUTPUT FILE>
    
    -s | --size:        Amount of data that you want to copy from INPUT to OUTPUT.
                        Can be writen as : [B]  for bytes.
                                           [KB] for Kilobytes.
                                           [MB] for Megabytes.
                                           [GB] for Gigabytes.
                                           [TB] for Terabytes.
                        If used with [-c | --count], the [-s | --size] option
                        will be ignored.
    -b | --blocksize:   Size of the block os data that will be read from INPUT
                        in every interation, in BYTES.
    -c | --count:       The number of blocks you want to be copied from INPUT to
                        OUTPUT. Will ignore [-s | --size] argument if its
                        used together.
    -i | --input        The file that you wanto to clone as INPUT.
    -o | --output       The file you want to be the OUTPUT from cloning.
         --continue     Resume the last operation if it where interrupted.

Examples:

    discloner /dev/sdc ~/disc/HD.img
    discloner -i /dev/sdc -o /dev/sdd
    discloner -c 1 --blocksize 512 -i ~/MBR-table.iso -o /dev/sdc
    discloner -s 25GB "~/My disk image/Disk.img" -o "/mnt/My backup/Disk.img"
    discloner -s 50% /dev/sda "~/half disk.img"
    discloner --continue

## Building
Needed prograns
  * cmake: Version > 3.10
  * g++:   C++ 17 GCC compiler, Version: > 9.4.0

### To Build

    build.sh
    or
    build.sh --build

### To Install/Uninstall

    build.sh --install
    or
    build.sh --uninstall

### To clean build files

    build.sh --clean

