Aluno: __Lucas João Martins__ - Matrícula: __15100752__

# Complexidade de algoritmos - Floyd Modificado

A seguinte disposição da numeração das linhas no algoritmo de Floyd Modificado foi utilizada para a realização dos cálculos:

```
01. FloydModificado()
02. início
03.    para i = 1 até n faça
04.        para j = 1 até n faça
05.            A[i,j] <- D[i,j];
06.            R[i,j] <- 0;
07.       fim para
08.    fim para
09.    para i = 1 até n faça
10.        A[i,i] <- 0;
11.    fim para
12.    para k = 1 até n faça
13.        para i = 1 até n faça
14.            para j = 1 até n faça
15.                se A[i,k] + A[k,j] < A[i,j] então
16.                   A[i,j] <- A[i,k] + A[k,j];
17.                    R[i,j] <- k;
18.           fim para
19.        fim para
20.    fim para
21. fim
```

