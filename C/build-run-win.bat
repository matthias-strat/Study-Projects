@ECHO OFF
IF NOT EXIST bin MKDIR bin
gcc -DNDEBUG -o bin\%2.exe "%1\%2.c"
bin\%2.exe