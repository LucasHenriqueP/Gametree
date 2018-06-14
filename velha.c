#include <stdio.h>
#include <stdlib.h>

int v;

typedef struct tic {
    int livre;
    int mm;
    struct tic ** filhos;
} velha;




void buildtree(velha* no, char campo[3][3]){
        printf("Estou no node: %d\n", v);
        v++;
    if (no == NULL || no->livre == 0){
        return;
    }
    
    char jog;
    int next;
    if(no->mm = 0){
        jog = 'x';
    }
    else{
        jog = 'o';
    }
    for (int i = 0; i<3; i++){
        for(int j = 0; j < 3; j++){
            if(campo[i][j] == ' '){
                campo[i][j] = jog;
                goto aqui;
            }

        }
    }
    aqui:
    if(no->mm == 1){
        next = 0;
    }
    else if(no->mm == 0)
        next = 1;
    
    //printf("%c\n", jog);
    no->filhos = (velha**)calloc(no->livre, sizeof(velha*));
    for(int i = 0; i < no->livre; i++){
        no->filhos[i] = (velha*) calloc(no->livre, sizeof(velha));
        no->filhos[i]->livre = no->livre - 1;
        no->filhos[i]->mm = next;
        buildtree(no->filhos[i], campo);

    }
    


}

velha* newGame(){
    velha* teste;
    int i = 0;
    teste = (velha*) calloc(1, sizeof(velha));
    teste->livre=9;
    teste->mm=0;
    char campo[3][3];
    buildtree(teste, campo);
    return teste;
}



char verifica (char campo[][3]){
    if(!campo){
        return -1;
    }

    int lx = 0;
    int lb = 0;
    int cb = 0;
    int cx = 0;

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(campo[i][j] == 'x'){
                lx++;
            }
            else if(campo[i][j] == 'o'){
                lb++;
            }
            if(campo[j][i] == 'x'){
                cx++;
            }
            else if(campo[j][i] == 'o'){
                cb++;    
        }
        if(lx == 3 || cx == 3)
            return 'x';
        if(lb == 3 || cb == 3)
            return 'o';    

        
    }
        lx = 0;
        lb = 0;
        cb = 0;
        cx = 0;
    }
    return 'n';
}

int main(){
    newGame();
    char c[3][3];
    
    c[0][0] = 'x';
    c[0][1] = 'x';
    c[0][2] = 'x';
    //printf("%c ganhou", verifica(c));
}