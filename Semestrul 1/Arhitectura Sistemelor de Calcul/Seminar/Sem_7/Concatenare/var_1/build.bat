
nasm modul.asm -fwin32 -o modul.obj

cl /Zi main.c /link modul.obj
