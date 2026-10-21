#include "plsoslink.h"
#include "plsosmacros.h"
#include "plsffail.h"
#include "plslib.h"
#include "plscanary.h"

static char* ___pls_parse_cmd(LPWSTR args, int* sizeL){
    int size = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, args, (LPWSTR)-1, 0, 0, 0, 0);

    *sizeL = size;

    #define PLS_MALLOC_SIZE0_NULL
    char* out = (char*)plsmalloc(size);
    if(out == NULL){
        return NULL;
    }
    #undef PLS_MALLOC_SIZE0_NULL

    WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, args, (LPWSTR)-1, out, size, 0, 0); /* FIX LATER (ERR) */

    return out;
}

__attribute__((no_stack_protector, noreturn)) int mainCRTStartup(){
    init_stack_canary();

    int sz = 0;
    /* char** argv; */
    char* tempargv = {0};
    int argc = 0;
    int n = 0;
    int j = 0;
    int i = 0;
    int* rsz = &sz;
    DWORD numBytes;
    char* parsed =  ___pls_parse_cmd(GetCommandLineW(), rsz);
    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), parsed, sz, &numBytes, NULL);

     for(n = 2 ; n <= sz ; n++){
        if(parsed[n] == ' '){
            if(argc == 0){
                while(j <= n - 3){
                    tempargv[i] = parsed[j+1];
                    i++;
                    j++;
                    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), (LPCVOID)tempargv[i-1], 1, &numBytes, NULL);
                }
                argc++;

                i = n;
                j = n;
            } else {
            while(j <= n){
                tempargv[i] = parsed[j];
                i++;
                j++;
                WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), (LPCVOID)tempargv[i-1], 1, &numBytes, NULL);
            }
            argc++;

        }
        }

        }

        while(j+3 <= n){
                tempargv[i] = parsed[j];
                i++;
                j++;
                WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), (LPCVOID)tempargv[i-1], 1, &numBytes, NULL);
            } argc++;
    
    ExitProcess(0);
    __pls_unreachable();
}