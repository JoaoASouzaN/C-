// Levi, Gabriel Setta, João Antônio de Souza, Henrique Augusto, João Victor Silva Nery.
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
	printf("Sua vida atual é: %d\n", vida);
	printf("Sua energia atual é: %d\n", energia);
	printf("Sua munição atual é: %d\n", municao);
	printf("Itens coletados: %d\n", itens);
	printf("Ordas: %d\n", orda);
	printf("Vitórias: %d\n", vitorias);
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
    
    printf("------------------- VOCÊ MORREU ---------------------\n");
    printf("Após inúmeras batalhas contra dezenas de criaturas, você cai desmaiado no chão!\n");
    printf("Então, de repente você se levanta novamente na sua cama, e descobre que tudo não passava de um temebroso pesadelo...\n");
    printf("Jogador(a): %s\n", nickName);
	printf("Sua vida atual é: %d\n", vida);
	printf("Sua energia atual é: %d\n", energia);
	printf("Sua munição atual é: %d\n", municao);
	printf("Itens coletados: %d\n", itens);
	printf("Ordas: %d\n", orda);
	printf("Vitórias: %d\n", vitorias);
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

/* ----------------------------- função da digitação ---------------------------------*/

int digitacao(char texto[]){ // função de digitação
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
    
    digitacao("Bem-vindo(a), aqui você vai começa uma nova aventura em um mundo paralelo!\n"
           	  "Está pronto(a) para iniciar está aventura?\n"
           	  "Ah, antes que eu me esqueça, como posso lhe chamar?: ");
           	  
    scanf("%s", nickName);
    system("cls");
    
	separadorLinha();
	
    digitacao("Você gradualmente desperta em seu quarto, mas algo estava terrivelmente errado.\n"
   			  "A realidade que o cercava era distorcida e assustadora, mergulhando-o em um pesadelo.\n"
   			  "Os móveis, antes familiares, agora exibiam uma aparência macabra, com formas distorcidas.\n"
   			  "Sombras dançantes que pareciam se contorcer e possuir vida própria.\n"
			  "O ar era pesado e impregnado de um odor pútrido e sufocante, provocando um calafrio constante em sua espinha.\n");
			  
	separadorLinha();
	system ("pause");
	system ("cls");
	
	separadorLinha();
	digitacao ("Selecione se deseja prosseguir: [1]Sim [2]Não");
	separadorLinha();
	
	scanf("%d", &selecao);
	
	/* ----------------------------- If se volta pra cama ou batalha  ---------------------------------*/
	if (selecao==1){
		system("cls");
		
		separadorLinha();
	
        digitacao("Você se aproxima da porta do quarto, quando de repente, ouve um som arrepiante vindo de dentro, indicando a presença de um monstro assustador.\n"
			  "O som ecoa pelo corredor, fazendo seu coração acelerar e enchendo-o de apreensão.\n"
			  "Diante disso, você se encontra diante de uma escolha crucial.\n");
				
		separadorLinha();
          printf("[1] Enfrentar o monstro\n");
	      printf("[2] Voltar pra cama\n");
				
					scanf("%d", &selecao);
					system("cls");
					separadorLinha();
		digitacao("Embora amedrontado, você decide enfrentar este pesadelo que o assombra. Com a determinação de superar seus medos.\n"
				  "Você reúne coragem e se prepara para enfrentar o desconhecido.\n"
				  "Cada passo em direção a porta do seu quarto é um desafio, mas você estava determinado a enfrentar seus pesadelos e encontrar uma saída dessa realidade sombria.\n");
 
    }
	if (selecao==2){
	    stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
		system("cls");
		digitacao("Você permanece imóvel, envolto pelo medo.\n"
				  "Seus olhos encaravam as sombras que a cada segundo parecia se contorcer com vida própria.\n"
				  "Cada movimento, cada ruído , ampliava sua apreensão, alimentando a sensação de que algo terrível estava à espreita.\n"
				  "Você decide se deitar novamente, abraçando a falsa segurança que a cama lhe oferece.\n"
				  "Entao um som assustador ecoa pelos corredores e chega ao seu quarto:\n\n");
					
		printf("COVARDE! Você não enfrentou seus medos e foi morto.\n");
		system("PAUSE");
		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
		
		system ("pause");
		return 0;
	}
	
	/* ----------------------------- Batalha 1 ---------------------------------*/
	
	separadorLinha();
	
        digitacao("Você se aproxima da porta do quarto, quando de repente, ouve um som arrepiante vindo de dentro, indicando a presença de um monstro assustador.\n"
			  "O som ecoa pelo corredor, fazendo seu coração acelerar e enchendo-o de apreensão.\n"
			  "Diante disso, você se encontra diante de uma escolha crucial.\n");
				
		separadorLinha();
          printf("[1] Enfrentar o monstro\n");
	      printf("[2] Voltar pra cama\n");
				
					scanf("%d", &selecao);
					system("cls");
					separadorLinha();
	
				
	
	
	/* ----------------------------- loot 1 ---------------------------------*/
	
	if (selecao==1){
		
		digitacao ("Agora que você decidiu seguir em frente, preste atenção ao seu redor e tente encontrar itens importantes \n" 
				   "para se defender do ataque de uma criatura completamente desconhecida... \n");
				   
		separadorLinha();
		
		digitacao ("No pé de sua cama há um baú, você deseja: \n"
 				   "[1] abrir o baú ( você pode encontrar itens que irão te auxiliar na luta contra o monstro) \n"
 				   "[2] sair pela porta ( suas chances de derrota são altas.) \n");
 				   
		scanf("%d", &selecao);
		system("cls");
		
		switch(selecao){
          
        	case 1:
          
        		digitacao ("Você optou por abrir o baú, e nele há um iten importante para sua sobrevivência.\n"
 						   " - Taco de baseball ( aumenta sua capacidade de luta)\n");
 						   
 				itens = itens + 1;
 				separadorLinha();
 				
 				digitacao("Deseja pegar este item? \n [1] Sim. n/ [2] Não.\n"); // pegar ou não o taco
 				
            	scanf("%d", &selecao);
            	system("cls");
            	
                    if(selecao==1){
                        baseball ++;
                        digitacao("Muito bem, agora você está equipado com o taco de baseball\n");
                        digitacao("O inimigo está do outro lado da porta, mas você está com seu taco de baseball. \n\n");
                        digitacao(" Em caso de VITÓRIA, você perderá 20 pontos de vida e 20 pontos de energia na batalha.\n Em caso de DERROTA, você perderá 50 pontos de vida e 50 pontos de energia na batalha.\n\n");
                             
                        system("PAUSE");
                        system("cls");
                            
                        separadorLinha();
                            
                        chance_batalha = aleatorio(100);
                            	
                            if(chance_batalha <=90){ // se ele pegar o taco as chances serao maiores
                                digitacao(" VITÓRIA \n Você conseguiu derrotar o monstro! \n");
                                monstro ++;
                                vida = vida - 20;
                                energia = energia - 20;
                                system("PAUSE");
                                vitorias = vitorias + 1;
                                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                            }
                                                          
                            else if(chance_batalha > 90){
                                digitacao(" DERROTA \n Você foi humilhado pelo monstro! \n");
                                vida = vida - 50;
                                energia = energia - 50;
                                system("PAUSE");
                                derrotas = derrotas + 1;
                                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                            }
                    }
                                                          
                    else if(selecao==2){ // se ele sair, as chances serão menores
                        digitacao("O inimigo está do outro lado da porta, mas você não possui nenhuma arma! \n");
                        
                        separadorLinha();
                        
                        digitacao(" Em caso de VITÓRIA, você perderá 20 pontos de vida e 20 pontos de energia na batalha.\n Em caso de DERROTA, você perderá 50 pontos de vida  50 pontos de energia na batalha.\n\n");
                        
                        separadorLinha();
                        
                        system("PAUSE");
                        system("cls");
                        aleatorio(100);
                        chance_batalha = aleatorio(100);
                             
                            if(chance_batalha <=50){
                                digitacao(" VITÓRIA \n Você conseguiu derrotar o monstro! \n");
                                monstro ++;
                                vida = vida - 20;
                                energia = energia - 20;
                                system("PAUSE");
                                vitorias = vitorias + 1;
                                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                            }
                                                          
                            else if(chance_batalha > 50){
                                digitacao(" DERROTA \n Você foi humilhado pelo monstro! \n");
                                vida = vida - 50;
                                energia = energia - 50;
                                system("PAUSE");
                                derrotas = derrotas + 1;
                                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                            }
                    }
                break;
        
            case 2: // se ele sair, vai morrer
                digitacao("O inimigo está do outro lado da porta, mas você não possui nenhuma arma! \n");
                    
                separadorLinha();
                    
                digitacao(" Em caso de VITÓRIA, você perderá 20 pontos de vida e 20 pontos de energia na batalha.\n Em caso de DERROTA, você perderá 50 pontos de vida  50 pontos de energia na batalha.\n\n");
                    
                separadorLinha();
                    
                system("PAUSE");
                system("cls");
                    
                chance_batalha = aleatorio(100);
                    
                if(chance_batalha <=50){
                    	
                    digitacao(" VITÓRIA \n Você conseguiu derrotar o monstro! \n");
                    monstro ++;
                    vida = vida - 20;
                    energia = energia - 20;
                    vitorias = vitorias + 1;
                    system("PAUSE");
                    stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                }
                                                          
                else if(chance_batalha > 50){
                    digitacao(" DERROTA \n Você foi humilhado pelo monstro! \n");
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
		digitacao ("Você recuou miseravelmente. O monstro entrou no seu quarto e te estraçalhou em mil pedaços.\n"
				   "Você foi covarde e isso causou sua destruição. Lamentável!\n");
				   
		system("PAUSE");
		
    	stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
						
		system ("pause");
		return 0;
	}
	
	stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
	
	digitacao("Você se inclina lentamente até o corredor, um barulho assustador ecoa do quarto de seus pais…\n"
	          "O medo toma conta, as pernas ficam tremulas, você se lembra que há uma arma de fogo no quarto dos seus pais, mas está trancada em um confre.\n"
              "A senha para abrir o quarto, no entanto, está no quarto de sua irmã...\n");
              
    separadorLinha();
    
	system("PAUSE");
	system("cls");
	
	digitacao("Ao adentrar furtivamente o quarto de sua irmã, você decide vasculhar as gavetas em busca da senha.\n");
	
	separadorLinha();
	system("PAUSE");
	
	digitacao("Você deseja procurar itens pelo quarto de sua irmã? \n [1] Sim. \n [2] Não.\n");
	scanf("%d", &selecao);
	
	system("cls");
	
	separadorLinha();
	
	switch(selecao){
    
    	case 1: 
            
			digitacao("Ao vasculhar o quarto, você encontrou os seguintes itens: \n" 
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
          digitacao("Você optou por não vasulhar o quarto da sua irmã em busca da senha do cofre, então você não terá acesso à arma de fogo!\n");
          
          separadorLinha();  
		           
          break;  
    }
    
    stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
    
	digitacao("Ao adentrar o enigmático quarto dos pais, você se depara com uma figura aterradora e incompreensível.\n"
	          "O ser humano possui uma cabeça que se assemelha a um olho gigantesco. O arrepio percorreu sua espinha diante dessa visão assustadora.\n");
	          
	         separadorLinha();
	         
	system("PAUSE");
 
    digitacao("Diante desta situação você tem 2 opções:\n"
              "[1] lutar contra o monstro.\n"
              "[2] arriscar abrir o cofre sorrateiramente sem que o monstro perceba para pegar a arma.\n");
    scanf("%d", &selecao);
    
    switch(selecao){ // seleção se vai abrir o cofre ou lutar
    
    	case 1:
    
    
        	digitacao("Qual arma você quer utilizar contra o monstro?\n"
                "[1] – spray / monstro: 5% você : 95%\n"
                "[2] – baseball / monstro: 35% você: 65%\n");
        	scanf("%d", &selecaoQuartoPais);
                
        	switch(selecaoQuartoPais){ // seleção da arma que será utilizada, caso queira lutar direto
        	
                case 1:
                    digitacao("Com o spray de pimenta você pode neutralizar totalmente a visão do monstro, e suas chances de vitória são quase 100%.\n\n");
                    system("PAUSE");
                    
                    separadorLinha();
                    
                    chance_batalha = aleatorio(100);
                    
                    	if(chance_batalha <=95){
                    		digitacao(" VITÓRIA \n Você conseguiu derrotar o monstro! \n");
                			monstro ++;
                    		vida = vida - 20;
                    		energia = energia - 20;
                    		vitorias = vitorias + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);                                      
                    	}
                                                          
                    	else if(chance_batalha > 95){
                    		digitacao(" DERROTA \n Você foi humilhado pelo monstro! \n");
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
                    digitacao("O seu taco de baseball já está muito danficado, portanto as chances de vitória são de 65%.\n\n");
                    system("PAUSE");
                    
                    separadorLinha();
                    separadorLinha();
                    
                    chance_batalha = aleatorio(100);
                    
                    	if(chance_batalha <=65){
                    		digitacao(" VITÓRIA \n Você conseguiu derrotar o monstro! \n");
                    		monstro ++;
                    		vida = vida - 20;
                    		energia = energia - 20;
                    		vitorias = vitorias + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);                                        
                    	}
                                                          
                    	else if(chance_batalha > 65){
                    		digitacao(" DERROTA \n Você foi humilhado pelo monstro! \n");
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
            
        case 2: // seleção caso opte por tentar abrir o cofre, mas o monstro percebe
                digitacao("Desafiando o desconhecido, você toma a corajosa decisão de abrir o cofre em busca da arma.\n"
                          "Entretanto, assim que começa a manipular a fechadura, o ar fica impregnado de uma aura sinistra.\n"
                          "Antes que pudesse compreender o que estava acontecendo, o ser maligno detecta sua presença intrusa e se lança contra você com uma velocidade e ferocidade assustadoras.\n"
                          "O choque e o espanto tomam conta de você, enquanto luta para reagir a esse ataque súbito e inesperado.\n");
                          
                separadorLinha();
                
                digitacao("Qual arma você quer utilizar contra o monstro?\n"
                		  "[1] – spray / monstro: 5% você : 95%\n"
                		  "[2] – baseball / monstro: 35% você: 65%\n");
                scanf("%d", &selecaoQuartoPais);
                
                system("PAUSE");
                 
                separadorLinha();
                
                switch(selecaoQuartoPais) { // seleção da arma após o monstro te perceber
                
                	case 1:
                    	digitacao("Com o spray de pimenta você pode neutralizar totalmente a visão do monstro, e suas chances de vitória são quase 100%.\n\n");
                    	system("PAUSE");
                    	
                    	separadorLinha();
                    	
                    	chance_batalha = aleatorio(100);
                    	
                    	if(chance_batalha <=95){
                    		digitacao(" VITÓRIA \n Você conseguiu derrotar o monstro! \n");
                    		monstro ++;
                    		vida = vida - 20;
                    		energia = energia - 20;
                    		vitorias = vitorias + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);                                      
                    	}
                                                          
                    	else if(chance_batalha > 95){
                    		digitacao(" DERROTA \n Você foi humilhado pelo monstro! \n");
                    		vida = vida - 50;
                    		energia = energia - 50;
                    		derrotas = derrotas + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                    	}
                    break;
                      
               		case 2:
                    	digitacao("O seu taco de baseball já está muito danficado, portanto as chances de vitória são de 65%.\n\n");
                    	system("PAUSE");
                    	
                    	separadorLinha();
                    
                    	chance_batalha = aleatorio(100);
                    	if(chance_batalha <=65){
                    		digitacao(" VITÓRIA \n Você conseguiu derrotar o monstro! \n");
                    		monstro ++;
                    		vida = vida - 20;
                    		energia = energia - 20;
                    		vitorias = vitorias + 1;
                    		system("PAUSE");
                    		stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);                                       
                    	}
                                                          
                    	else if(chance_batalha > 65){
                    		digitacao(" DERROTA \n Você foi humilhado pelo monstro! \n");
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
        
        digitacao("Você finalmente chega no cofre, mas agora é preciso digitar a senha que encontrou no quarto de sua irmã.\n");
        scanf("%d", &cofre);
        
        if(cofre == senha){
        	digitacao("Você conseguiu abrir o cofre, e com isso teve acesso aos seguintes itens:\n"
                      "- Uma pistola\n"
                      "- Munição\n");
                      
        	separadorLinha(); 
		           
        	system("PAUSE");
		           
        	municao = municao + 25;
        	itens = itens + 2;
        	pistola = 1;      
        }
        
        else if(cofre != senha) {
        	digitacao("Você não foi capaz de gravar a senha, portanto não conseguiu abrir o cofre e ficará sem arma de fogo. Boa sorte!\n");
        	
        	separadorLinha();
        	
        	system("PAUSE");
        }
        
    	stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
		system("PAUSE");
 
    	separadorLinha();
    
    	digitacao("Você entra na sala sombria, cada passo sendo dado com cautela.\n"
                  "O ambiente pesado e amedrontador provoca arrepios em sua pele.\n"
                  "Seus olhos percorrem os armários empoeirados, em busca desesperada de itens vitais.\n" );
                
    	separadorLinha();
    	system("pause");
    
    	digitacao("De repente, você avista pela janela centenas de seres sobrenaturais do lado de fora.\n\n");
    	digitacao("Sua única reação é buscar, de forma incansável, recursos que podem te ajudar na batalha contra estes monstros\n\n");
    	
    	separadorLinha();
    
    	system("pause");
    
    	digitacao("Em um piscar de olhos, você percebe que todos estão tentando entrar pela porta de sua casa, prontos para te matar! \n \n");
    	
    	separadorLinha();
    
    	selecao = 0;
    
    do{ 
    	
        if(energia <= 0){
            energia = 0;
        }
        
        if(vida<0){
			system("cls");
        	printf("\n-------------------------- DERROTA --------------------------\n");
        	printf("Em meio a grandes jornadas, nem sempre a vitória é medida pelos tesouros conquistados, mas sim pelas lições aprendidas e pela coragem em enfrentar desafios mesmo diante da derrota.\n");
    
    		separadorLinha();
			
			system("pause");
			stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
			system("PAUSE");
			return 0;
		}
		
        stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
        printf("O %dº monstro da orda está entrando na sua casa! Se prepare para a batalha\n", orda);
        
        separadorLinha();
        
        system("pause");
        system("cls");
        digitacao("Você quer vasculhar a sala em busca de itens importantes para sua sobrevivência? \n [1]Sim. \n [2]Não.\n");
        scanf("%d", &selecao);
        
        switch(selecao){
          
        	case 1: 
                remedioItens = aleatorioItens(5,15);
                energiaItens = aleatorioItens(10,15);
                municaoItens = aleatorioItens(5,12);
            	digitacao ("Você optou por abrir o baú, e nele há um item importante para sua sobrevivência.\n");
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
                digitacao("Você optou por não procurar itens importantes. \n");
                separadorLinha();
                
                break;
        } 
        
        if(pistola == 0){
            system("cls");
            printf("\n-------------------------- DERROTA --------------------------\n");
            digitacao(" VOCÊ MORREU. Pois não estava suficientemente preparado para a batalha. \n\n ");
            digitacao(" Com pesar, o seu destino chegou ao fim. Seu espírito valente sucumbiu diante dos desafios inesperados desta jornada implacável. Sua história será lembrada como um testemunho de determinação e coragem, agora \nperdida nas sombras do desconhecido. Que sua memória seja eterna. \n" );
                    
            system("PAUSE");
            stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
            system("PAUSE");
            return 0;
                    
        }
                    
        loopMonstro = aleatorio(100);
        
        if(loopMonstro <= 15){ 
            stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
            digitacao("Você irá enfrentar o terrível: CLAWFLANG \n"); // --------------------------------- CLAWFLANG
            digitacao("Clawfang é um monstro com garras afiadas e rápidas, conhecido por sua agilidade e ferocidade.\n");
            digitacao("Seu poder reside em suas garras, capazes de dilacerar seus oponentes com facilidade. Ele pode executar ataques rápidos e precisos, causando danos significativos aos seus oponentes. Além disso, suas garras \nsão venenosas, podendo infligir envenenamento aos inimigos atingidos.");
            
            separadorLinha();
            
            printf("   Em caso de derrota:  \nVIDA: -50 \nENERGIA: -50 \nMUNICAO: -15");
            printf("   Em caso de vitória:  \nVIDA: -25 \nENERGIA: -40 \nMUNICAO: -15");
            digitacao(" É HORA DO COMBATE! ");
                
            system("PAUSE");
            system("cls");
                
            chance_batalha = aleatorio(100);
            
            if(chance_batalha <=65){
                digitacao(" VITÓRIA \n Você conseguiu derrotar o CLAWFLANG! \n");
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
                digitacao(" DERROTA \n Você foi humilhado pelo CLAWFLANG! \n");
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
            digitacao("Você irá enfrentar o terrível: SHADOWMAW \n");
            digitacao("Shadowmaw é um monstro das sombras, com uma boca enorme e dentes afiados, que emerge das profundezas das trevas.\n");
            digitacao("Seu poder está relacionado ao domínio das sombras. Ele pode se camuflar na escuridão e atacar seus oponentes de surpresa. Além disso, Shadowmaw possui uma mordida poderosa, capaz de drenar a energia \nvital de suas vítimas. Ele também é capaz de lançar rajadas de sombras que enfraquecem seus oponentes.\n");
            
            separadorLinha();
            
            printf("   Em caso de derrota:  \nVIDA: -20 \nENERGIA: -25 \nMUNICAO: -10\n");
            printf("   Em caso de vitória:  \nVIDA: -10 \nENERGIA: -15 \nMUNICAO: -10\n");
            digitacao(" É HORA DO COMBATE! ");    
            system("PAUSE");
            system("cls");
             
            if(pistola == 0){
                digitacao(" VOCÊ MORREU \n ");
                digitacao(" Com pesar, o seu destino chegou ao fim. Seu espírito valente sucumbiu diante dos desafios inesperados desta jornada implacável. Sua história será lembrada como um testemunho de determinação e coragem, agora \nperdida nas sombras do desconhecido. Que sua memória seja eterna. \n" );
                system("PAUSE");
                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                system("PAUSE");
                return 0;
                   
            }
                    
            chance_batalha = aleatorio(100);
            
            if(chance_batalha <=65){
                digitacao(" VITÓRIA \n Você conseguiu derrotar o SHADOWMAW! \n");
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
                digitacao(" DERROTA \n Você foi humilhado pelo SHADOWMAW! \n");
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
            digitacao("Você irá enfrentar o terrível: DREADTHORN \n");
            digitacao("Dreadthorn é um monstro de aspecto espinhoso, com tentáculos afiados e venenosos que se estendem de seu corpo.\n");
            digitacao("Seu poder está centrado em seus tentáculos. Dreadthorn pode atacar seus oponentes com seus espinhos venenosos, causando danos e envenenamento. Além disso, ele pode criar uma barreira de espinhos ao seu redor, tornando-se \ndifícil de ser atingido. Dreadthorn também tem a capacidade de regenerar seus espinhos e se curar gradualmente durante a batalha.");
            
            separadorLinha();
            
            printf("   Em caso de derrota:  \nVIDA: -15 \nENERGIA: -15 \nMUNICAO: -5\n");
            printf("   Em caso de vitória:  \nVIDA: -5 \nENERGIA: -12 \nMUNICAO: -5\n");
            digitacao(" É HORA DO COMBATE! ");
                
            system("PAUSE");
            system("cls");
 
            if(pistola == 0){
                digitacao(" VOCÊ MORREU \n ");
                digitacao(" Com pesar, o seu destino chegou ao fim. Seu espírito valente sucumbiu diante dos desafios inesperados desta jornada implacável. Sua história será lembrada como um testemunho de determinação e coragem, agora \nperdida nas sombras do desconhecido. Que sua memória seja eterna. \n" );
                system("PAUSE");
                stats(nickName, vida, energia ,municao ,orda ,itens ,vitorias ,derrotas);
                system("PAUSE");
                return 0;
            }
            chance_batalha = aleatorio(100);
                
            if(chance_batalha <=65){
                digitacao(" VITÓRIA \n Você conseguiu derrotar o DREADTHORN! \n");
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
                digitacao(" DERROTA \n Você foi humilhado pelo DREADTHORN! \n");
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
        printf(" -------------------------- VITÓRIA --------------------------\n");
        digitacao(" Mesmo exausto após inúmeras batalhas, você triunfou contra uma orda de monstros sobrenaturais.\n"
                  " Após tudo isso, você acorda em sua cama normalmente, e descobre que tudo não se passava de um assombroso pesadelo.\n");
                  
        system("PAUSE");
        system("cls");
        return 0;
    }
      
	system("pause");
	return 0;
   
}
