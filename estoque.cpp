#include<iostream>
#include<stdio.h> 
#include<locale>
#include<stdio_ext.h>//para limpar o buffer em linux "__fpurge(stdin)"
using namespace std;


struct estoque{
    string nomeProduto, dataValidade;
    double idProduto, valorProd;
	int quantidade;
};
estoque produtos[5];

void limparTela(){
    system("CLS");
} // função limpa tela;

void limparBuffer(){
    fflush(stdin);
	__fpurge(stdin);
    
} //função limparbuffer

int exebirMenu(){
    cout<<"Bem vindo ao nosso controle de estoque"<<endl;
    cout<<"0 - Sair do programa"<<endl;
    cout<<"1 - Cadastrar Produto"<<endl;
    cout<<"2 - Visualizar estoque"<<endl;
    cout<<"3 - Pesquisa"<<endl;
	cout<<"4 - Alterar dados"<<endl;
    cout<<"Insira sua opção desejada: ";
}

int sairPrograma(){

	cout<<"Obrigado por trabalhar conosco!";
    exit(0);
}

int cadastrarProduto(int quantProd){
    limparTela();
    int indice = quantProd;
    for(int i=0; i< indice; i++)
    {
    	limparBuffer();
        cout<<"Insira o id do produto: ";
        cin>>produtos[i].idProduto;
		limparBuffer();
        cout<<"Insira o nome do produto: ";
        limparBuffer();
		cout<<"Insira a quantidade de produtos: ";
		cin>>produtos[i].quantidade;
        getline(cin, produtos[i].nomeProduto);
        cout<<"Insira a validade do lote(Mês e Ano): ";
        limparBuffer();
		cin>>produtos[i].dataValidade;
        cout<<"Insira o valor do produto: ";
        cin>>produtos[i].valorProd;
        limparTela();
    } 
	return exebirMenu();
	}

int VisualizarEstoque(int quantProd){
	limparTela();	
	int indice = quantProd;
	for(int i=0; i<indice;i++)
	{	
		cout<<"------------------------------------"<<endl;
		cout<<"Numero do Cadastro: "<<i<<endl;
		cout<<"Nome: "<<produtos[i].nomeProduto<<endl;
		cout<<"ID: "<<produtos[i].idProduto<<endl;
		cout<<"Quantidade Produtos: "<<produtos[i].quantidade<<endl;
		cout<<"Data de Validade: "<<produtos[i].dataValidade<<endl;
		cout<<"Valor: "<<produtos[i].valorProd<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"\n\n";
		system("PAUSE");
	}
	return exebirMenu();	
}
int Pesquisa (int quantProd)
{
	limparTela();	
	int indice = quantProd, continuar;
	string resp;
	do{
	cout<<"Informe mêss e ano de validade: "<<endl;
	for (int i=0;i<indice;i++)
	{	
		cin>>resp;
		if(resp==produtos[i].dataValidade)
		{
		cout<<"-------Resultado da Pesquisa-------"<<endl;
		cout<<"Nome: "<<produtos[i].nomeProduto<<endl;
		cout<<"ID: "<<produtos[i].idProduto<<endl;
		cout<<"Quantidade de produtos: "<<produtos[i].quantidade<<endl;
		cout<<"Data de Validade: "<<produtos[i].dataValidade<<endl;
		cout<<"Valor: "<<produtos[i].valorProd<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"\n\n";
		system("PAUSE");
		}
		cout<<"Deseja fazer outra pesquisa ? "<<endl;
		cout<<"0 - Sair da pesquisa"<<endl;
		cout<<"1 - Continuar "<<endl;
		cin>>continuar;
	}}while(continuar!=0);
	return exebirMenu();	
}
 float alterarDados(){

	 int cad, op, resp;

	 cout<<"------------------------------------"<<endl;
	 cout<<"Insira o número de cadastro: ";
	 cin>>cad;
	 cout<<"Qual opção deseja alterar? "<<endl;
	 cout<<"0 - Voltar ao menu principal"<<endl;
	 cout<<"1 - Alterar Nome do produto."<<endl;
	 cout<<"2 - Alterar o ID do produto."<<endl;
	 cout<<"3 - Alterar quantidade de produtos."<<endl;
	 cout<<"4 - Alterar a data de validade do produto."<<endl;
	 cout<<"5 - Alterar o valor do produto."<<endl;
	 cout<<"------------------------------------"<<endl;
	 cin>>op;

		
			switch (op)
			{
			case 0:
				limparBuffer(); limparTela();
				exebirMenu();
			case 1:
				limparBuffer();
				cout<<"Qual o novo nome do produto? ";
				getline(cin, produtos[cad].nomeProduto);
				cout<<"Deseja fazer mais alguma alteração? 1 para sim, 0 para não: ";
				cin>>resp;
				limparBuffer();
				if(resp == 1)
					alterarDados();
				else 
					exebirMenu();
				break;
			case 2:
				limparBuffer();
				cout<<"Qual o novo ID do produto? ";
				cin>>produtos[cad].idProduto;
				limparBuffer();
				if(resp == 1)
					alterarDados();
				else 
					exebirMenu();
				break;
			case 3:
				limparBuffer();
				cout<<"Qual a quantidade de produtos: ";
				cin>>produtos[cad].quantidade;
				limparBuffer();
				if(resp == 1)
					alterarDados();
				else 
					exebirMenu();
			case 4:
				limparBuffer();
				cout<<"Qual a nova data de validade do produto? ";
				cin>>produtos[cad].dataValidade;
				break;
				limparBuffer();
				if(resp == 1)
					alterarDados();
				else 
					exebirMenu();
			case 5:
				limparBuffer();
				cout<<"Qual o	 novo valor do produto? ";
				cin>>produtos[cad].valorProd;
				break;
				limparBuffer();
				if(resp == 1)
					alterarDados();
				else 
					exebirMenu();
			default: alterarDados();
				break;
			}
 }

