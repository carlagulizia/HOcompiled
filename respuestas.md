1. Escriban que esperan de cada uno de los pasos
-El preprocesador se encarga de las directivas # como los includes y las macros. Busca los archivos, los copia y los incluye.

-El make assembler pasa del lenguaje C al assembler, es un nivel mas bajo, cada vez mas cerca del lenguaje de maquina, pero aun podemos leerlo.

Al ejecutarlo lo que hace es: gcc -masm=intel -S calculator.c -o calculator.asm 
y genera el archivo calculator.asm 

-El make object me genera un objeto. Pasa del assembler al lenguaje de la maquina.
Al ejecutarlo lo que hace es: gcc -c calculator.c -o calculator.o

-El make executable me genera el ejecutable, ya compilado.
Al ejecutarlo lo que hace es: gcc calculator.o -o calculator.e
2. ¿Qué agrego el preprocesador?
Al hacer make preprocessing se compilo el primero de los 4 pasos: 
gcc -E calculator.c -o calculator.pp_c
Se agrego el archivo calculator.pp_c

3. Identificar en la rutina de assembler las funciones
En el main con "call" llama a las funciones add_numbers (linea 23) y printf (linea 29). Para add_numbers agrega los valores 11 y 31 que va a sumar en los registros esi y edi

4. Explicar que quieren decir los símbolos que se crean en el objeto
Al ejecutar "nm calculator.o", los simbolos del objeto son los siguientes:
000000000000003c T add_numbers
0000000000000000 T main
                 U printf
Los segmentos que se pueden ejecutar son add_numbers y main, y estan definidos, mientras que printf no esta definido a priori.

5. ¿En que se diferencian los símbolos del objeto y del ejecutable?
Al ejecutar nm calculator.e aparecen muchos mas elementos que los que tenia el objeto. En particular me focalice en los siguientes:
0000000000400569 T add_numbers
000000000040052d T main
                 U printf@@GLIBC_2.2.5

Aqui se puede ver que main y add_numbers continuan igual al tiempo de ejecucion, pero ahora printf que antes de generar el ejecutabole no estaba definido, ahora si bien continua sin estar definido esta mediante una libreria dinamica GLIBC version 2.2.5 la cual lo definira al momento de ejecutarlo.
