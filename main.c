#include <string.h>
#include <Windows.h>
#include <stdio.h>

char* rewrite(char* src, char* dest, int fb, int lb);

int main(void){
    char** argv;
    char* temp;
    int argc = 0;
    int j = 0;
    int i = 0;
    int n = 0;
    int k = 0;
    int moment = 0;
    char dest[320];
    char* designedit = GetCommandLine();

    for(n = 2 ; n <= 77 ; n++){
        if(designedit[n] == ' '){
            if(k == 0){
                while(j <= n - 3){
                    dest[i] = designedit[j+1];
                    i++;
                    j++;
                    printf("%c", dest[i-1]);
                }
                k++;
                moment = n;
                i = n;
                j = n;
            } else {
            while(j <= n){
                dest[i] = designedit[j];
                i++;
                j++;
                printf("%c", dest[i-1]);
            }
            k++;

        }
        }

        }

        while(j+3 <= n){
                dest[i] = designedit[j];
                i++;
                j++;
                printf("%c", dest[i-1]);
            }

        
}
