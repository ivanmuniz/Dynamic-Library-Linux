#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    void *lib_handle;
    int (*asciiBinaryToInt)(char*);
    int (*asciiHexToInt)(char*);
    int (*asciiOctToInt)(char*);
    int iBinToInt = 0;
    int iHexToInt = 0;
    int iOctToInt = 0;
    char *error;
    char* s = NULL;

    lib_handle = dlopen("libDyn.so", RTLD_LAZY);
    if(!lib_handle) {
        fprintf(stderr, "%s\n", dlerror());
        return(1);
    }

    asciiBinaryToInt = dlsym(lib_handle, "asciiBinaryToInt");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return(1);
    }
    s = (char*)malloc(sizeof(char) * 9);
    printf("Ingrese el numero binario que desea convertir a decimal: ");
    scanf("%s", s);
    s[8] = '\0';
    iBinToInt = (*asciiBinaryToInt)(s);
    printf("%d\n", iBinToInt);
    free(s);

    asciiHexToInt = dlsym(lib_handle, "asciiHEXToInt");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return(1);
    }
    s = (char*)malloc(sizeof(char) * 9);
    printf("Ingrese el numero hexadecimal que desea convertir a decimal: ");
    scanf("%s", s);
    s[8] = '\0';
    iHexToInt = (*asciiHexToInt)(s);
    printf("%d\n", iHexToInt);
    free(s);

    asciiOctToInt = dlsym(lib_handle, "asciiOCTToInt");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return(1);
    }
    s = (char*)malloc(sizeof(char) * 9);
    printf("Ingrese el numero octal que desea convertir a decimal: ");
    scanf("%s", s);
    s[8] = '\0';
    iOctToInt = (*asciiOctToInt)(s);
    printf("%d\n", iOctToInt);
    free(s);

    dlclose(lib_handle);
    return(0);

}
