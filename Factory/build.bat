::Creo los directorios para el binario y las bibliotecas
MD .\bin\

::compilo el Binario
g++ -Wall -std=c++11 -I.\include\ main.cpp -o .\bin\main.exe

:: Limpio los códigos objeto
DEL .\*.o