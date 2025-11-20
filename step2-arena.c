#include <stdio.h>
#include <string.h>

void step2(void);

void step1(char *userInput) {
    // push   0x804a150
    // call   0x8049080 <puts@plt>
    puts("====================== CHAMP1 ======================");

    // push   DWORD PTR [ebp+0x8]
    // call   0x80490a0 <strlen@plt>
    // cmp    eax,0x5
    // jne    0x804948e <step1+129>
    if (strlen(userInput) != 5) {
        return;
    }

    // mov    eax,DWORD PTR [ebp+0x8]
    // movzx  eax,BYTE PTR [eax]
    // cmp    al,0x50
    // jne    0x8049491 <step1+132>
    if (userInput[0] != 'P') return;

    // mov    eax,DWORD PTR [ebp+0x8]
    // add    eax,0x1
    // movzx  eax,BYTE PTR [eax]
    // cmp    al,0x6f
    // jne    0x8049494 <step1+135>
    if (userInput[1] != 'o') return;

    // mov    eax,DWORD PTR [ebp+0x8]
    // add    eax,0x2
    // movzx  eax,BYTE PTR [eax]
    // cmp    al,0x43
    // jne    0x8049497 <step1+138>
    if (userInput[2] != 'C') return;

    // mov    eax,DWORD PTR [ebp+0x8]
    // add    eax,0x3
    // movzx  eax,BYTE PTR [eax]
    // cmp    al,0x3c
    // jne    0x804949a <step1+141>
    if (userInput[3] != '<') return;

    // mov    eax,DWORD PTR [ebp+0x8]
    // add    eax,0x4
    // movzx  eax,BYTE PTR [eax]
    // cmp    al,0x33
    // jne    0x804949d <step1+144>
    if (userInput[4] != '3') return;

    // push   DWORD PTR [ebp+0x8]
    // push   0x804a18c
    // call   0x8049060 <printf@plt>
    printf("\nArgh you found my flag, I will defeat you next time ! \"%s\"\n", userInput);

    // call   0x8049345 <step2>
    step2();
}

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
