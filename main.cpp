#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <locale.h>

using namespace std;

void preencheSistema2 (float matriz[2][4], int opcao);
void imprimeSistema2 (float matriz[2][4], int opcao);
void preencheSistema3 (float matriz[3][4], int opcao);
void imprimeSistema3 (float matriz[3][4], int opcao);
float * determinante2(float matriz[2][4]); 
float * determinante3(float matriz[3][4]); 
void virgulaParaPonto(char * entrada);
void entradaDoSistema();
void solucaoDoSistema();

int main() {

    setlocale(LC_ALL, "");

    char tecla;
    int opcao = 0;
    float *det, x, y, z;

    do {
            system("cls");          
            cout << " +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
            cout << " |     Solucionador de Sistema Lineares      |" << endl;
            cout << " +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
            cout << " |                                           |" << endl;
            cout << " |           +====== Menu ======+            |" << endl;
            cout << " |           |                  |            |" << endl;
            cout << " |              [1] 2 Variáveis              |" << endl;
            cout << " |              [2] 3 Variáveis              |" << endl;
            cout << " |              [0] Sair                     |" << endl;
            cout << " |           |                  |            |" << endl;
            cout << " |           +------------------+            |" << endl;
            cout << " |                                           |" << endl;
            cout << " |                                           |" << endl;
            cout << " +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
            cout << "\n\t\t  Opção: ";
            _flushall();
            cin >> opcao;

            // Define o tamanho da matriz
            float matriz[opcao + 1][4];

            switch (opcao)
            {
                case 1:
                    system("cls");
                    entradaDoSistema();
                    preencheSistema2(matriz, opcao);
                    
                    do {

                        system("cls");
                        solucaoDoSistema();
                        imprimeSistema2(matriz, opcao);
                        det = determinante2(matriz);

                        x = det[1] / det[0];
                        y = det[2] / det[0];

                        cout << endl;
                        cout << " +----------------- Resultado ---------------+" << endl;
                        cout << "  Determinante: " << det[0] << endl;
                        cout << "  Valor de x: " << x << endl;
                        cout << "  Valor de y: " << y << endl;
                        cout << " +-------------------------------------------+" << endl;

                        cout << endl << "Pressione enter para retornar ao menu..." << endl;
                        _flushall();
                        scanf("%c", &tecla);

                    } while (tecla != '\n');

                    break;

                case 2:
                    system("cls");
                    entradaDoSistema();
                    preencheSistema3(matriz, opcao);
                    
                    do {
                        system("cls");
                        solucaoDoSistema();
                        imprimeSistema3(matriz, opcao);
                        det = determinante3(matriz);

                        x = det[1] / det[0];
                        y = det[2] / det[0];
                        z = det[3] / det[0];

                        cout << endl;
                        cout << " +----------------- Resultado ---------------+" << endl;
                        cout << "  Determinante: " << det[0] << endl;
                        cout << "  Valor de x: " << x << endl;
                        cout << "  Valor de y: " << y << endl;
                        cout << "  Valor de z: " << z << endl;
                        cout << " +-------------------------------------------+" << endl;

                        cout << endl << "Pressione enter para retornar ao menu..." << endl;
                        _flushall();
                        scanf("%c", &tecla);

                    } while (tecla != '\n');

                    break;
                    
                case 0: 
                    return 0;
            }
    } while(opcao != 0);
}

