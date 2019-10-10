# Dynamic-Library-Linux
Dynamic Library of P11  
  
Install the library using:  
cp libDyn.so.1.0.1 /usr/lib  
ln -sf /usr/lib/libDyn.so.1.0.1 /usr/lib/libDyn.so  
ln -sf /usr/lib/libDyn.so.1.0.1 /usr/lib/libDyn.so.1  
  
Compile your code using:  
gcc -Wall -L/usr/lib/libDyn.so Prueba.c -ldl -lm  
or  
gcc -rdynamic Prueba.c -ldl -lm
