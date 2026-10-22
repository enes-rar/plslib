#include "plsosmacros.h"
#include "plsoslink.h"
#include "plswintypes.h"
#include "plsdef.h"

int main(int argc, char** argv){
    argc++;
    argv[0][0] = '0';

    DWORD numBytes;
    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), (LPCVOID)'0', 4, &numBytes, NULL);

    return 0;
}
