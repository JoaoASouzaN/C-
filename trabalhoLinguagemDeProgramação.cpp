// Levi, Gabriel Setta, Jo�o Ant�nio de Souza, Henrique Augusto, Jo�o Victor Silva Nery.
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>


void separadorLinha(){
    printf("\n--------------------------------------------------------------------------------------------------------------------\n");
}

void colorRed(){ // cor do texto
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
}


void stats (char nickName[100], int vida, int energia, int municao, int orda, int itens, int vitorias, int derrotas){ // status do jogador
	system ("cls");
	separadorLinha();
	
	if(vida <= 0){
        vida = 0;
    }
    
    if(vida > 100){
        vida = 100;
    }
    
    if(energia <= 0){
        energia = 0;
    }
    
    if(energia > 100){
        energia = 100;
    }
    
    if(municao <= 0){
        municao = 0;
    }
    
    printf("Jogador(a): %s\n", nickName);
	printf("Sua vida atual �: %d\n", vida);
	printf("Sua energia atual �: %d\n", energia);
	printf("Sua muni��o atual �: %d\n", municao);
	printf("Itens coletados: %d\n", itens);
	printf("Ordas: %d\n", orda);
	printf("Vit�rias: %d\n", vitorias);
	printf("Derrotas: %d\n", derrotas);
	
	separadorLinha();
}

void statsDerrota (char nickName[100], int vida, int energia, int municao, int orda, int itens, int vitorias, int derrotas){ //status do jogador ao perder
	system ("cls");
	separadorLinha();
	
	if(vida <= 0){
        vida = 0;
    }
    
    if(vida > 100){
        vida = 100;
    }
    
    if(energia <= 0){
        energia = 0;
    }
    
    if(energia > 100){
        energia = 100;
    }
    
    if(municao <= 0){
        municao = 0;
    }
    
    printf("------------------- VOC� MORREU ---------------------\n");
    printf("Ap�s in�meras batalhas contra dezenas de criaturas, voc� cai desmaiado no ch�o!\n");
    printf("Ent�o, de repente voc� se levanta novamente na sua cama, e descobre que tudo n�o passava de um temebroso pesadelo...\n");
    printf("Jogador(a): %s\n", nickName);
	printf("Sua vida atual �: %d\n", vida);
	printf("Sua energia atual �: %d\n", energia);
	printf("Sua muni��o atual �: %d\n", municao);
	printf("Itens coletados: %d\n", itens);
	printf("Ordas: %d\n", orda);
	printf("Vit�rias: %d\n", vitorias);
	printf("Derrotas: %d\n", derrotas);
	
	separadorLinha();
}

int aleatorio(int aleatorio_max) { // aleatoriedade 
	int minimo = 0, maximo = aleatorio_max, num;
	srand(time(0));
	num = (rand() % (maximo - minimo + 1)) + minimo;
	return num;
}

int aleatorioItens(int aleatorio_min, int aleatorio_max) { // aleatoriedade dos itens
	int minimo = aleatorio_min, maximo = aleatorio_max, num;
	srand(time(0));
	num = (rand() % (maximo - minimo + 1)) + minimo;
	return num;
}


int aleatorioSenha(int maximo) { //aleatoriedade da senha
	int minimo = 9999, num;
	srand(time(0));
	num = (rand() % (maximo - minimo + 1)) + minimo;
	return num;
}

/* ----------------------------- fun��o da digita��o ---------------------------------*/

int digitacao(char texto[]){ // fun��o de digita��o
	int i = 0;
    while(texto[i] != '\0'){
        printf("%c", texto[i]);
        fflush(stdout);
        Sleep(0);
        i++;
    }
}

/* ----------------------------------------------------------------------------------*/