void RealizarVenda() {
	int produtoId = 0;
	int desconto = 0;
	float porcentagem_desconto = 0;
	bool voltar_ao_menu = false;

	// Define como -1, j� que o produto ainda n�o foi encontrado.
	int produtoIndice = -1;

	cout << "Insira o Id do produto para a venda." << endl;
	cin >> produtoId;

	cout << "Insira o valor do desconto no produto em porcentagem." << endl;
	cin >> desconto;

	// Divide por 100 para encontrar o n�mero quebrado.
	if (desconto) {
		porcentagem_desconto = (float)(desconto / 100);
	}

	// Procura pelo produto.
	for (int i = 0; i < 5; i++) {
		if (produtos[i].idProduto == produtoId) {
			produtoIndice = i;
			// Sai do la�o quando encontrado.
			break;
		}
	}

	// Se o �ndice do produto foi encontrado.
	if (produtoIndice >= 0) {
		// Verifica se h� a quantidade suficiente no estoque.
		if (produtos[produtoIndice].quantidade > 0) {
			// Realiza apenas uma venda.
			// Diminui em 1.
			produtos[produtoIndice].quantidade--;

			// Obtem o valor de acordo com a porcentagem.
			// Por exemplo, 0.5 multiplicado por 100 � 50.
			double valor_porcento_retirado = produtos[produtoIndice].valorProd * porcentagem_desconto;
			double valor_com_desconto = produtos[produtoIndice].valorProd - valor_porcento_retirado;

			cout << endl;
			cout << "Valor: " << produtos[produtoIndice].valorProd << " R$" << endl;
			cout << "Desconto: " << desconto << "%";
			cout << "Valor com o desconto: " << valor_com_desconto << " R$" << endl;

			cout << endl << "A venda foi efetuada." << endl;
			cout << "Ainda restam " << produtos[produtoIndice].quantidade << " unidade(s) do produto ";
			cout << produtos[produtoIndice].nomeProduto << " no estoque." << endl;
			
			voltar_ao_menu = true;
 		}
		else {
			cout << "Produto com quantidade insuficiente no estoque." << endl;
			voltar_ao_menu = true;
		}
	}
	else {	
		cout << "Produto n�o encontrado no estoque." << endl;
		voltar_ao_menu = true;
	}

	if (voltar_ao_menu) {
		cout << endl << "Pressione uma tecla para voltar ao menu" << endl;
		_getch();

		exibirMenu();
	}
}
int main(){
	setlocale(LC_ALL, "Portuguese");
    int op, total;
    exebirMenu();
   
	do{
		 cin>>op;
    switch(op)
    {
        case 0:
            sairPrograma();
            break;
        case 1:
            int quantProd;
            cout<<"Insira quantos produtos deseja cadastrar: ";
            cin>>quantProd; total = total + quantProd;
            cadastrarProduto(quantProd);
            
            break;
        case 2: 
            VisualizarEstoque(quantProd);
            break;
		case 3:
			Pesquisa (quantProd);      
	   		break; 
	    case 4:
			alterarDados();
            break;
		case 5:
			RealizarVenda();
			break;
            
        default : cout<<"Opção inválida tente novamente."<<endl;
    }}while(op!=0);

    
}
