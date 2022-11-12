//JOSUÉ HASS PEREIRA - PROVA2

////////////BIBLIOTECAS////////////
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>


////////////BANCO DE CADASTRO DO ALUNO////////////
typedef struct cadastro_aluno{
    int id;
    char nome_aluno[50];
    int deleted;
} aluno;


////////////BANCO DE CADASTRO DA NOTA////////////
typedef struct cadastro_nota{
    int id_aluno;
    int id_nota;
    float vl_nota;
}nota;


////////////VARIAVEIS GLOBAIS////////////
int qtd_aluno = 0;
char novNome[50];
aluno alunos[10];
nota notas[30];




////////////FUNCAO PARA ARMAZENAR O CADASTRO NA STRUCT (ALUNO)////////////
void cadastrar(){
    int res;
    
    qtd_aluno++;
    alunos[qtd_aluno].id = qtd_aluno;//Definir ID do aluno automaticamente
    printf("\n\n----CADASTRO DE ALUNOS----\n");
    do{
        printf("\nCódigo do aluno: %i\n", qtd_aluno);
        printf("Digite o nome do aluno: ");
        fgets(alunos[qtd_aluno].nome_aluno, 50, stdin);
        if(strlen(alunos[qtd_aluno].nome_aluno) <= 4){//Validando para ACEITAR somentes nomes com mais de 3 letras
            printf("Error!Por favor, insira um nome válido!\n");
        }
        
    }while(strlen(alunos[qtd_aluno].nome_aluno) <= 4);
    alunos[qtd_aluno].deleted = 1;//"Ativando" o cadastro do aluno (Deleted = 1 --- TRUE)
    printf("\n---Aluno Cadastrado com sucesso!---\n");
}


////////////FUNCAO PARA PERCORRER A STRUCT E PRINTAR////////////
void consultarAluno(){
    int i, bsc;
    printf("\n\n----CONSULTA DE ALUNOS----\n");
    printf("Código do aluno: ");
    scanf("%i", &bsc);
    for(i=1;i<=qtd_aluno;i++){//Caso haja 1 cadastro, o for vai rodar
        
        if((bsc == alunos[i].id) && (alunos[i].deleted == 1)){//Retorna TRUE se os alunos estao ativos/busca igual o id
            printf("Aluno: %s", alunos[i].nome_aluno);
        } else if(alunos[i].deleted == 0 && bsc == alunos[i].id){//Retorna TRUE se o aluno extiver desativado (Deleted = 0 --- TRUE)
            printf("!!Aluno não existe na base!!Voltando para o menu inicial...\n");
        }
    }
    if(qtd_aluno==0 || (bsc > qtd_aluno)){//Retorna TRUE se não houver cadastro/busca maior que o ultimo ID criado 
        printf("!!Aluno não existe na base!!Voltando para o menu inicial...\n");   
    }
}


////////////FUNCAO PARA DELETAR O CADASTRO DO AlUNO////////////
void deletarAlun(){
    char confExc[2];
    int i, bsc;
    printf("\n\n----DELETAR ALUNO----\n");
    printf("Código do aluno: ");
    scanf("%i", &bsc);
    getchar();
    for(i=1;i<=qtd_aluno;i++){
        if((bsc == alunos[i].id) && (alunos[i].deleted == 1)){
            printf("Aluno: %sConfirmar Exclusão?\n[S]im - [N]ão\n", alunos[i].nome_aluno);
            fgets(confExc, 2, stdin);
            confExc[0] = toupper(confExc[0]);
            
            if(strcmp(confExc, "S") == 0){
                alunos[i].deleted = 0;
                printf("\n---Aluno Deletado com sucesso!---\n");
            }else if(strcmp(confExc, "N") == 0){
                printf("!!Operação cancelada!!Voltando para o menu inicial...\n");
            }
        }else if((alunos[i].deleted == 0 && bsc == alunos[i].id) || bsc > qtd_aluno){
            printf("!!Aluno não existe na base!!Voltando para o menu inicial...\n");
        }
    }
    if(qtd_aluno==0){
        printf("!!Aluno não existe na base!!Voltando para o menu inicial...\n");   
    }
}


////////////FUNCAO PARA ALTERAR O CADASTRO DO ALUNOS////////////
void alterarAlun(){
    char confExc[2];
    int i, bsc;

    printf("\n\n----ALTERAR CADASTRO DO ALUNO----\n");
    printf("Código do aluno: ");
    scanf("%i", &bsc);
    getchar();
    
    for(i=1;i<=qtd_aluno;i++){
        if((bsc == alunos[i].id) && (alunos[i].deleted == 1)){
            printf("Aluno: %sNovo nome: ", alunos[i].nome_aluno);
            fgets(novNome, 50, stdin);
            printf("Confirmar Alteração?\n[S]im - [N]ão\n");
            fgets(confExc, 2, stdin);
            
            confExc[0] = toupper(confExc[0]);
            if(strcmp(confExc, "S") == 0){
                strcpy(alunos[i].nome_aluno, novNome);
                printf("\n---Nome alterado com sucesso!---\n");
            }else if(strcmp(confExc, "N") == 0){
                printf("!!Operação cancelada!!Voltando para o menu inicial...\n");
            }
        }else if(alunos[i].deleted == 0 && bsc == alunos[i].id){
                printf("!!Aluno não existe na base!!Voltando para o menu inicial...\n");
        }
    }
    if(qtd_aluno==0 || (bsc > qtd_aluno)){
        printf("!!Aluno não existe na base!!Voltando para o menu inicial...\n");   
    }
}


menuAlun(){
	int opcAlun;
	printf("\n1 - Cadastrar\n2 - Consultar por id\n3 - Excluir por id\n4 - Alterar por id\n5 - Relatório\n6 - Voltar\n");
    printf("\nEscolha: ");
    scanf("%i", &opcAlun);
    getchar();
    switch(opcAlun){
        case 1: cadastrar();break;
        case 2: consultarAluno();break;
        case 3: deletarAlun();break;
        case 4: alterarAlun();break;
        case 5: ;
        case 6: ;
	}
}





////////////MAIN////////////
int main()
{
    int opc, opcNot, opcRel;
    setlocale(LC_ALL,"Portuguese");//FUNCAO PARA PERMITIR ACENTUAÇÃO
    
    printf("\n---------UNIVERSIDADE DO ESTADO DE SANTA CATARINA---------\n");
    do{
        printf("\n--MENU--");
        printf("\n1 - Alunos\n2 - Notas\n3 - Relatório\n4 - Sair\n");
        printf("\nEscolha: ");
        scanf("%i", &opc);
        //getchar();

        if(opc < 1 || opc > 4){
            printf("\n!!!!Digite uma opção valida!!!!\n");
        }

        switch(opc){
            case 1: menuAlun(); break;
            case 2: menuNota(); break;
                printf("\n1 - Incluir nota do Aluno\n2 - Alterar nota do Aluno\n3 - Excluir nota do Aluno\n4 - Consultar nota do Aluno\n5 - Voltar");
                printf("\nEscolha: ");
                scanf("%i", &opcNot);
            case 3:
                printf("\n1 - Relatório de notas\n2 - Relatório de Médias\n3 - Voltar");
                printf("\nEscolha: ");
                scanf("%i", &opcRel);


        }
    }while(opc != 4);
    return 0;
}
