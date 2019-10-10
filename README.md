# Dynamic-Library-Linux
Dynamic Library of P11  
  
The dynamic library has 3 functions  
int asciiBinaryToInt(char* s);  
int asciiHEXToInt(char* s);  
int asciiOCTToInt(char* s);  
  
All the functions receive a pointer of type char that captures a string of 9 digits.  
If the function returns -1 there was a problem converting the char stream. This is mostly because the program found an invalid character that cannot be converted.  
Else it returns an integer with the value of the conversion.  
  
Install the library using:  
cp libDyn.so.1.0.1 /usr/lib  
ln -sf /usr/lib/libDyn.so.1.0.1 /usr/lib/libDyn.so  
ln -sf /usr/lib/libDyn.so.1.0.1 /usr/lib/libDyn.so.1  
  
Compile your code using:  
gcc -Wall -L/usr/lib/libDyn.so Prueba.c -ldl -lm  
or  
gcc -rdynamic Prueba.c -ldl -lm
