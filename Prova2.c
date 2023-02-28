#include <stdio.h>

#define N_ALUNOS 6

void acrescentar_ponto_alunas(float notas[2][N_ALUNOS], char sexo[2][N_ALUNOS]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N_ALUNOS; j++) {
            if (sexo[i][j] == 'F') {
                notas[i][j] += 1.0;
            }
        }
    }
}
void adicionar_aluno(char nomes[2][N_ALUNOS][50], char sexo[2][N_ALUNOS], float notas[2][N_ALUNOS]) {
    int equipe, index;
    printf("Em qual equipe deseja adicionar o novo aluno? (Digite 1 ou 2): ");
    scanf("%d", &equipe);
    printf("Qual o nome do novo aluno? ");
    scanf("%s", nomes[equipe - 1][N_ALUNOS - 1]);
    printf("Qual o sexo do novo aluno? (Digite 'M' ou 'F'): ");
    scanf(" %c", &sexo[equipe - 1][N_ALUNOS - 1]);
    printf("Qual a nota final do novo aluno? ");
    scanf("%f", &notas[equipe - 1][N_ALUNOS - 1]);
}

int main() {
    
    char nomes[2][N_ALUNOS][50] = {
        {"Ana", "Bianca", "Carla", "Daniela", "Elena", "Fabiana"},
        {"Gabriela", "Helena", "Isabela", "Henrique", "Jonas", "Leo"}
    };

    char sexo[2][N_ALUNOS] = {
        {'F', 'F', 'F', 'F', 'F', 'F'},
        {'F', 'F', 'F', 'M', 'M', 'M'}
    };

    float notas[2][N_ALUNOS] = {
        {9.0, 8.5, 7.0, 9.5, 8.0, 7.5},
        {8.0, 7.5, 9.0, 6.5, 7.0, 8.5}
    };
    
    acrescentar_ponto_alunas(notas, sexo);

    adicionar_aluno(nomes, sexo, notas);

    
    int n_mulheres_e1 = 0, n_mulheres_e2 = 0;
    for (int i = 0; i < N_ALUNOS; i++) {
        if (sexo[0][i] == 'F') {
            n_mulheres_e1++;
        }
        if (sexo[1][i] == 'F') {
            n_mulheres_e2++;
        }
    }

    printf("Equipe 1 tem %d mulheres\n", n_mulheres_e1);
    printf("Equipe 2 tem %d mulheres\n", n_mulheres_e2);

   
    char alunas_selecionadas[12][50];
    int n_alunas_selecionadas = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N_ALUNOS; j++) {
            if (sexo[i][j] == 'F' && notas[i][j] >= 8.0) {
                strcpy(alunas_selecionadas[n_alunas_selecionadas], nomes[i][j]);
                n_alunas_selecionadas++;
            }
        }
    }

  
    printf("Alunas selecionadas:\n");
    for (int i = 0; i < n_alunas_selecionadas; i++) {
        printf("- %s\n", alunas_selecionadas[i]);
    }

    return 0;
}
