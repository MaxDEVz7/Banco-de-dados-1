#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <locale.h>
#include<ctype.h>

int main(){
	
	int op=0, mat[1000][1], i, registros=0, matop, opbusca=0,flag=0, flagstr[1000] = {0}, x, j; 
	char nome[1000][99], curso[1000][99], strbusca[99];
	
setlocale(LC_ALL,"Portuguese");
	
	printf("QUAL OPERA??O DESEJA FAZER:\n(1) Remo??o de dados\n(2) Inclus?o de dados\n(3) Apresenta??o de dados\n(4) Buscar dados\n(0) Sair\n");
	scanf("%d", &op);
	fflush(stdin);

	while(op>0){
	if (op==1 && registros>0){
	printf("Insira a matricula do aluno no qual ser? removido: ");
	scanf("%d", &matop);
	fflush(stdin);
	for(i=0; i<registros;i++){
	if (matop == mat[i][0]){
	mat[i][0]=0;
	strcpy(nome[i], "\0");
	strcpy(curso[i], "\0");
	registros--;
	flag=1;
			}
	}
	if (flag==0){
	printf("\nMatricula nao encontrada!\n");
	}
	
}
else if(op==1 && registros==0){
	printf("\nN?o ha registros para remover\n");
}
	
	else if(op==2){
	printf("Insira a matricula do aluno no qual ser? incluido: ");
	scanf("%d", &mat[registros][0]);
	fflush(stdin);
	switch(mat[registros][0]){
	case 0:
	printf("\nVALOR INSERIDO INVALIDO!\n");
	break;
	default:
	fflush(stdin);
	printf("Insira o nome do aluno no qual ser? incluido: ");
	fgets(nome[registros], sizeof(nome[registros]), stdin);
	fflush(stdin);
	printf("Insira o curso do aluno no qual ser? incluido: ");
	fgets(curso[registros], sizeof(curso[registros]), stdin);
	registros++;
	}
}
	else if(op==3 &&registros>0){
	for(i=0; i<registros; i++){
	printf("\nMATRICULA: %d\n", mat[i][0]);
	printf("NOME: %s", nome[i]);
	printf("CURSO: %s\n", curso[i]);
	}
}
	else if(op==3 &&registros<=0){
	printf("\nN?o ha registros para ser apresentados!\n");
	}
	
	else if (op==4){
	printf("Selecione por qual coluna deseja fazer a busca (1) matricula (2) nome (3) curso: ");
	scanf("%d", &opbusca);
	fflush(stdin);
	switch (opbusca){
	case 1:
	printf("\nDigite aqui a matricula de sua busca: ");
	scanf("%d", &matop);
	fflush(stdin);
	for(i=0; i<registros;i++){
	if (matop == mat[i][0]){
	printf("\nMATRICULA: %d\n", mat[i][0]);
	printf("NOME: %s", nome[i]);
	printf("CURSO: %s\n", curso[i]);
	flag=1;
	break;
	}
	else{
	flag=0;
	}
}
	if(flag==0){
	printf("\nMatricula nao encontrada!\n");
	}
	break;
	
	case 2:
	printf("\nDigite aqui o nome de sua busca: ");
	fgets(strbusca, sizeof(strbusca), stdin);
	for(i=0; i<registros;i++){
	for(x=0; x<strlen(nome[i]);x++){
	for(j=0; j<strlen(strbusca);j++){
	if(nome[i][x]==strbusca[j]){
	flagstr[i]++;
				}
			}
		}
	printf("%d", flagstr[i]);
	if(flagstr[i]>=strlen(strbusca)){
	printf("\nMATRICULA: %d\n", mat[i][0]);
	printf("NOME: %s\n", nome[i]);
	printf("CURSO: %s\n", curso[i]);
	}

	}
	break;
	case 3:
	printf("\nDigite aqui o curso de sua busca: ");
	fgets(strbusca, sizeof(strbusca), stdin);
	for(i=0; i<registros;i++){
	if(x==sizeof(curso[i])-sizeof(strbusca)){
	printf("\nMATRICULA: %d\n", mat[i][0]);
	printf("NOME: %s", nome[i]);
	printf("CURSO: %s\n", curso[i]);
	}
	}
	
	break;

	default:
	printf("Coluna invalida!\n");
}
	}

	else if(op>4 || op<0){
	printf("OPERA??O DIGITADA INVALIDA!\n\n");
	}
	
	printf("\n\nQUAL OPERA??O DESEJA FAZER:\n(1) Remo??o de dados\n(2) Inclus?o de dados\n(3) Apresenta??o de dados\n(4) Buscar dados\n(0) Sair\n");
	scanf("%d", &op);
	fflush(stdin);
	i=0;
	flag=0;
	matop=0;
	strcpy(strbusca, "\0");
	for(i=0; i<registros; i++){
	if(mat[i][0]==0){
	mat[i][0]=mat[i+1][0];
	strcpy(nome[i], nome[i+1]);	
	strcpy(curso[i], curso[i+1]);	
	}
	}
}
	if(op==0){
	printf("OPERA??O FINALIZADA, OBRIGADO!\n\n");
	}
	
	return 0;
}
