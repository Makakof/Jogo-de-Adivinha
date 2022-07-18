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

int main(void)
{
    int numerosecreto,chute,tentativas,pontos,segundos,nivel,ganhou,i;
    segundos = time(0);
    srand(segundos);

    numerosecreto = rand();
    numerosecreto = numerosecreto % 100;
    ganhou = 0;
    pontos = 1000;

    printf("\n");
    printf("**************************************\n");
    printf("*Bem vindo ao nosso jogo de adivinha!*\n");
    printf("**************************************\n");

    printf("Qual o nível de dificuldade? 1-Fácil, 2-Médio e 3-Difícil\n");
    scanf("%d",&nivel);

    switch(nivel)
    {
        case 1:
            tentativas = 20;
        break;
        case 2:
            tentativas = 15;
        break;
        default:
            tentativas = 5;
        break;
    }

    printf("Boa sorte!!\n");
    for(i = 1;i <= tentativas;i++)
    {
        printf("Tentativa %d de %d\n",i,tentativas);
        printf("Qual o seu chute?\n");
        scanf("%d",&chute);
        if(chute > 0)
        {
            pontos -= modulo((chute - numerosecreto)/2);
            if(chute == numerosecreto)
            {
                ganhou = 1;
                break;
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
            i--;
        }
    }
    if(ganhou == 1)
    {
        printf("         />_________________________________\n");
        printf("[########[]_______________VITÓRIA__________/\n");
        printf("         />\n");
        printf("\n\n");
        printf("Você acertou em %d tentativas, PARABÉNS! Tu é muito bom nesse jogo, jogue de novo\n",i);
        printf("A sua pontuação foi de: %d pontos!\n",pontos);
    }
    else
    {
        printf("Você perdeu! Mas não desanime, tente de novo!\n");
    }
    printf("Fim de jogo!\n");
    return 0;
}