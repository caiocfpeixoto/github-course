#include <iostream>

using namespace std;

double acoes[11] = {21.85, 40.74, 82.06, 25.64, 25.45, 41.70, 17.92, 19.01, 27.81, 56.20, 36.87};
double fiis[8] = {111.30, 116.11, 208.05, 166.80, 150.75, 129.50, 172.26, 148.68};

double totalCost(int quantity, double costPrice){
    double value = 0.0;

    value = costPrice * quantity;

    return value;
}

double totalPatriAcoes(string assetCode, int quantity){
    double value = 0.0;

    if(assetCode == "ITUB3"){
        value = acoes[0] * quantity;
    }
    else if(assetCode == "EGIE3"){
        value = acoes[1] * quantity;
    }
    else if(assetCode == "WEGE3"){
        value = acoes[2] * quantity;
    }
    else if(assetCode == "MGLU3"){
        value = acoes[3] * quantity;
    }
    else if(assetCode == "RADL3"){
        value = acoes[4] * quantity;
    }
    else if(assetCode == "LREN3"){
        value = acoes[5] * quantity;
    }
    else if(assetCode == "ENBR3"){
        value = acoes[6] * quantity;
    }
    else if(assetCode == "BBDC3"){
        value = acoes[7] * quantity;
    }
    else if(assetCode == "FLRY3"){
        value = acoes[8] * quantity;
    }
    else if(assetCode == "B3SA3"){
        value = acoes[9] * quantity;
    }
    else if(assetCode == "MDIA3"){
        value = acoes[10] * quantity;
    }
    else{
        value = 0.0;
    }

    return value;
}

double totalPatriFIIs(string assetCode, int quantity){
    double value = 0.0;

    if(assetCode == "XPML11"){
        value = fiis[0] * quantity;
    }
    else if(assetCode == "VISC11"){
        value = fiis[1] * quantity;
    }
    else if(assetCode == "HGBS11"){
        value = fiis[2] * quantity;
    }
    else if(assetCode == "KNRI11"){
        value = fiis[3] * quantity;
    }
    else if(assetCode == "HGRE11"){
        value = fiis[4] * quantity;
    }
    else if(assetCode == "HGRU11"){
        value = fiis[5] * quantity;
    }
    else if(assetCode == "HGLG11"){
        value = fiis[6] * quantity;
    }
    else if(assetCode == "GGRC11"){
        value = fiis[7] * quantity;
    }
    else{
        value = 0.0;
    }

    return value;
}


void lista(){
    cout << "Lista de Acoes" << "     Lista de FIIs"<< endl;
    cout << "ITUB3 R$ 21,85" << "     XPML11 R$ 111,30" << endl;
    cout << "EGIE3 R$ 40,74" << "     VISC11 R$ 116,11" << endl;
    cout << "WEGE3 R$ 82,06" << "     HGBS11 R$ 208,05" << endl;
    cout << "MGLU3 R$ 25,64" << "     KNRI11 R$ 166,80" << endl;
    cout << "RADL3 R$ 25,45" << "     HGRE11 R$ 150,75" << endl;
    cout << "LREN3 R$ 41,70" << "     HGRU11 R$ 129,50" << endl;
    cout << "ENBR3 R$ 17,92" << "     HGLG11 R$ 172,26" << endl;
    cout << "BBDC3 R$ 19,01" << "     GGRC11 R$ 148,68" << endl;
    cout << "FLRY3 R$ 27,81" << endl;
    cout << "B3SA3 R$ 56,20" << endl;
    cout << "MDIA3 R$ 36,87" << endl;
}

