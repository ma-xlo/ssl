/*
//1) Exibir o sistema;

//2) Exibir o resultado do determinante;

3) Prever e fazer teste para os possíveis erros (erro de digitação e outros);

9) Exibir a solução do sistema utilizando a Regra de Cramer.

*/

#include <iostream>
#include <string>
#include <malloc.h>
#include <locale.h>

using namespace std;

void preencheSistema2 (float matriz[2][4], int opcao) {
    char coef[2] = {'x', 'y'}; 

    for(int i = 0; i < opcao + 1; i++) {
        cout << "Expressão " << i+1 << endl;
        for(int j = 0; j < opcao + 1; j++) {
            cout << "  Coeficiente da variável " << coef[j] << ": ";
            //_flushall();
            cin >> matriz[i][j];

            if( j == 1 ) {
                cout << "  Resultado" << ": ";
                cin >> matriz[i][2];

            }
        }
    }
}

float * determinante2(float matriz[2][4]) 
{
    
    float * detGeral;
    detGeral = (float *)malloc(3 * sizeof(float));
    
    detGeral[0] = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];

    //Determinante de x
    detGeral[1] = matriz[0][2] * matriz[1][1] - matriz[1][2] * matriz[0][1];
    
    //Determinante de y
    detGeral[2] =  matriz[0][0] * matriz[1][2] - matriz[0][2] * matriz[1][0];
    
    return detGeral;
}

void imprimeSistema2 (float matriz[2][4], int opcao) 
{
    char coef[2] = {'x', 'y'}; 
    char tecla;

    cout << endl << "Sistema inserido:" << endl;

    for(int i = 0; i < opcao + 1; i++) {
        for(int j = 0; j <= opcao + 1; j++) {
            if (matriz[i][j] < 0)
                cout << "+ " << "(" << matriz[i][j] << coef[j] << ")" << " ";
            else 
                cout << "+ " << matriz[i][j] << coef[j] << " ";


            if( j == 1) {
                cout << "= " << matriz[i][2] << endl;
                break;
            }
        }
    }
}

void preencheSistema3 (float matriz[3][4], int opcao) {
    char coef[3] = {'x', 'y', 'z'}; 

    for(int i = 0; i < opcao + 1; i++) {
        cout << "Expressão " << i+1 << endl;
        for(int j = 0; j < opcao + 1; j++) {
            cout << "  Coeficiente da variável " << coef[j] << ": ";
            //_flushall();
            cin >> matriz[i][j];

            if( j == 2 ) {
                cout << "  Resultado" << ": ";
                cin >> matriz[i][3];

            }
        }
    }
}

float * determinante3(float matriz[3][4]) 
{
    
    float * detGeral;
    detGeral = (float *)malloc(4 * sizeof(float));
    
    //Determinante geral
    detGeral[0] = 
    (matriz[0][0] * matriz[1][1] * matriz[2][2] + matriz[0][1] * matriz[1][2] * matriz[2][0] + matriz[0][2] * matriz[1][0] * matriz[2][1]) 
    - (matriz[0][2] * matriz[1][1] * matriz[2][0] + matriz[0][0] * matriz[1][2] * matriz[2][1] + matriz[0][1] * matriz[1][0] * matriz[2][2]); 

    //Determinante de x
    detGeral[1] = 
    (matriz[0][3] * matriz[1][1] * matriz[2][2] + matriz[0][1] * matriz[1][2] * matriz[2][3] + matriz[0][2] * matriz[1][3] * matriz[2][1]) 
    - (matriz[0][2] * matriz[1][1] * matriz[2][3] + matriz[0][3] * matriz[1][2] * matriz[2][1] + matriz[0][1] * matriz[1][3] * matriz[2][2]);
    
    //Determinante de y
    detGeral[2] = 
    (matriz[0][0] * matriz[1][3] * matriz[2][2] + matriz[0][3] * matriz[1][2] * matriz[2][0] + matriz[0][2] * matriz[1][0] * matriz[2][3])
    - (matriz[0][2] * matriz[1][3] * matriz[2][0] + matriz[0][0] * matriz[1][2] * matriz[2][3] + matriz[0][3] * matriz[1][0] * matriz[2][2]);
    
    //Determinante de y

    detGeral[3] =
    (matriz[0][0] * matriz[1][1] * matriz[2][3] + matriz[0][1] * matriz[1][3] * matriz[2][0] + matriz[0][3] * matriz[1][0] * matriz[2][1]) 
    - (matriz[0][3] * matriz[1][1] * matriz[2][0] + matriz[0][0] * matriz[1][3] * matriz[2][1] + matriz[0][1] * matriz[1][0] * matriz[2][3]);

    return detGeral;
}

