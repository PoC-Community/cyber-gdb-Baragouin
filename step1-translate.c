#include <stdio.h>

int main(int argc, char **argv) {
    // mov    DWORD PTR [ebp-0xc],0x7
    int a = 7;
    // mov    DWORD PTR [ebp-0x10],0x1
    int b = 1;

    // mov edx,[ebp-0x10]
    // mov    eax,DWORD PTR [ebp-0xc]
    // add    eax,edx
    // cmp    eax,0x8
    // jne    0x80491b4 <main+62>
    if (a + b == 8) {
        // push   0x804a00c
        // call   0x8049040 <puts@plt>
        puts("Normal.");
    } else {
        // push   0x804a014
        // call   0x8049040 <puts@plt>
        puts("Hmm wait what ?!");
    }

    // mov    eax,DWORD PTR [ebp-0x10]
    return b;
}

