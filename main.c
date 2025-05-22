#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hashLinear(int k, int m, int *v) // função para a sondagem linear
{
    int c = 0;        // contador de colisões
    int i = k % m;    // calcula o endereço inicial
    while (v[i] != 0) // se o endereço estiver ocupado
    {
        i = (i + 1) % m; // realiza a sondagem linear
        c++;
        if (c == m)
        {
            printf("A tabela está totalmente preencida, e não é possível inserir o elemento %d\n", k);
            return; // se a tabela estiver cheia, retorna
        } // icrementa o contador de colisões
    }
    v[i] = k; // armazena o valor no vetor
}

void hashLista(int k, int m, int *v) // função para o endereço fechado
{
}

int main()
{
    int m = 0, op = 0, num = 0, ch; // inicialização das variaveis

    FILE *fp = fopen("/home/fels/Documentos/POD/Trabalho2/dados.txt", "r"); // Abertura do arquivo dados.txt
    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo dados.\n");
        exit(1);
    }
    else
    {
        printf("Arquivo dados aberto com sucesso.\n");
    }

    while ((ch = fgetc(fp)) != '\n') // realizado a leitura do arquivo
    {
        if (ch >= '0' && ch <= '9')
        {
            m = m * 10 + (ch - '0');
        }
        else if (ch == '\n')
        {
            break;
        }
    }

    int *v = malloc(m * sizeof(int)); // vetor de tamanho m
    for (int i = 0; i < m; i++)
    {
        v[i] = 0; // inicializando o vetor com 0
    }

    while ((ch = fgetc(fp)) != '\n') // realizando a leitura do arquivo
    {
        if (ch >= '0' && ch <= '9')
        {
            op = op * 10 + (ch - '0'); // armazenando o valor da opção escolhida
        }
        else if (ch == '\n')
        {
            break;
        }
    }

    if (op == 1) // condição para a sondagem linear
    {
        while ((ch = fgetc(fp)) != EOF) // realizando a leitura do arquivo
        {
            if (ch >= '0' && ch <= '9')
            {
                num = num * 10 + (ch - '0'); // armazenando o valor do numero
            }
            else if (ch == ';')
            {
                hashLinear(num, m, v); // chamando a função hashLinear
                num = 0;               // zerando o numero
            }
        }
    }
    else if (op == 0) // condição para a lista encadeada
    {
        while ((ch = fgetc(fp)) != EOF) // realizando a leitura do arquivo
        {
            if (ch >= '0' && ch <= '9')
            {
                num = num * 10 + (ch - '0'); // armazenando o valor do numero
            }
            else if (ch == ';')
            {
                hashLista(num, m, v); // chamando a função hashLista
                num = 0;              // zerando o numero
            }
        }
    }
    if (op == 1) // condição para a sondagem linear
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d : %d\n", i, v[i]); // imprimindo o vetor
        }
    }
    else if (op == 0) // imprimindo o vetor de lista encadeada
    {
    }

    free(v);    // liberando a memória alocada
    fclose(fp); // fechando o arquivo
    return 0;   // finalizando o programa
}