void preencheSistema2 (float matriz[2][4], int opcao) 
{
    char coef[2] = {'x', 'y'}, digito[5];
    int check = 0;

    void entradaDoSistema();

    for(int i = 0; i < opcao + 1; i++) {
        cout << " +- " << i+1 << "º Equação " << " -----------------------------+" << endl;
        for(int j = 0; j < opcao + 1; j++) {
            
            do {
                cout << "  Coeficiente da variável " << coef[j] << ": ";
                _flushall();
                cin >> digito;
                
                for(int i = 0; i < 5; i++) {
                    if(isalpha(digito[i])) { 
                        cout << "  *** Valor Inválido! ***" << endl;
                        check = 1;
                        break;
                    } else {
                        check = 0;
                        break;
                    }
                }
            } while (check);

            virgulaParaPonto(digito);
            matriz[i][j] = std::stof(digito);
            
            do {
                if( j == 1 ) {
                    cout << "  Resultado" << ": ";
                    _flushall();
                    cin >> digito;
                    
                    for(int i = 0; i < 5; i++) {
                        if(isalpha(digito[i])) { 
                            cout << "  *** Valor Inválido! ***" << endl;
                            check = 1;
                            break;
                        } else {
                            check = 0;
                            break;
                        }
                    }
                }
            } while (check);

            matriz[i][2] = std::stof(digito);

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

    cout << endl << " +------------- Sistema inserido ------------+" << endl << endl;

    for(int i = 0; i < opcao + 1; i++) {
        cout << "                ";
        for(int j = 0; j <= opcao + 1; j++) {
            if (matriz[i][j] < 0 && j != 0)
                cout << "+ " << "(" << matriz[i][j] << coef[j] << ")" << " ";
            else if (j == 0)
                cout << " " << matriz[i][j] << coef[j] << " ";
            else if (j == 0 && matriz[i][j] < 0)
                cout << " " << matriz[i][j] << coef[j] << " ";
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

    char coef[3] = {'x', 'y', 'z'}, digito[5]; 
    int check = 0;

    for(int i = 0; i < opcao + 1; i++) {
        cout << " +- " << i+1 << "º Equação " << " -----------------------------+" << endl;
        for(int j = 0; j < opcao + 1; j++) {
        
            do {
                cout << "  Coeficiente da variável " << coef[j] << ": ";
                _flushall();
                cin >> digito;
                for(int i = 0; i < 5; i++) {
                            if(isalpha(digito[i])) { 
                                cout << "  *** Valor Inválido! ***" << endl;
                                check = 1;
                                break;
                            } else {
                                check = 0;
                                break;
                            }
                        }
            } while (check);

            virgulaParaPonto(digito);
            matriz[i][j] = std::stof(digito);
            
            do {
                if( j == 2 ) {
                    cout << "  Resultado" << ": ";
                    _flushall();
                    cin >> digito;

                    for(int i = 0; i < 5; i++) {
                        if(isalpha(digito[i])) { 
                            cout << "  *** Valor Inválido! ***" << endl;
                            check = 1;
                            break;
                        } else {
                            check = 0;
                            break;
                        }
                    }
                }
            } while (check);
        }

        matriz[i][3] = std::stof(digito);

    }
}

void imprimeSistema3 (float matriz[3][4], int opcao) 
{
    char coef[3] = {'x', 'y', 'z'}; 

    cout << endl << " +------------- Sistema inserido ------------+" << endl << endl;
    for(int i = 0; i < opcao + 1; i++) {
        cout << "              ";
        for(int j = 0; j <= opcao + 1; j++) {
            if (matriz[i][j] < 0 && j != 0)
                cout << "+ " << "(" << matriz[i][j] << coef[j] << ")" << " ";
            else if (j == 0)
                cout << " " << matriz[i][j] << coef[j] << " ";
            else if (j == 0 && matriz[i][j] < 0)
                cout << " " << matriz[i][j] << coef[j] << " ";
            else 
                cout << "+ " << matriz[i][j] << coef[j] << " ";

            if( j == 2) {
                cout << "= " << matriz[i][3] << endl;
                break;
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

void virgulaParaPonto(char * entrada) {
    int i, tamEntrada = strlen(entrada);
    for(i = 0; i < tamEntrada; i++)
        if(entrada[i] == ',')
            entrada[i] = '.';

}

void entradaDoSistema(){
    cout << " +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
    cout << " |              Insira o Sistema             |" << endl;
    cout << " +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl << endl;
}

void solucaoDoSistema() {
    cout << " +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
    cout << " |             Solução do sistema            |" << endl;
    cout << " +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
}