int main(){ // int main
    setlocale(LC_ALL, "Portuguese");
    colorRed();
    char nickName[100];
    int selecao;
    int vida=100, energia=100, municao=0, itens=0, fases=0, monstro=0, vitorias = 0, derrotas = 0;
    int baseball = 0, pistola=0;
    int chance_batalha;
    int spray;
    int senha, cofre;
    int selecaoQuartoPais;
    int key = 0, orda = 0;
    int energiaItens, municaoItens, remedioItens;
    int loopMonstro;
    
    separadorLinha();
    	
  printf(" ______   ______     ______     ______     __         __         ______     __            ______   ______     ______     ______     ______     __         ______    \n");
    printf("/\\  == \\ /\\  __ \\   /\\  == \\   /\\  __ \\   /\\ \\       /\\ \\       /\\  ___\\   /\\ \\          /\\  == \\ /\\  __ \\   /\\  == \\   /\\  __ \\   /\\  == \\   /\\ \\       /\\  ___\\   \n");
    printf("\\ \\  _-\\ \\ \\  __ \\  \\ \\  __<   \\ \\  __ \\  \\ \\ \\____  \\ \\ \\____  \\ \\  __\\   \\ \\ \\____     \\ \\  _-\\ \\ \\  __ \\  \\ \\  __<   \\ \\  __ \\  \\ \\  __<   \\ \\ \\____  \\ \\  __\\   \n");
    printf(" \\ \\_\\   \\ \\_\\ \\_\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\     \\ \\_\\    \\ \\_\\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\ \n");
    printf("  \\/_/    \\/_/\\/_/   \\/_/ /_/   \\/_/\\/_/   \\/_____/   \\/_____/   \\/_____/   \\/_____/      \\/_/     \\/_/\\/_/   \\/_/ /_/   \\/_____/   \\/_____/   \\/_____/   \\/_____/ \n");
    
    separadorLinha();
    
    /* ----------------------------- Boas vindas ---------------------------------*/
    
    digitacao("Bem-vindo(a), aqui voc� vai come�a uma nova aventura em um mundo paralelo!\n"
           	  "Est� pronto(a) para iniciar est� aventura?\n"
           	  "Ah, antes que eu me esque�a, como posso lhe chamar?: ");
           	  
    scanf("%s", nickName);
    system("cls");
    
	separadorLinha();
	
    digitacao("Voc� gradualmente desperta em seu quarto, mas algo estava terrivelmente errado.\n"
   			  "A realidade que o cercava era distorcida e assustadora, mergulhando-o em um pesadelo.\n"
   			  "Os m�veis, antes familiares, agora exibiam uma apar�ncia macabra, com formas distorcidas.\n"
   			  "Sombras dan�antes que pareciam se contorcer e possuir vida pr�pria.\n"
			  "O ar era pesado e impregnado de um odor p�trido e sufocante, provocando um calafrio constante em sua espinha.\n");
			  
	separadorLinha();
	system ("pause");
	system ("cls");
	
	separadorLinha();
	digitacao ("Selecione se deseja prosseguir: [1]Sim [2]N�o");
	separadorLinha();
	
	scanf("%d", &selecao);
	
	/* ----------------------------- If se volta pra cama ou batalha  ---------------------------------*/
	if (selecao==1){
		system("cls");
		
		separadorLinha();
	
        digitacao("Voc� se aproxima da porta do quarto, quando de repente, ouve um som arrepiante vindo de dentro, indicando a presen�a de um monstro assustador.\n"
			  "O som ecoa pelo corredor, fazendo seu cora��o acelerar e enchendo-o de apreens�o.\n"
			  "Diante disso, voc� se encontra diante de uma escolha crucial.\n");
				
		separadorLinha();
          printf("[1] Enfrentar o monstro\n");
	      printf("[2] Voltar pra cama\n");
				
					scanf("%d", &selecao);
					system("cls");
					separadorLinha();
		digitacao("Embora amedrontado, voc� decide enfrentar este pesadelo que o assombra. Com a determina��o de superar seus medos.\n"
				  "Voc� re�ne coragem e se prepara para enfrentar o desconhecido.\n"
				  "Cada passo em dire��o a porta do seu quarto � um desafio, mas voc� estava determinado a enfrentar seus pesadelos e encontrar uma sa�da dessa realidade sombria.\n");
 
    }
	if (selecao==2){
	    stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
		system("cls");
		digitacao("Voc� permanece im�vel, envolto pelo medo.\n"
				  "Seus olhos encaravam as sombras que a cada segundo parecia se contorcer com vida pr�pria.\n"
				  "Cada movimento, cada ru�do , ampliava sua apreens�o, alimentando a sensa��o de que algo terr�vel estava � espreita.\n"
				  "Voc� decide se deitar novamente, abra�ando a falsa seguran�a que a cama lhe oferece.\n"
				  "Entao um som assustador ecoa pelos corredores e chega ao seu quarto:\n\n");
					
		printf("COVARDE! Voc� n�o enfrentou seus medos e foi morto.\n");
		system("PAUSE");
		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
		
		system ("pause");
		return 0;
	}
	
	/* ----------------------------- Batalha 1 ---------------------------------*/
	
	separadorLinha();
	
        digitacao("Voc� se aproxima da porta do quarto, quando de repente, ouve um som arrepiante vindo de dentro, indicando a presen�a de um monstro assustador.\n"
			  "O som ecoa pelo corredor, fazendo seu cora��o acelerar e enchendo-o de apreens�o.\n"
			  "Diante disso, voc� se encontra diante de uma escolha crucial.\n");
				
		separadorLinha();
          printf("[1] Enfrentar o monstro\n");
	      printf("[2] Voltar pra cama\n");
				
					scanf("%d", &selecao);
					system("cls");
					separadorLinha();
	
				
	
	
	/* ----------------------------- loot 1 ---------------------------------*/
	
	if (selecao==1){
		
		digitacao ("Agora que voc� decidiu seguir em frente, preste aten��o ao seu redor e tente encontrar itens importantes \n" 
				   "para se defender do ataque de uma criatura completamente desconhecida... \n");
				   
		separadorLinha();
		
		digitacao ("No p� de sua cama h� um ba�, voc� deseja: \n"
 				   "[1] abrir o ba� ( voc� pode encontrar itens que ir�o te auxiliar na luta contra o monstro) \n"
 				   "[2] sair pela porta ( suas chances de derrota s�o altas.) \n");
 				   
		scanf("%d", &selecao);
		system("cls");
		
		switch(selecao){
          
        	case 1:
          
        		digitacao ("Voc� optou por abrir o ba�, e nele h� um iten importante para sua sobreviv�ncia.\n"
 						   " - Taco de baseball ( aumenta sua capacidade de luta)\n");
 						   
 				itens = itens + 1;
 				separadorLinha();
 				
 				digitacao("Deseja pegar este item? \n [1] Sim. n/ [2] N�o.\n"); // pegar ou n�o o taco
 				
            	scanf("%d", &selecao);
            	system("cls");
            	
                    if(selecao==1){
                        baseball ++;
                        digitacao("Muito bem, agora voc� est� equipado com o taco de baseball\n");
                        digitacao("O inimigo est� do outro lado da porta, mas voc� est� com seu taco de baseball. \n\n");
                        digitacao(" Em caso de VIT�RIA, voc� perder� 20 pontos de vida e 20 pontos de energia na batalha.\n Em caso de DERROTA, voc� perder� 50 pontos de vida e 50 pontos de energia na batalha.\n\n");
                             
                        system("PAUSE");
                        system("cls");
                            
                        separadorLinha();
                            
                        chance_batalha = aleatorio(100);
                            	
                            if(chance_batalha <=90){ // se ele pegar o taco as chances serao maiores
                                digitacao(" VIT�RIA \n Voc� conseguiu derrotar o monstro! \n");
                                monstro ++;
                                vida = vida - 20;
                                energia = energia - 20;
                                system("PAUSE");
                                vitorias = vitorias + 1;
                                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                            }
                                                          
                            else if(chance_batalha > 90){
                                digitacao(" DERROTA \n Voc� foi humilhado pelo monstro! \n");
                                vida = vida - 50;
                                energia = energia - 50;
                                system("PAUSE");
                                derrotas = derrotas + 1;
                                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                            }
                    }
                                                          
                    else if(selecao==2){ // se ele sair, as chances ser�o menores
                        digitacao("O inimigo est� do outro lado da porta, mas voc� n�o possui nenhuma arma! \n");
                        
                        separadorLinha();
                        
                        digitacao(" Em caso de VIT�RIA, voc� perder� 20 pontos de vida e 20 pontos de energia na batalha.\n Em caso de DERROTA, voc� perder� 50 pontos de vida  50 pontos de energia na batalha.\n\n");
                        
                        separadorLinha();
                        
                        system("PAUSE");
                        system("cls");
                        aleatorio(100);
                        chance_batalha = aleatorio(100);
                             
                            if(chance_batalha <=50){
                                digitacao(" VIT�RIA \n Voc� conseguiu derrotar o monstro! \n");
                                monstro ++;
                                vida = vida - 20;
                                energia = energia - 20;
                                system("PAUSE");
                                vitorias = vitorias + 1;
                                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                            }
                                                          
                            else if(chance_batalha > 50){
                                digitacao(" DERROTA \n Voc� foi humilhado pelo monstro! \n");
                                vida = vida - 50;
                                energia = energia - 50;
                                system("PAUSE");
                                derrotas = derrotas + 1;
                                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                            }
                    }
                break;
        
            case 2: // se ele sair, vai morrer
                digitacao("O inimigo est� do outro lado da porta, mas voc� n�o possui nenhuma arma! \n");
                    
                separadorLinha();
                    
                digitacao(" Em caso de VIT�RIA, voc� perder� 20 pontos de vida e 20 pontos de energia na batalha.\n Em caso de DERROTA, voc� perder� 50 pontos de vida  50 pontos de energia na batalha.\n\n");
                    
                separadorLinha();
                    
                system("PAUSE");
                system("cls");
                    
                chance_batalha = aleatorio(100);
                    
                if(chance_batalha <=50){
                    	
                    digitacao(" VIT�RIA \n Voc� conseguiu derrotar o monstro! \n");
                    monstro ++;
                    vida = vida - 20;
                    energia = energia - 20;
                    vitorias = vitorias + 1;
                    system("PAUSE");
                    stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                }
                                                          
                else if(chance_batalha > 50){
                    digitacao(" DERROTA \n Voc� foi humilhado pelo monstro! \n");
                    vida = vida - 50;
                    energia = energia - 50;
                    derrotas = derrotas + 1;
                    system("PAUSE");
                    stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                    
                }
                break;
			selecao = 0;     	
		}
			
	}
	
	selecao = 0;    
	
	system("cls");
	
	if (selecao==2){
	    separadorLinha();
		digitacao ("Voc� recuou miseravelmente. O monstro entrou no seu quarto e te estra�alhou em mil peda�os.\n"
				   "Voc� foi covarde e isso causou sua destrui��o. Lament�vel!\n");
				   
		system("PAUSE");
		
    	stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
						
		system ("pause");
		return 0;
	}
	
	stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
	
	digitacao("Voc� se inclina lentamente at� o corredor, um barulho assustador ecoa do quarto de seus pais�\n"
	          "O medo toma conta, as pernas ficam tremulas, voc� se lembra que h� uma arma de fogo no quarto dos seus pais, mas est� trancada em um confre.\n"
              "A senha para abrir o quarto, no entanto, est� no quarto de sua irm�...\n");
              
    separadorLinha();
    
	system("PAUSE");
	system("cls");
	
	digitacao("Ao adentrar furtivamente o quarto de sua irm�, voc� decide vasculhar as gavetas em busca da senha.\n");
	
	separadorLinha();
	system("PAUSE");
	
	digitacao("Voc� deseja procurar itens pelo quarto de sua irm�? \n [1] Sim. \n [2] N�o.\n");
	scanf("%d", &selecao);
	
	system("cls");
	
	separadorLinha();
	
	switch(selecao){
    
    	case 1: 
            
			digitacao("Ao vasculhar o quarto, voc� encontrou os seguintes itens: \n" 
            "- Spray de pimenta.\n"
            "- Chocolate.\n"
            "- Papel com a senha do cofre.\n");
            senha=aleatorioSenha(99999);
            printf("SENHA: %d\n", senha);
            spray ++;
            energia = energia +10;
            itens = itens + 3;
            system("PAUSE");
            stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
            break;
            
    	case 2:
          digitacao("Voc� optou por n�o vasulhar o quarto da sua irm� em busca da senha do cofre, ent�o voc� n�o ter� acesso � arma de fogo!\n");
          
          separadorLinha();  
		           
          break;  
    }
    
    stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
    
	digitacao("Ao adentrar o enigm�tico quarto dos pais, voc� se depara com uma figura aterradora e incompreens�vel.\n"
	          "O ser humano possui uma cabe�a que se assemelha a um olho gigantesco. O arrepio percorreu sua espinha diante dessa vis�o assustadora.\n");
	          
	         separadorLinha();
	         
	system("PAUSE");
 
    digitacao("Diante desta situa��o voc� tem 2 op��es:\n"
              "[1] lutar contra o monstro.\n"
              "[2] arriscar abrir o cofre sorrateiramente sem que o monstro perceba para pegar a arma.\n");
    scanf("%d", &selecao);
    
    switch(selecao){ // sele��o se vai abrir o cofre ou lutar
    
    	case 1:
    
    
        	digitacao("Qual arma voc� quer utilizar contra o monstro?\n"
                "[1] � spray / monstro: 5% voc� : 95%\n"
                "[2] � baseball / monstro: 35% voc�: 65%\n");
        	scanf("%d", &selecaoQuartoPais);
                
        	switch(selecaoQuartoPais){ // sele��o da arma que ser� utilizada, caso queira lutar direto
        	
                case 1:
                    digitacao("Com o spray de pimenta voc� pode neutralizar totalmente a vis�o do monstro, e suas chances de vit�ria s�o quase 100%.\n\n");
                    system("PAUSE");
                    
                    separadorLinha();
                    
                    chance_batalha = aleatorio(100);
                    
                    	if(chance_batalha <=95){
                    		digitacao(" VIT�RIA \n Voc� conseguiu derrotar o monstro! \n");
                			monstro ++;
                    		vida = vida - 20;
                    		energia = energia - 20;
                    		vitorias = vitorias + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);                                      
                    	}
                                                          
                    	else if(chance_batalha > 95){
                    		digitacao(" DERROTA \n Voc� foi humilhado pelo monstro! \n");
                    		system("PAUSE");
                    		
                    		separadorLinha();
                    		separadorLinha();
                    		
                    		vida = vida - 50;
                    		energia = energia - 50;
                    		derrotas = derrotas + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);  
                    	}
                    break;
                      
                case 2:
                    digitacao("O seu taco de baseball j� est� muito danficado, portanto as chances de vit�ria s�o de 65%.\n\n");
                    system("PAUSE");
                    
                    separadorLinha();
                    separadorLinha();
                    
                    chance_batalha = aleatorio(100);
                    
                    	if(chance_batalha <=65){
                    		digitacao(" VIT�RIA \n Voc� conseguiu derrotar o monstro! \n");
                    		monstro ++;
                    		vida = vida - 20;
                    		energia = energia - 20;
                    		vitorias = vitorias + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);                                        
                    	}
                                                          
                    	else if(chance_batalha > 65){
                    		digitacao(" DERROTA \n Voc� foi humilhado pelo monstro! \n");
                    		system("PAUSE");
                    		
                    		separadorLinha();
                    		
                    		vida = vida - 50;
                    		energia = energia - 50;
                    		derrotas = derrotas + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                    	}
            }
            break;
            
        case 2: // sele��o caso opte por tentar abrir o cofre, mas o monstro percebe
                digitacao("Desafiando o desconhecido, voc� toma a corajosa decis�o de abrir o cofre em busca da arma.\n"
                          "Entretanto, assim que come�a a manipular a fechadura, o ar fica impregnado de uma aura sinistra.\n"
                          "Antes que pudesse compreender o que estava acontecendo, o ser maligno detecta sua presen�a intrusa e se lan�a contra voc� com uma velocidade e ferocidade assustadoras.\n"
                          "O choque e o espanto tomam conta de voc�, enquanto luta para reagir a esse ataque s�bito e inesperado.\n");
                          
                separadorLinha();
                
                digitacao("Qual arma voc� quer utilizar contra o monstro?\n"
                		  "[1] � spray / monstro: 5% voc� : 95%\n"
                		  "[2] � baseball / monstro: 35% voc�: 65%\n");
                scanf("%d", &selecaoQuartoPais);
                
                system("PAUSE");
                 
                separadorLinha();
                
                switch(selecaoQuartoPais) { // sele��o da arma ap�s o monstro te perceber
                
                	case 1:
                    	digitacao("Com o spray de pimenta voc� pode neutralizar totalmente a vis�o do monstro, e suas chances de vit�ria s�o quase 100%.\n\n");
                    	system("PAUSE");
                    	
                    	separadorLinha();
                    	
                    	chance_batalha = aleatorio(100);
                    	
                    	if(chance_batalha <=95){
                    		digitacao(" VIT�RIA \n Voc� conseguiu derrotar o monstro! \n");
                    		monstro ++;
                    		vida = vida - 20;
                    		energia = energia - 20;
                    		vitorias = vitorias + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);                                      
                    	}
                                                          
                    	else if(chance_batalha > 95){
                    		digitacao(" DERROTA \n Voc� foi humilhado pelo monstro! \n");
                    		vida = vida - 50;
                    		energia = energia - 50;
                    		derrotas = derrotas + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                    	}
                    break;
                      
               		case 2:
                    	digitacao("O seu taco de baseball j� est� muito danficado, portanto as chances de vit�ria s�o de 65%.\n\n");
                    	system("PAUSE");
                    	
                    	separadorLinha();
                    
                    	chance_batalha = aleatorio(100);
                    	if(chance_batalha <=65){
                    		digitacao(" VIT�RIA \n Voc� conseguiu derrotar o monstro! \n");
                    		monstro ++;
                    		vida = vida - 20;
                    		energia = energia - 20;
                    		vitorias = vitorias + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);                                       
                    	}
                                                          
                    	else if(chance_batalha > 65){
                    		digitacao(" DERROTA \n Voc� foi humilhado pelo monstro! \n");
                    		vida = vida - 50;
                    		energia = energia - 50;
                    		derrotas = derrotas + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                    	} 
                    break;  
                }
        break;         
        }
        
        digitacao("Voc� finalmente chega no cofre, mas agora � preciso digitar a senha que encontrou no quarto de sua irm�.\n");
        scanf("%d", &cofre);
        
        if(cofre == senha){
        	digitacao("Voc� conseguiu abrir o cofre, e com isso teve acesso aos seguintes itens:\n"
                      "- Uma pistola\n"
                      "- Muni��o\n");
                      
        	separadorLinha(); 
		           
        	system("PAUSE");
		           
        	municao = municao + 25;
        	itens = itens + 2;
        	pistola = 1;      
        }
        
        else if(cofre != senha) {
        	digitacao("Voc� n�o foi capaz de gravar a senha, portanto n�o conseguiu abrir o cofre e ficar� sem arma de fogo. Boa sorte!\n");
        	
        	separadorLinha();
        	
        	system("PAUSE");
        }
        
    	stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
		system("PAUSE");
 
    	separadorLinha();
    
    	digitacao("Voc� entra na sala sombria, cada passo sendo dado com cautela.\n"
                  "O ambiente pesado e amedrontador provoca arrepios em sua pele.\n"
                  "Seus olhos percorrem os arm�rios empoeirados, em busca desesperada de itens vitais.\n" );
                
    	separadorLinha();
    	system("pause");
    
    	digitacao("De repente, voc� avista pela janela centenas de seres sobrenaturais do lado de fora.\n\n");
    	digitacao("Sua �nica rea��o � buscar, de forma incans�vel, recursos que podem te ajudar na batalha contra estes monstros\n\n");
    	
    	separadorLinha();
    
    	system("pause");
    
    	digitacao("Em um piscar de olhos, voc� percebe que todos est�o tentando entrar pela porta de sua casa, prontos para te matar! \n \n");
    	
    	separadorLinha();
    
    	selecao = 0;
    
    do{ 
    	
        if(energia <= 0){
            energia = 0;
        }
        
        if(vida<0){
			system("cls");
        	printf("\n-------------------------- DERROTA --------------------------\n");
        	printf("Em meio a grandes jornadas, nem sempre a vit�ria � medida pelos tesouros conquistados, mas sim pelas li��es aprendidas e pela coragem em enfrentar desafios mesmo diante da derrota.\n");
    
    		separadorLinha();
			
			system("pause");
			stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
			system("PAUSE");
			return 0;
		}
		
        stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
        printf("O %d� monstro da orda est� entrando na sua casa! Se prepare para a batalha\n", orda);
        
        separadorLinha();
        
        system("pause");
        system("cls");
        digitacao("Voc� quer vasculhar a sala em busca de itens importantes para sua sobreviv�ncia? \n [1]Sim. \n [2]N�o.\n");
        scanf("%d", &selecao);
        
        switch(selecao){
          
        	case 1: 
                remedioItens = aleatorioItens(5,15);
                energiaItens = aleatorioItens(10,15);
                municaoItens = aleatorioItens(5,12);
            	digitacao ("Voc� optou por abrir o ba�, e nele h� um item importante para sua sobreviv�ncia.\n");
                printf("- Municao %d\n"
			           "- Medicamento %d\n" 
                       "- Comida %d\n", municaoItens, remedioItens, energiaItens );
                            
                energia = energia + energiaItens;
                itens = itens + energiaItens;
                vida = vida + remedioItens;
                itens = itens + remedioItens;
                municao = municao + municaoItens;
                itens = itens + municaoItens;
                
                system("PAUSE");
                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                system("PAUSE");
                          
            	break;    
 
        	case 2:
                digitacao("Voc� optou por n�o procurar itens importantes. \n");
                separadorLinha();
                
                break;
        } 
        
        if(pistola == 0){
            system("cls");
            printf("\n-------------------------- DERROTA --------------------------\n");
            digitacao(" VOC� MORREU. Pois n�o estava suficientemente preparado para a batalha. \n\n ");
            digitacao(" Com pesar, o seu destino chegou ao fim. Seu esp�rito valente sucumbiu diante dos desafios inesperados desta jornada implac�vel. Sua hist�ria ser� lembrada como um testemunho de determina��o e coragem, agora \nperdida nas sombras do desconhecido. Que sua mem�ria seja eterna. \n" );
                    
            system("PAUSE");
            stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
            system("PAUSE");
            return 0;
                    
        }
                    
        loopMonstro = aleatorio(100);
        
        if(loopMonstro <= 15){ 
            stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
            digitacao("Voc� ir� enfrentar o terr�vel: CLAWFLANG \n"); // --------------------------------- CLAWFLANG
            digitacao("Clawfang � um monstro com garras afiadas e r�pidas, conhecido por sua agilidade e ferocidade.\n");
            digitacao("Seu poder reside em suas garras, capazes de dilacerar seus oponentes com facilidade. Ele pode executar ataques r�pidos e precisos, causando danos significativos aos seus oponentes. Al�m disso, suas garras \ns�o venenosas, podendo infligir envenenamento aos inimigos atingidos.");
            
            separadorLinha();
            
            printf("   Em caso de derrota:  \nVIDA: -50 \nENERGIA: -50 \nMUNICAO: -15");
            printf("   Em caso de vit�ria:  \nVIDA: -25 \nENERGIA: -40 \nMUNICAO: -15");
            digitacao(" � HORA DO COMBATE! ");
                
            system("PAUSE");
            system("cls");
                
            chance_batalha = aleatorio(100);
            
            if(chance_batalha <=65){
                digitacao(" VIT�RIA \n Voc� conseguiu derrotar o CLAWFLANG! \n");
                monstro ++;
                orda++;
                key++;
                vida = vida - 25;
                energia = energia - 40;
                municao = municao - 15;
                vitorias = vitorias + 1;
                system("PAUSE");                                      
            }
                                                          
            if(chance_batalha > 65){
                digitacao(" DERROTA \n Voc� foi humilhado pelo CLAWFLANG! \n");
                vida = vida - 50;
                orda++;
                energia = energia - 50;
                municao = municao - 15;
                derrotas = derrotas + 1;
                system("PAUSE");       
            }           
        }
        
        else if((loopMonstro > 15) && (loopMonstro <=50)){ // --------------------------------- SHADOWMAW
            stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
            digitacao("Voc� ir� enfrentar o terr�vel: SHADOWMAW \n");
            digitacao("Shadowmaw � um monstro das sombras, com uma boca enorme e dentes afiados, que emerge das profundezas das trevas.\n");
            digitacao("Seu poder est� relacionado ao dom�nio das sombras. Ele pode se camuflar na escurid�o e atacar seus oponentes de surpresa. Al�m disso, Shadowmaw possui uma mordida poderosa, capaz de drenar a energia \nvital de suas v�timas. Ele tamb�m � capaz de lan�ar rajadas de sombras que enfraquecem seus oponentes.\n");
            
            separadorLinha();
            
            printf("   Em caso de derrota:  \nVIDA: -20 \nENERGIA: -25 \nMUNICAO: -10\n");
            printf("   Em caso de vit�ria:  \nVIDA: -10 \nENERGIA: -15 \nMUNICAO: -10\n");
            digitacao(" � HORA DO COMBATE! ");    
            system("PAUSE");
            system("cls");
             
            if(pistola == 0){
                digitacao(" VOC� MORREU \n ");
                digitacao(" Com pesar, o seu destino chegou ao fim. Seu esp�rito valente sucumbiu diante dos desafios inesperados desta jornada implac�vel. Sua hist�ria ser� lembrada como um testemunho de determina��o e coragem, agora \nperdida nas sombras do desconhecido. Que sua mem�ria seja eterna. \n" );
                system("PAUSE");
                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                system("PAUSE");
                return 0;
                   
            }
                    
            chance_batalha = aleatorio(100);
            
            if(chance_batalha <=65){
                digitacao(" VIT�RIA \n Voc� conseguiu derrotar o SHADOWMAW! \n");
                monstro ++;
                key++;
                orda++;
                vida = vida - 10;
                energia = energia - 15;
                municao = municao - 10;
                vitorias = vitorias + 1;
                system("PAUSE");                                     
            }
                                                 
            else if(chance_batalha > 65) {
                digitacao(" DERROTA \n Voc� foi humilhado pelo SHADOWMAW! \n");
                vida = vida - 20;
                orda++;
                energia = energia - 25;
                municao = municao - 10;
                derrotas = derrotas + 1;
                system("PAUSE");
            }
        }
        
        else if(loopMonstro > 50){ // --------------------------------- DREADTHORN
            stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
            digitacao("Voc� ir� enfrentar o terr�vel: DREADTHORN \n");
            digitacao("Dreadthorn � um monstro de aspecto espinhoso, com tent�culos afiados e venenosos que se estendem de seu corpo.\n");
            digitacao("Seu poder est� centrado em seus tent�culos. Dreadthorn pode atacar seus oponentes com seus espinhos venenosos, causando danos e envenenamento. Al�m disso, ele pode criar uma barreira de espinhos ao seu redor, tornando-se \ndif�cil de ser atingido. Dreadthorn tamb�m tem a capacidade de regenerar seus espinhos e se curar gradualmente durante a batalha.");
            
            separadorLinha();
            
            printf("   Em caso de derrota:  \nVIDA: -15 \nENERGIA: -15 \nMUNICAO: -5\n");
            printf("   Em caso de vit�ria:  \nVIDA: -5 \nENERGIA: -12 \nMUNICAO: -5\n");
            digitacao(" � HORA DO COMBATE! ");
                
            system("PAUSE");
            system("cls");
 
            if(pistola == 0){
                digitacao(" VOC� MORREU \n ");
                digitacao(" Com pesar, o seu destino chegou ao fim. Seu esp�rito valente sucumbiu diante dos desafios inesperados desta jornada implac�vel. Sua hist�ria ser� lembrada como um testemunho de determina��o e coragem, agora \nperdida nas sombras do desconhecido. Que sua mem�ria seja eterna. \n" );
                system("PAUSE");
                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                system("PAUSE");
                return 0;
            }
            chance_batalha = aleatorio(100);
                
            if(chance_batalha <=65){
                digitacao(" VIT�RIA \n Voc� conseguiu derrotar o DREADTHORN! \n");
                monstro ++;
                key++;
                orda++;
                vida = vida - 5;
                energia = energia - 12;
                municao = municao - 5;
                vitorias = vitorias + 1;
                system("PAUSE");                                   
            }
                    
            else if(chance_batalha > 65) {
                digitacao(" DERROTA \n Voc� foi humilhado pelo DREADTHORN! \n");
                vida = vida - 15;
                energia = energia - 15;
                orda++;
                municao = municao - 5;
                derrotas = derrotas + 1;
                system("PAUSE");   
            }
        }
        
        orda ++;
        
    }while(vida != 0);
    
    if(key == 10) {
        stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
        printf(" -------------------------- VIT�RIA --------------------------\n");
        digitacao(" Mesmo exausto ap�s in�meras batalhas, voc� triunfou contra uma orda de monstros sobrenaturais.\n"
                  " Ap�s tudo isso, voc� acorda em sua cama normalmente, e descobre que tudo n�o se passava de um assombroso pesadelo.\n");
                  
        system("PAUSE");
        system("cls");
        return 0;
    }
      
	system("pause");
	return 0;
   
}
