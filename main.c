#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "funcoes.h"

int main()
{
    FILE *save_professor;
    Professor professor;
    Disciplina *disciplinas;

    //Criando diretório para os arquivos
    system("mkdir arquivos");

    //Checando se tem Usuario cadastrado se nao houver cria o usuario
    if(!(save_professor = fopen("arquivos/professor.dat", "r"))){
        professor = cad_professor(save_professor);
        disciplinas = cad_disciplina(professor.num_disc);
    }
    else{
        load_professor(save_professor, &professor);
        disciplinas = load_disciplinas(professor.num_disc);
    }
    menu(&professor, disciplinas, save_professor);

    return 0;
}

