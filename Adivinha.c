#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int modulo(int numero)
{
    if(numero < 0)
    {
        numero = numero * (-1);
    }
    return numero;
}

void abertura()
{
    printf("\n");
    printf("**************************************\n");
    printf("*Bem vindo ao nosso jogo de adivinha!*\n");
    printf("**************************************\n");
}

void dificuldade(int* tentativas)
{
    int nivel;
    printf("Qual o nível de dificuldade? 1-Fácil, 2-Médio e 3-Difícil\n");
    scanf("%d",&nivel);

    switch(nivel)
    {
        case 1:
            (*tentativas) = 20;
        break;
        case 2:
            (*tentativas) = 15;
        break;
        default:
            (*tentativas) = 5;
        break;
    }

    printf("Boa sorte!!\n");
}

int verifica_chutes(int* i, int tentativas,int* pontos,int numerosecreto)
{
    int chute, ganhou;
    ganhou = 0;
    printf("Tentativa %d de %d\n",(*i),tentativas);
    printf("Qual o seu chute?\n");
    scanf("%d",&chute);
    if(chute > 0)
    {
        (*pontos) -= modulo((chute - numerosecreto)/2);
        if(chute == numerosecreto)
        {
            ganhou = 1;
            return ganhou;
        }
        else if(chute > numerosecreto)
        {
            printf("Seu chute foi maior que o número secreto!\n");
        }
        else
        {
            printf("Seu chute foi menor que o número secreto!\n");
        }
    }
    else
    {
        printf("Você digitou um número que não é válido, tente de novo!\n");
        (*i)--;
    }

    return ganhou;
}

int escolhe_numero_secreto()
{
    int segundos, numero;

    segundos = time(0);
    srand(segundos);
    numero = rand();
    numero = numero % 100;

    return numero;
}

int main(void)
{
    int numerosecreto,tentativas,pontos,ganhou,i;

    ganhou = 0;
    pontos = 1000;
    i = 1;

    abertura();
    dificuldade(&tentativas);
    numerosecreto = escolhe_numero_secreto();
    do
    {
        ganhou = verifica_chutes(&i,tentativas,&pontos,numerosecreto);
        i++;
    }while(i <= tentativas && !ganhou);

    if(ganhou == 1)
    {
        printf("\n\n");
        printf("         />_________________________________\n");
        printf("[########[]_______________VITÓRIA__________/\n");
        printf("         />\n");
        printf("\n\n");
        printf("Você acertou em %d tentativas, PARABÉNS! Tu é muito bom nesse jogo, jogue de novo\n",i);
        printf("A sua pontuação foi de: %d pontos!\n",pontos);
    }
    else
    {
        printf("\n\n");
        printf("Você perdeu! Mas não desanime, tente de novo!\n");
    }
    printf("Fim de jogo!\n");
    return 0;
}