void imprimeSistema3 (float matriz[3][4], int opcao) 
{
    char coef[3] = {'x', 'y', 'z'}; 

    cout << endl << "Sistema inserido:" << endl;

    for(int i = 0; i < opcao + 1; i++) {
        for(int j = 0; j <= opcao + 1; j++) {
            if (matriz[i][j] < 0)
                cout << "+ " << "(" << matriz[i][j] << coef[j] << ")" << " ";
            else 
                cout << "+ " << matriz[i][j] << coef[j] << " ";


            if( j == 2) {
                cout << "= " << matriz[i][3] << endl;
                break;
            }
        }
    }
}

int main() {

    setlocale(LC_ALL, "");

    int opcao = 0;

    do {
            system("clear");          
            cout << "  +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
            cout << "  |     Solucionador de Sistema Lineares      |" << endl;
            cout << "  +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
            cout << "  |                                           |" << endl;
            cout << "  |           +====== Menu ======+            |" << endl;
            cout << "  |           |                  |            |" << endl;
            cout << "  |             [1] 2 Variáveis               |" << endl;
            cout << "  |             [2] 3 Variáveis               |" << endl;
            cout << "  |             [0] Sair                      |" << endl;
            cout << "  |           |                  |            |" << endl;
            cout << "  |           +------------------+            |" << endl;
            cout << "  |                                           |" << endl;
            cout << "  |                                versão 1.0 |" << endl;
            cout << "  +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
            cout << "\n\t\t   Opção: ";
            //_flushall();
            cin >> opcao;

            float matriz[opcao + 1][4], *det, x, y, z;
            char tecla;
            //matriz = (float **) malloc((opcao + 1) * sizeof(float));

            switch (opcao)
            {
                case 1:
                    system("clear");
                    preencheSistema2(matriz, opcao);
                    imprimeSistema2(matriz, opcao);
                    det = determinante2(matriz);

                    x = det[1] / det[0];
                    y = det[2] / det[0];

                    cout << endl << "Determinante: " << det[0] << endl;
                    cout << "Valor x: " << x << endl;
                    cout << "Valor y: " << y << endl;

                    cout << endl << "Pressione enter para retornar ao menu..." << endl;
                    if(tecla != '\n') {
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) { }
                        scanf("%c", &tecla);
                        break;
                    }

                case 2:
                    system("clear");
                    preencheSistema3(matriz, opcao);
                    imprimeSistema3(matriz, opcao);
                    det = determinante3(matriz);

                    x = det[1] / det[0];
                    y = det[2] / det[0];
                    z = det[3] / det[0];

                    cout << endl << "Determinante: " << det[0] << endl;
                    cout << "Valor x: " << x << endl;
                    cout << "Valor y: " << y << endl;
                    cout << "Valor z: " << z << endl;

                    cout << endl << "Pressione enter para retornar ao menu..." << endl;
                    
                    if(tecla != '\n') {
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) { }
                        scanf("%c", &tecla);
                        break;
                    }
                    
                case 0: 
                    return 0;
            }
    } while(opcao != 0);
}

// 1 2 1 0
// 2 -1 1 1
// -1 3 1 -2