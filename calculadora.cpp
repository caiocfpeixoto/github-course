#include <iostream>
#include <math.h>

using namespace std;

void calculadora(long long int x, char sinal, long long int y){

    if(sinal == '+'){
        cout << "= "<< x + y << "\n" << endl;
    }
    else if(sinal == '-'){
        cout << "= "<< x - y << "\n" << endl;
    }
    else if(sinal == 'x'){
        cout << "= "<< x * y << "\n" << endl;
    }
    else if(sinal == '/'){
        if(y == 0){
            cout << "Divisao invalida" << "\n" << endl;
        }
        else{
            cout << "= "<< x / y << " (Resto = " << x % y << ") "<< "\n" << endl;
        }
    }
    else if(sinal == '^'){
        cout << "= " << pow(x, y) << "\n" << endl;
    }
    else{
        cout << "Operacao invalida" << "\n" << endl;
    }
}

int main(){

    char op = ' ';
    long long int num1 = 0.0;
    long long int num2 = 0.0;
    long long int result = 0.0;

    cout << "CALCULADORA DE NUMEROS INTEIROS" << "\n" << endl;
    cout << "Operacoes possiveis:" << endl;
    cout << "(+) --> Soma" << endl;
    cout << "(-) --> Subtracao" << endl;
    cout << "(x) --> Multiplicacao" << endl;
    cout << "(/) --> Divisao" << endl;
    cout << "(^) --> Exponenciacao" << "\n" << endl;

     while(true){

        cin >> num1 >> op >> num2;

        calculadora(num1, op, num2);
    }
}


