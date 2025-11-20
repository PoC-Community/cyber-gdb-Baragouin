#include <stdio.h>

int step1(char *argument);

int main(int argc, char **argv) {
    // push   0x804a1cc
    // call   0x8049080 <puts@plt>
    puts("PoC");

    // cmp    DWORD PTR [ebx],0x2
    // je     0x80494cd <main+45>
    if (argc != 2) {
        // mov    eax,0x1
        // jmp    0x80494f6 <main+86>
        return 1;
    }

    // mov    eax,DWORD PTR [ebx+0x4]
    // add    eax,0x4
    // mov    eax,DWORD PTR [eax]
    // sub    esp,0xc
    char *input = argv[1];

    // push   eax
    // call   0x804940d <step1>
    step1(input);

    // push   0x804a41d
    // call   0x8049080 <puts@plt>
    puts("CHAMP1");

    // mov    eax,0x0
    return 0;
}