int main(){
    cout << "BEM VINDO AO PATRIMONIUM!" << "\n\n";
    cout << "--------MENU INICIAL--------" << endl;
    cout << "O que deseja fazer? Digite o numero indicado para o procedimento que sera realizado:" << endl;
    cout << "(1) - Ver lista de ativos e suas cotacoes do dia" << endl;
    cout << "(2) - Fazer um lancamento manual" << endl;
    cout << "(3) - Fechar o aplicativo" << "\n" << endl;

    int opcoes = 0;
    int quantidade = 0;
    int numAcoes = 0;
    int numFIIs = 0;
    double precoDoAtivo = 0.0;
    double custoAtivo = 0.0;
    double custoTotal = 0.0;
    double patrimonioAtivo = 0.0;
    double patrimonioTotal = 0.0;
    double variacao = 0.0;
    double patrimonioAcoes = 0.0;
    double patrimonioFIIs = 0.0;
    string codigo = " ";

    while(opcoes != 3){
        cin >> opcoes;
        cout << "\n";
        if(opcoes == 1){
            lista();
            cout << "\n";
        }
        else if(opcoes == 2){
            cout << "Escolha o tipo de ativo digitando o codigo do procedimento a ser realizado:" << endl;
            cout << "(1) - Acoes" << endl;
            cout << "(2) - FIIs" << "\n" << endl;
            int segundaOpcao;
            cin >> segundaOpcao;
            cout << "\n";

            if(segundaOpcao == 1){
                cout << "Digite o codigo da Acao: ";
                cin >> codigo;
                cout << "Quantidade: ";
                cin >> quantidade;
                cout << "Preco de custo: ";
                cin >> precoDoAtivo;

                custoAtivo = totalCost(quantidade, precoDoAtivo);
                patrimonioAtivo = totalPatriAcoes(codigo, quantidade);

                if(custoAtivo != 0 && patrimonioAtivo != 0){
                    custoTotal += custoAtivo;
                    patrimonioAcoes += patrimonioAtivo;
                    patrimonioTotal += patrimonioAtivo;
                    variacao = patrimonioTotal - custoTotal;
                    numAcoes++;

                    cout << "\n\n";
                    cout << "DADOS CONSOLIDADOS" << endl;
                    cout << "Custo Total: " << custoTotal << endl;
                    cout << "Patrimonio: " << patrimonioTotal << endl;
                    cout << "Variacao Atual: " << variacao << endl;
                    cout << "Variacao: " << (patrimonioTotal / custoTotal - 1) * 100 << "%\n\n" << endl;

                    cout <<"POSICAO NA CARTEIRA" << endl;
                    cout << "ACOES    " << numAcoes << " ativo(s) ";
                    cout << (patrimonioAcoes / patrimonioTotal) * 100 << "%  R$ " << patrimonioAcoes << "\n\n" << endl;
                    cout << "FIIs    " << numFIIs << " ativo(s) ";
                    cout << (patrimonioFIIs / patrimonioTotal) * 100 << "%  R$ " << patrimonioFIIs << "\n\n" << endl;

                    cout << "--------MENU INICIAL--------" << endl;
                    cout << "O que deseja fazer? Digite o numero indicado para o procedimento que sera realizado:" << endl;
                    cout << "(1) - Ver lista de ativos e suas cotacoes do dia" << endl;
                    cout << "(2) - Fazer um lancamento manual" << endl;
                    cout << "(3) - Fechar o aplicativo" << "\n" << endl;
                    }
                else{
                    cout << "\n";
                    cout << "Operacao invalida!" << "\n" << endl;
                    cout << "--------MENU INICIAL--------" << endl;
                    cout << "O que deseja fazer? Digite o numero indicado para o procedimento que sera realizado:" << endl;
                    cout << "(1) - Ver lista de ativos e suas cotacoes do dia" << endl;
                    cout << "(2) - Fazer um lancamento manual" << endl;
                    cout << "(3) - Fechar o aplicativo" << "\n" << endl;
                }
            }
            else if(segundaOpcao == 2){
                cout << "Digite o codigo do FII: ";
                cin >> codigo;
                cout << "Quantidade: ";
                cin >> quantidade;
                cout << "Preco de custo: ";
                cin >> precoDoAtivo;

                custoAtivo = totalCost(quantidade, precoDoAtivo);
                patrimonioAtivo = totalPatriFIIs(codigo, quantidade);

                if(custoAtivo != 0 && patrimonioAtivo != 0){
                    custoTotal += custoAtivo;
                    patrimonioFIIs += patrimonioAtivo;
                    patrimonioTotal += patrimonioAtivo;
                    variacao = patrimonioTotal - custoTotal;
                    numFIIs++;

                    cout << "\n\n";
                    cout << "DADOS CONSOLIDADOS" << endl;
                    cout << "Custo Total: " << custoTotal << endl;
                    cout << "Patrimonio: " << patrimonioTotal << endl;
                    cout << "Variacao Atual: " << variacao << endl;
                    cout << "Variacao: " << (patrimonioTotal / custoTotal - 1) * 100 << "%\n\n" << endl;

                    cout <<"POSICAO NA CARTEIRA" << endl;
                    cout << "ACOES    " << numAcoes << " ativo(s) ";
                    cout << (patrimonioAcoes / patrimonioTotal) * 100 << "%  R$ " << patrimonioAcoes << endl;
                    cout << "FIIs    " << numFIIs << " ativo(s) ";
                    cout << (patrimonioFIIs / patrimonioTotal) * 100 << "%  R$ " << patrimonioFIIs << "\n\n" << endl;


                    cout << "--------MENU INICIAL--------" << endl;
                    cout << "O que deseja fazer? Digite o numero indicado para o procedimento que sera realizado:" << endl;
                    cout << "(1) - Ver lista de ativos e suas cotacoes do dia" << endl;
                    cout << "(2) - Fazer um lancamento manual" << endl;
                    cout << "(3) - Fechar o aplicativo" << "\n" << endl;
                }
                else{
                    cout << "\n";
                    cout << "Operacao invalida!" << "\n" << endl;
                    cout << "--------MENU INICIAL--------" << endl;
                    cout << "O que deseja fazer? Digite o numero indicado para o procedimento que sera realizado:" << endl;
                    cout << "(1) - Ver lista de ativos e suas cotacoes do dia" << endl;
                    cout << "(2) - Fazer um lancamento manual" << endl;
                    cout << "(3) - Fechar o aplicativo" << "\n" << endl;
                }

            }
            else{
                cout << "Operacao invalida" << "\n" << endl;
            }
        }
        else if(opcoes == 3){
            break;
        }
    }

}
