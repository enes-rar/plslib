#include "plsoslink.h"
#include "plsosmacros.h"
#include "plsffail.h"
#include "plslib.h"
#include "plscanary.h"

#define ____SLASH (char)92

int A__main(int argc, char* argv[]);

int __main(){
    return 0;
}

static char* ___pls_parse_cmd(LPWSTR args, int* sizeL){
    int size = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, args, -1, 0, 0, 0, 0);

    *sizeL = size;

    #define PLS_MALLOC_SIZE0_NULL
    char* out = (char*)plsmalloc(size);
    if(out == NULL){
        return NULL;
    }
    #undef PLS_MALLOC_SIZE0_NULL

    WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, args, -1, out, size, 0, 0); /* FIX LATER (ERR) */

    return out;
}

int mainCRTStartup(){
    init_stack_canary();

    int sz = 0;
    int argc = 0;
    int inq = 1; /* in quotes denoter */
    int i = 0; /* cmd array pointer */
    int p = 0; /* argv array pointer */
    int* rsz = &sz; /* cmd size */
    DWORD numBytes; /* number of bytes written (genuinely useless, only to fill up the writefile func) */
    char* parsed =  ___pls_parse_cmd(GetCommandLineW(), rsz);
    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), parsed, sz, &numBytes, NULL);

    static char* argv[ARGV_MAX]; /* FIX LATER (dynamic) */
    argv[argc] = (char*)plsmalloc(100);

    /* FIX LATER (RUNTIME COMP PARSER) */
    if (parsed[0] == '"') {
        i++; /* skip opening quote */

        while (parsed[i] != '\0' && parsed[i] != '"') {
            argv[0][p] = parsed[i];
            p++;
            i++;
        }

    if (parsed[i] == '"') {
            i++; /* skip closing quote */
        }
    } else {
        while (parsed[i] != '\0' && parsed[i] != ' ' && parsed[i] != '\t') {
            argv[0][p] = parsed[i];
            p++;
            i++;
        }
    }

    argv[0][p] = '\0';
    p = 0;
    inq = 0;

    while(parsed[i] != '\0'){
    if((parsed[i] == ' ' || parsed[i] == '\t') && inq == 0){

        argv[argc][p+1] = '\0';
        argc++;
        argv[argc] = (char*)plsmalloc(100);
        p = 0;
        
        while(parsed[i] == ' ' || parsed[i] == '\t'){
            i++;
        }

        i--; /* otherwise i skips the first char of the arg because of the i++ at the end. */

    } else if(parsed[i] == '"'){

        inq = !inq;

    } else if(parsed[i] == ____SLASH){ 
        if(parsed[i+1] == '"'){
            /* literal quotes */
            argv[argc][p] = '"';
            i++;
            
        } else if(parsed[i+1] == ____SLASH){
            /* literal slash */
            argv[argc][p] = ____SLASH;
            i++;

        } else {

            argv[argc][p] = parsed[i];

        }
    } else {

        argv[argc][p] = parsed[i];

    }
    
    i++;
    p++;

    }

    A__main(argc, argv); /* FIX LATER (envp) */

    ExitProcess(0);
    __pls_unreachable();
}