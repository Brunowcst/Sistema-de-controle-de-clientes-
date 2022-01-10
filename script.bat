gcc -c clientes.c
gcc -c funcionario.c
gcc -c financas.c
gcc -c scc.c
gcc -c bibliotecascc.c

gcc -o scc.exe funcionario.o clientes.o financas.o bibliotecascc.o scc.o


del /f scc.o
del /f clientes.o
del /f funcionario.o
del /f financas.o
del /f bibliotecascc.o

