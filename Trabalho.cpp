//Gabriel
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
    
	/* ----------------------------- Status ----------------------------------------------*/
    /* ----------------------------- fun��o separador ------------------------------------*/
    
        void separadorLinha(){
                printf("\n--------------------------------------------------------------------------------------------------------------------\n");
        }
        
    /* ----------------------------- Fun��o CorTexto -------------------------------------*/ 
    
                // cor do texto
                
        void colorRed(){ 
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        }

	/* ----------------------------- Fun��es Aleatoriedade -------------------------------*/
	
                //facil, medio ou dificio
                
        int aleatorioInimigos(int nivelInimigos) { 
        
	            int minimo = 0, maximo = 5, numInimigos;
	            srand(time(0));
	            numInimigos = (rand() % (maximo - minimo + 1)) + minimo;
	            
	            if(nivelInimigos==1){
	            numInimigos = numInimigos*1;
	            }
	            
	            else if(nivelInimigos==2){
	            numInimigos = numInimigos*2;
	            }
	            
	            else if(nivelInimigos==3){
	            numInimigos = numInimigos*4;
	            }
	            
	            return numInimigos;
	    }
	    
                // aleatoriedade dos itens
	         
	    int aleatorioItens(int aleatorio_min, int aleatorio_max) { 
	    
	         int minimo = aleatorio_min, maximo = aleatorio_max, numItens;
	         srand(time(0));
	         numItens = (rand() % (maximo - minimo + 1)) + minimo;
	         
        return numItens;
        }

	
	/* ----------------------------- Fun��o Digita��o ------------------------------------*/
	
                // fun��o de digita��o
                
        int digitacao(char texto[]){ 
                int i = 0;
                while(texto[i] != '\0'){
                printf("%c", texto[i]);
                fflush(stdout);
                Sleep(5);
                i++;
                }
        }
        
	/* ----------------------------- 100 Vida --------------------------------------------*/
     
     int semvida(int vidaAt){
                             if(vidaAt<=0){
                             
                             separadorLinha();
                             
                                           digitacao("\n   Infelizmente sua jornada chegou ao fim. Bom descan�o guerrreiro.\n");
                             
                             separadorLinha();
                             
                                          }        
                             system("pause");
                             return 0;
                            } 
	/* ----------------------------- Status ----------------------------------------------*/
 
     int status( int vidaS, int sangueS, int madeiraS, int bandagemS, int sangramentoS){
     
              separadorLinha();
     
              printf("\n   Vida = %d\n   Sangue = %d\n   Madeira = %d\n   Bandagem = %d\n   Sangramento = %d\n", vidaS, sangueS, madeiraS, bandagemS, sangramentoS);
              
              separadorLinha();
     
     }                          
                                                             
                                                                                                                         
	/* ----------------------------- Jogo ------------------------------------------------*/
	
        int main(){ 
                
                //funcao linguagem ptbr
                
                setlocale(LC_ALL, "Portuguese");
                
                //cor texto
                
                colorRed();
                
                //nome jogador
                
                char nickName[100];
                
                //variavel dificuldade
                
                int nivel;
                
                //variaveis saude
                
                int vida=50, sangue=100;
                
                //variavel progresso
                
                int andar=0;
                
                //variaveis itens
                
                int madeira=0, pedra=0, esqueiro=100, bandagem=0, faca=0, lancaFlamejante=0;
                
                //variaveis suporte
                
                int resposta, sangramento, infeccao, tocha, variavel, recursosLvl= 0, oshara=0, bauLvl=0;
                
                //introdu��o
                
                separadorLinha();
                
                digitacao("\n   Bem-vindo(a), Aos 10 Andares do Infinito!\n"
                          "   Est� pronto(a) para iniciar uma aventura eletrizante?\n"
                          "   Mas antes, digite o seu nome: ");
                          
                          scanf("%s", &nickName);
                          
                separadorLinha();
                        
                digitacao( "\n   Agora escolha a dificuldade que voc� deseja.\n"
                           "   Digite:\n\n   1- Facil\n   2- Medio\n   3- Dificil\n\n"
                           "   Qual a dificuldade?: " );
                              
                           scanf("%d", &nivel);  
                                                
           	    separadorLinha();
           	    
                 //Primeitro Andar
           	    
           	    andar = andar +1;
           	    
           	    digitacao("\n   Certo, agora podemos come�ar.\n\n   Voc� acorda em um lugar escuro e �mido, sem nenhuma lembran�a de como chegou ali. Voc� se encontra na entrada de uma\n"
                          "   masmorra misteriosa e avista um anci�o solit�rio que est� guardando a entrada da masmorra.\n");
           	    
           	    separadorLinha();
           	    
           	    digitacao("\n   O que fazer?\n\n"
                          "   Digite:\n\n"
                          "   1- Conversar com o Anciao antes de entrar na masmorra.\n"
                          "   2- Entrar na masmorra.\n");
                          
                          printf("\n   O que voc� decide?: ");
                          scanf("%d", &resposta);
                          
                          separadorLinha();
                          
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                          
                if(resposta == 1){
                 
                                     digitacao("\n   Voc� se aproxima do Anciao e pergunta: Onde estou?\n"
                                               "   O Anci�o olha fixamente para voc� e responde com uma voz grave:\n"
                                               "   Voc� est� na entrada dos 10 Andares do Infinito, um lugar de mist�rios e perigos. Seu caminho para casa est�\n"
                                               "   bloqueado, e a �nica maneira de retornar � passar pelo d�cimo andar. Tenha cuidado, aventureiro.\n"
                                               "\n   Ent�o ele desaparece da sua frente e voc� decide entrar e procurar pela saida.\n");
                                                  
                                     separadorLinha();
                                        
                                     digitacao("\n   Ao entrar voc� se depara com uma jovem, que diz:\n"
                                               "   Entao, voc� � a pessoa que o Anci�o me falou, ele pediu que eu fosse gentil com voce. Bem, meu nome � Liza.\n"
                                               "   sou uma curandeira.\n"
                                               "   Posso ver que voc� veio despreparado, vou te dar uma faca, com ela voce vai conseguir coletar seus primeiros \n"
                                               "   recursos e se defender caso seja preciso, mas ja vou avisar, isso n�o sera o suficiente para os proximos andares.\n"
                                               "   Acho bom se preparar. O caminho pode ser dificil e quando fizer uma escolha n�o olhe para tras.\n");
                                                  
                                     faca=1;
                          
                                     separadorLinha();
                                        
                                  }
                              
                else if(resposta == 2){
               
                                          digitacao("\n   Ao entrar voc� se depara com uma jovem, que diz:\n"
                                                    "   Entao, voc� � a pessoa que ignorou o Anci�o. Bem, meu nome � Liza, sou uma curandeira.\n"
                                                    "   Acho bom se preparar. O que vem por ai n�o � bom. E quando fizer uma escolha n�o olhe para tras.\n");
                          
                                          separadorLinha();
                                                  
                                      }
                                      
                else{
                
                        digitacao("\n   Desculpa, mas essa alternativa � invalida, tente novamente na proxima.\n");
                        
                        separadorLinha();
                        
                        system("pause");
                        return 0;                      
                
                    }
                                
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------                                  
                
                 digitacao("\n   O que fazer?\n\n"
	                       "   Digite:\n\n"
           	               "   1- Conversar com a Liza\n   2- Coletar madeira\n   3- Abrir Ba�\n\n   Resposta:");
           	                
           	     scanf(" %d", &resposta);
                 
           	     separadorLinha();           
                 
                 switch(resposta){
                
                                   case 1:
                                
                                          bandagem = aleatorioItens(1, 3);
                                       
                                          if(bandagem==1){
                                       
                                             digitacao("\n   Ao conversar um pouco com ela, voc� acaba ficando um pouco mais tranquilo e ela acaba lhe dando uma bandagem.\n");
                                             printf("   Agora voc� tem: %d bandagem.\n", bandagem);
                                       
                                          }
                                          
                                          else{
                                       
                                             digitacao("\n   Ao conversar um pouco com ela, voc� acaba ficando um pouco mais tranquilo e ela acaba lhe dando algumas bandagens.\n");
                                             printf("   Agora voc� tem: %d bandagens.\n", bandagem);
                                       
                                          }
                                
                                          break;
                                
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------                                 
                                
                                   case 2:
                                       
                                          madeira = aleatorioItens(2, 5);
                                   
                                          if(faca==0){
                                          
                                             sangramento = 1;
                                       
                                             printf("\n   Agora que voc� coletou algumas madeira, ja pode fazer alguma ferramenta para facilitar a sua jornada.");
                                             digitacao("\n   Mas, ao coletar madeira com as m�os voc� acabou se cortando\n   e agora precisa usar uma bandagem para parar o sangramento.");
                                       
                                          }
                                
                                          break;
                                
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------                                 
                                
                                   case 3:
                                
                                          digitacao("\n   Certo, voc� descidiu abrir o ba� e acabou encontrando:");
                                          
                                          madeira = aleatorioItens(0, 3);
                                          bandagem = aleatorioItens(0, 3);
                                                      
                                          if(faca==0){
                                          
                                                      faca = aleatorioItens(0, 10);
                                                      
                                                      if(faca == 6){
                                                      
                                                                    printf("\n   Madeira = %d\n   Bandagem = %d\n   Faca = %d", madeira, bandagem, faca);
                                                      
                                                      }
                                          }
                                          
                                          else{
                                          
                                               printf("\n   %d madeiras e %d bandagens.\n", madeira, bandagem);
                                          }
                                }
                                
                 if(resposta>3){
                                
                                digitacao("\n   Desculpa, mas essa alternativa � invalida, tente novamente na proxima.\n");
                                
                                separadorLinha();
                        
                                system("pause");
                                return 0;                      
                
                                }
                 separadorLinha();
                 
                 if(sangramento>0){
                                                              
                                     sangue= sangue-(sangramento*10);
                                     vida= vida-10;
                                                              
                                  }
                 semvida(vida);
                 //Segundo Andar
                 
                 andar = andar +1;
                 
                 digitacao("\n   Voc� chegou no segundo andar com:\n");
                 printf("\n   Vida = %d\n   Sangue = %d\n   Madeira = %d\n   Bandagem = %d\n   Sangramento = %d\n   Faca = %d\n", vida, sangue, madeira, bandagem, sangramento, faca);
                 digitacao("\n   Logo �pos sua chegada ao segundo andar voc� se depara com Gruff - Um mercen�rio sombrio que busca por itens\n   valioisos, em troca disso ele esta disposto a te mostrar um atalho para o terceiro andar.\n");
                 
                 separadorLinha();
                 
                 digitacao("\n   Deseja realizar a troca?\n\n   Troca: 3 Madeiras e 3 Bandagens\n\n   Digite:\n\n   1- Sim\n   2- N�o\n");;
                 
                 digitacao("\n   Resposta: ");
                 scanf("%d", &resposta);
                 
                 separadorLinha();
                 
                 switch(resposta){
                                  case 1:
                                         if(bandagem>2 && madeira>2){
                                         
                                                                    digitacao("\n   Gruff: Certo, vou te levar ao terceiro andar.\n");
                                                                    madeira = madeira - 3;
                                                                    bandagem = bandagem -3;
                                                                    
                                                                    break;
                                         
                                         }
                                         
                                         else{
                                         
                                             digitacao("\n   Gruff: Nada feito, n�o aceito menos que isso.\n");
                                         
                                         }
                                         
                                  case 2:
                                        if(sangramento == 1){
                 
                                                             digitacao("\n   Voc� chegou no segundo andar com um sangramento, deseja trata-lo?\n\n   Digite:\n   1- Sim\n   2- N�o\n   ");
                                                             digitacao("\n   Resposta: ");
                                                             scanf("%d", &resposta);
                                                             separadorLinha();
                                                             
                                                             if(resposta == 1 && bandagem > 0){
                                                             
                                                                                                  sangramento = sangramento - 1;
                                                                                                  bandagem = bandagem - 1;
                                                                                               
                                                                                               }
                                                                               
                                                             else{
                                                             
                                                                    digitacao("\n   Voc� n�o tem bandagens suficientes para se tratar.");
                                                                    sangue = sangue-10;
                                                                    vida = vida-10;
                                                                    printf("\n   Vida= %d\n   Sangue= %d\n", vida, sangue);               
                                                                    separadorLinha();
                                                                 }
                                      
                                                             }
                                  }
                                                             
                                         digitacao("\n   Agora que o Gruff saiu, voc� pode perceber como o segundo andar � muito escuro.\n   Voc� se lembra que ele estava usando uma tocha que aparentemente era feita de madeira e bandagem.\n\n   Criar tocha?\n\n   Digite:\n\n   1- Sim\n   2- N�o\n\n   Resposta: ");
                                         
                                         scanf("%d", &resposta);
                                         
                                         separadorLinha();
                                         
                                         if(resposta == 1){
                                         
                                                           if(madeira>0 && bandagem>0){
                                                           
                                                                                       digitacao("\n   Certo! Agora que voc� fez a tocha podera passar facilmente pelo segundo andar.");
                                                                                       
                                                                                       bandagem = bandagem - 1;
                                                                                       madeira= madeira- 1;
                                                           
                                                           }
                                                           
                                                           else{
                                                           
                                                                digitacao("\n   Voc� n�o tem material suficiente para fazer a tocha, BOA SORTE COM O ESCURO!!!");
                                                                
                                                                variavel = aleatorioItens(0, 30);
                                                                
                                                                if(variavel == 13){
                                                                
                                                                               digitacao("\n   MORREU!!!!\n   VOC� CAIU EM UMA ARMADILHA MORTAL.\n");
                                                                               
                                                                               separadorLinha(); 
                                                                
                                                                }
                                                                
                                                                else if(variavel<6){
                                                                
                                                                                    sangramento = sangramento + 1;
                                                                                    digitacao("\n   Parab�ns, voc� conseguiu passar, mas ganhou um corte a mais");
                                                                
                                                                                   }
                                                                                   
                                                                else if(variavel>28){
                                                                
                                                                                     sangramento = sangramento + 2;
                                                                                     digitacao("\n   Parab�ns, voc� conseguiu passar, mas ganhou dois cortes");
                                                                
                                                                                     }
                                                                
                                                                else{
                                                                
                                                                     digitacao("\n   PARAB�NS, voc� conseguiu passar sem nem um corte a mais.");
                                                                
                                                                }
                                                              
                                                              }
                                                           }   
                                                              
                                                              if(sangramento>0){
                                                              
                                                                     sangue= sangue-(sangramento*10);
                                                                     vida= vida-10;
                                                              
                                                              }
                  semvida(vida);                                            
                 //Terceiro  Andar
                 
                 if(sangramento>0){
                                                              
                                           sangue= sangue-(sangramento*10);
                                           vida= vida-10;
                                                              
                                  }
                 
                 andar= andar +1;
                 
                 digitacao("\n   Voc� chegou no terceiro andar com:\n");
                 printf("\n   Vida = %d\n   Sangue = %d\n   Madeira = %d\n   Bandagem = %d\n   Sangramento = %d\n   Faca = %d\n", vida, sangue, madeira, bandagem, sangramento, faca);
                 
                 separadorLinha();
                 
                 if(sangramento > 0){
                 
                                      digitacao("\n   Voc� chegou no terceiro andar com ");
                                      printf("%d de ", sangramento);
                                      digitacao("sangramento, deseja tratar?\n\n   Digite:\n   1- Tratar 1 sangramento\n   2- Tratar todos os sangramentos possiveis\n   3- N�o tratar");
                                      
                                      printf("\n   Resposta: ");                       
                                      scanf("%d", &resposta);
                                      
                                      separadorLinha();
                                                             
                    if(resposta == 1 && bandagem > 0 && sangramento>0){
                                                             
                                          sangramento = sangramento - 1;
                                          bandagem = bandagem - 1;
                                                                                             
                                          digitacao("\n   Muito bem, voc� estancou um sangramento.");
                                          printf("\n   Vida= %d\n   Sangue= %d\n   Bandagem= %d\n   Sangramento= %d\n", vida, sangue, bandagem, sangramento);
                                                                        
                    }
                                      
                    else if(resposta == 2 &&  sangramento>0){
                                      
                                          sangramento = sangramento - bandagem;
                                          bandagem= bandagem - sangramento;
                                                             
                                          if(sangramento<0){
                                             sangramento=0;
                                          }
                                                                   
                                          if(bandagem<0){
                                             bandagem=0;
                                          }
                                                                   
                                          digitacao("\n   Muito bem, voc� estancou um sangramento.");
                                          printf("\n   Vida= %d\n   Sangue= %d\n   Bandagem= %d\n   Sangramento= %d\n", vida, sangue, bandagem, sangramento);                  
                                      
                    }
                                                                                                                                          
                    else if(bandagem ==0){
                                                             
                                          digitacao("\n   Voc� n�o tem bandagens suficientes para se tratar.");
                                          sangue = sangue-(sangramento*10);
                                          vida = vida-(sangramento*10);
                                          printf("\n   Vida= %d\n   Sangue= %d\n");               
                                                             
                    }
                 }
                 
                 digitacao("\n   Logo �pos sua chegada ao terceiro andar voc� se depara com Oshara - Uma armeira muito habilidosa.\n   Ela troca itens por uma arma.\n");
                 
                 separadorLinha();
                 
                 digitacao("\n   TROCA:\n   1 Faca + 1 Madeira + 1 Bandagem = 1 Lan�a Flamejante\n");
                 
                 separadorLinha();
                 
                 digitacao("\n   Voc� tambem repara que a algumas coisas a se explorar.\n");
                 
                 do{
                 
                    digitacao("\n   O que fazer?\n\n   Digite:\n\n   1- Fazer troca com a Oshara\n   2- Abrir Ba�\n   3- Coletar Recursos\n   4- Ir para o proximo andar\n");
                 
                    printf("\n   Resposta: ");
                    scanf("%d", &resposta);
                    
                    separadorLinha();
                 
                                  if(resposta==1 && oshara==0){
                                                        if(faca==1 && madeira>=1 && bandagem>=1){
                                  
                                                               digitacao("\n   Boooooa!!\n   Agora voc� tem a Lan�a Flamejante. Ela te consedera ilumina��o caso precise e um otimo dano a media distancia.\n");
                                                                    
                                                               faca--;
                                                               madeira--;
                                                               bandagem--;
                                                               lancaFlamejante = 1;
                                                               
                                                               status(vida, sangue, madeira, bandagem, sangramento);
                                                                                                                              
                                                               digitacao("\n   O que fazer?\n   Digite:\n   2- Abrir Ba�\n   3- Coletar Recursos\n   4- Ir para o proximo andar\n");
                                  
                                                               printf("\n   Resposta: ");
                                                               scanf("%d", &resposta);
                                                        }
                                  
                                                        else{
                                  
                                                               digitacao("\n   Infelizmente voc� n�o possue recursos suficientes para fazer a troca.");
                                                               
                                                               status(vida, sangue, madeira, bandagem, sangramento);
                                                               
                                                               digitacao("\n   O que fazer? Digite:\n   2- Abrir Ba�\n   3- Coletar Recursos\n   4- Ir para o proximo andar\n");
                                  
                                                               printf("\n   Resposta: ");
                                                               scanf("%d", &resposta);
                                                        }
                                  }
                                                                                          
                                  else if(resposta ==1 && oshara==1){
                                                   
                                                        digitacao("\n   Voc� j� fez a troca com a Oshara.");
                                                        
                                                        status(vida, sangue, madeira, bandagem, sangramento);
                                                            
                                                        digitacao("\n   O que fazer?\n   Digite:\n   1- Fazer troca com a Oshara\n   3- Coletar Recursos\n   4- Ir para o proximo andar\n");
                                  
                                                        printf("\n   Resposta: ");
                                                        scanf("%d", &resposta);                  
                                  }  
                 
                                  else if(resposta==2 && bauLvl==0){
                 
                                                        madeira = madeira + aleatorioItens(3,6);
                                                        bandagem = bandagem + aleatorioItens(1,4);
                                                        bauLvl= 1;
                                  
                                                        digitacao("\n   Voc� encontou tais itens no ba�:\n");
                                                            
                                                        printf("\n   Madeira= %d e Bandagem= %d\n", madeira, bandagem);
                                                            
                                                        digitacao("\n   O que fazer?\n\n   Digite:\n   1- Fazer troca com a Oshara\n   3- Coletar Recursos\n   4- Ir para o proximo andar\n");
                                  
                                                        printf("\n   Resposta: ");
                                                        scanf("%d", &resposta);
                                                        
                                                        separadorLinha();
                                  }
                                  
                                  else if(resposta==2 && bauLvl==1){
                                  
                                                        digitacao("\n   Voc� ja abriu o ba�:");
                                                            
                                                        status(vida, sangue, madeira, bandagem, sangramento);
                                                            
                                                        digitacao("\n   O que fazer?\n   Digite:\n   1- Fazer troca com a Oshara\n   3- Coletar Recursos\n   4- Ir para o proximo andar\n");
                                  
                                                        printf("\n   Resposta: ");
                                                        scanf("%d", &resposta);
                                  }
                 
                                  else if(resposta==3 && recursosLvl==0){
                 
                                                        madeira = madeira + aleatorioItens(1,3);
                                                        bandagem = bandagem + aleatorioItens(1,2);
                                                        recursosLvl= 1;
                                                            
                                                        digitacao("\n   Voc� encontou tais itens durante a explora��o:\n");
                                                            
                                                        status(vida, sangue, madeira, bandagem, sangramento);
                                                            
                                                        digitacao("\n   O que fazer?\n\n   Digite:\n   1- Fazer troca com a Oshara\n   3- Coletar Recursos\n   4- Ir para o proximo andar\n");
                                  
                                                        printf("\n   Resposta: ");
                                                        scanf("%d", &resposta);
                                  }
                                 
                                  else if(resposta==3 && recursosLvl==1){
                                  
                                                        digitacao("\n   Voc� ja coletou os recursos:");
                                                            
                                                        status(vida, sangue, madeira, bandagem, sangramento);
                                                            
                                                        digitacao("\n   O que fazer?\n   Digite:\n   1- Fazer troca com a Oshara\n   3- Coletar Recursos\n   4- Ir para o proximo andar\n");
                                  
                                                        printf("\n   Resposta: ");
                                                        scanf("%d", &resposta);
                                  }
                 }while(resposta!=4);
                 andar=4;
                 
                  semvida(vida); 
                     
                 //Quarto ao Nono andar
                      
                 for(andar=4; andar<=9; andar++){
                 
                      recursosLvl=0;
                      bauLvl=0;
                      resposta=0;
                      semvida(vida);
                      
                      digitacao("\n   Parab�ns voc� chegou ao ");
                                  
                               if(andar==4){
                                        digitacao("quarto andar.\n");
                               }
                               
                               else if(andar==5){
                                        digitacao("quinto andar.\n");
                               }
                               
                               else if(andar==6){
                                        digitacao("sexto andar.\n");
                               }
                               
                               else if(andar==7){
                                        digitacao("setimo andar.\n");
                               }
                               
                               else if(andar==8){
                                        digitacao("oitavo andar.\n");
                               }
                               
                               else if(andar==9){
                                        digitacao("nono andar.\n");
                               }
                                          
                                          
                      status(vida, sangue, madeira, bandagem, sangramento);
                                          
                      digitacao("\n   Logo �pos sua chegada voc� repara que tem algumas coisas a se explorar.\n");
                                  
                      do{
                 
                                  digitacao("\n   O que fazer?\n\n   Digite:\n   1- Abrir Ba�\n   2- Coletar Recursos\n   3- Ir para o proximo andar\n");
                 
                                  printf("\n   Resposta: ");
                                  scanf("%d", &resposta);
                 
                                  if(resposta==1 && bauLvl==0){
                 
                                              madeira = madeira + aleatorioItens(3,6);
                                              bandagem = bandagem + aleatorioItens(1,4);
                                              bauLvl= 1;
                                  
                                              digitacao("\n   Voc� encontou tais itens no ba�:");
                                                            
                                              status(vida, sangue, madeira, bandagem, sangramento);
                                                            
                                              digitacao("\n   O que fazer?\n   Digite:\n   2- Coletar Recursos\n   3- Ir para o proximo andar\n");
                                  
                                              printf("\n   Resposta: ");
                                              scanf("%d", &resposta);
                                  }
                                  
                                  else if(resposta==1 && bauLvl==1){
                                  
                                              digitacao("\n   Voc� ja abriu o ba�:");
                                                            
                                              status(vida, sangue, madeira, bandagem, sangramento);
                                                            
                                              digitacao("\n   O que fazer?\n   Digite:\n   2- Coletar Recursos\n   3- Ir para o proximo andar\n");
                                  
                                              printf("\n   Resposta: ");
                                              scanf("%d", &resposta);
                                  }
                 
                                  if(resposta==2 && recursosLvl==0){
                 
                                              madeira = madeira + aleatorioItens(1,3);
                                              bandagem = bandagem + aleatorioItens(1,2);
                                              recursosLvl= 1;
                                                            
                                              digitacao("\n   Voc� encontou tais itens durante a explora��o:");
                                                            
                                              status(vida, sangue, madeira, bandagem, sangramento);
                                                            
                                              digitacao("\n   O que fazer?\n   Digite:\n   1- Abrir Ba�\n   2- Coletar Recursos\n   3- Ir para o proximo andar\n");
                                  
                                              printf("\n   Resposta: ");
                                              scanf("%d", &resposta);
                                  }
                                 
                                  else if(resposta==2 && recursosLvl==1){
                                  
                                              digitacao("\n   Voc� ja coletou os recursos:");
                                                            
                                              status(vida, sangue, madeira, bandagem, sangramento);
                                                            
                                              digitacao("\n   O que fazer?\n   Digite:\n   1- Abrir Ba�\n   2- Coletar Recursos\n   3- Ir para o proximo andar\n");
                                  
                                              printf("\n   Resposta: ");
                                              scanf("%d", &resposta);
                                  }
                                  
                                  if(sangramento==1){
                                  
                                       sangue--;
                                       vida--;
                                  
                                  }
                                  
                      }while(resposta!=3);
                      
                      if(nivel==1){
                      
                                            
                                            if(aleatorioItens(1,2)==2){
                                            
                                                                         digitacao("\n   Voce acabou encontrando com um inimigo quando estava prestes a entrar no proximo andar.\n   O que fazer?\n   Digite:\n   1- Lutar\n   2- Correr\n");
                                                                         printf("\n   Resposta: ");
                                                                         scanf("%d", &resposta);
                                                                         
                                                                         if(resposta==1 && lancaFlamejante==1){
                                                                         
                                                                                                              digitacao("\n   Voc� derrotou facilmente o inimigo.");
                                                                         
                                                                         }//if batalha
                                                                         
                                                                         else if(resposta ==1 && lancaFlamejante==0){
                                                                         
                                                                                                              digitacao("\n   Voc� lutou bravamente e conseguiu derrotar o inimigo.");
                                                                         
                                                                         }//else if batalha
                                                                         
                                                                         else if(resposta ==2){
                                                                         
                                                                                                              if(aleatorioItens(1,3)==3){
                                                                                                              
                                                                                                                                  digitacao("\n   Voc� fugiu do Inimigo e no caminho acabou perdendo alguns itens e ganhou um sangramento."); 
                                                                                                                                  bandagem--;
                                                                                                                                  madeira--;
                                                                                                                                  sangramento++;
                                                                                                                                  status(vida, sangue, madeira, bandagem, sangramento);
                                                                                                                                  digitacao("\n   Tratar sangramento?\n   Digite:\n   1- Sim\n   2- N�o");
                                                                                                                                  printf("\n   Resposta: ");
                                                                                                                                  scanf("%d", &resposta);
                                                                                                                                  if(resposta==1){
                                                                                                                                  
                                                                                                                                                  sangramento--;
                                                                                                                                  
                                                                                                                                  }
                                                                                                                                  else{
                                                                                                                                  
                                                                                                                                                  digitacao("\n   Voc� n�o tratou do sangramento."); 
                                                                                                                                  
                                                                                                                                  }
                                                                                                              
                                                                                                              }
                                                                         
                                                                         }//else if fuga
                                                                         
                                            };
                       
                      }//ifNivelInimigos
                      else if(nivel==2){
                                            if(aleatorioItens(1,3)>=2){
                                            
                                                                         digitacao("\n   Voce acabou encontrando com um inimigo quando estava prestes a entrar no proximo andar.\n   O que fazer?\n   Digite:\n   1- Lutar\n   2- Correr\n");
                                                                         printf("\n   Resposta: ");
                                                                         scanf("%d", &resposta);
                                                                         
                                                                         if(resposta==1 && lancaFlamejante==1){
                                                                         
                                                                                                              digitacao("\n   Voc� derrotou facilmente o inimigo.");
                                                                         
                                                                         }//if batalha
                                                                         
                                                                         else if(resposta ==1 && lancaFlamejante==0){
                                                                         
                                                                                                              digitacao("\n   Voc� lutou bravamente e conseguiu derrotar o inimigo.");
                                                                         
                                                                         }//else if batalha
                                                                         
                                                                         else if(resposta ==2){
                                                                         
                                                                                                              if(aleatorioItens(1,3)==3){
                                                                                                              
                                                                                                                                  digitacao("\n   Voc� fugiu do Inimigo e no caminho acabou perdendo alguns itens e ganhou um sangramento."); 
                                                                                                                                  bandagem--;
                                                                                                                                  madeira--;
                                                                                                                                  sangramento++;
                                                                                                                                  status(vida, sangue, madeira, bandagem, sangramento);
                                                                                                                                  digitacao("\n   Tratar sangramento?\n   Digite:\n   1- Sim\n   2- N�o");
                                                                                                                                  printf("\n   Resposta: ");
                                                                                                                                  scanf("%d", &resposta);
                                                                                                                                  if(resposta==1){
                                                                                                                                  
                                                                                                                                                  sangramento--;
                                                                                                                                  
                                                                                                                                  }
                                                                                                                                  else{
                                                                                                                                  
                                                                                                                                                  digitacao("\n   Voc� n�o tratou do sangramento."); 
                                                                                                                                  
                                                                                                                                  }
                                                                                                              
                                                                                                              }
                                                                         
                                                                         }//else if fuga
                                                                         
                                            };
                       
                      }//ifNivelInimigos
                      else if(nivel==3){
                      
                                            if(aleatorioItens(1,5)>=2){
                                            
                                                                         digitacao("\n   Voce acabou encontrando com um inimigo quando estava prestes a entrar no proximo andar.\n   O que fazer?\n   Digite:\n   1- Lutar\n   2- Correr\n");
                                                                         printf("\n   Resposta: ");
                                                                         scanf("%d", &resposta);
                                                                         
                                                                         if(resposta==1 && lancaFlamejante==1){
                                                                         
                                                                                                              digitacao("\n   Voc� lutou bravamente e conseguiu derrotar o inimigo.");
                                                                         
                                                                         }//if batalha
                                                                         
                                                                         else if(resposta ==1 && lancaFlamejante==0){
                                                                         
                                                                                                              digitacao("\n   Voc� lutou bravamente mas n�o estava forte o suficiente para derrotar o inimigo.");
                                                                                                              vida=0;
                                                                                                              status(vida, sangue, madeira, bandagem, sangramento);
                                                                                                              
                                                                                                              system("pause");
                                                                                                              return 0;
                                                                         
                                                                         }//else if batalha
                                                                         
                                                                         else if(resposta ==2){
                                                                         
                                                                                                              if(aleatorioItens(1,5)==3){
                                                                                                              
                                                                                                                                  digitacao("\n   Voc� fugiu do Inimigo e no caminho acabou perdendo alguns itens e ganhou um sangramento."); 
                                                                                                                                  bandagem--;
                                                                                                                                  madeira--;
                                                                                                                                  sangramento++;
                                                                                                                                  status(vida, sangue, madeira, bandagem, sangramento);
                                                                                                                                  digitacao("\n   Tratar sangramento?\n   Digite:\n   1- Sim\n   2- N�o");
                                                                                                                                  printf("\n   Resposta: ");
                                                                                                                                  scanf("%d", &resposta);
                                                                                                                                  if(resposta==1){
                                                                                                                                  
                                                                                                                                                  sangramento--;
                                                                                                                                  
                                                                                                                                  }
                                                                                                                                  else{
                                                                                                                                  
                                                                                                                                                  digitacao("\n   Voc� n�o tratou do sangramento."); 
                                                                                                                                  
                                                                                                                                  }
                                                                                                              
                                                                                                              }
                                                                                                              else{
                                                                                                              
                                                                                                                   digitacao("\n   Voc� tentou fugir mas o inimigo foi mais rapido e conseguiu te pegar.");
                                                                                                                   vida=0;
                                                                                                                   status(vida, sangue, madeira, bandagem, sangramento);
                                                                                                                   
                                                                                                                   system("pause");
                                                                                                                   return 0;
                                                                                                              }
                                                                         
                                                                         }//else if fuga
                                                                         
                                            };
                       
                      }//ifNivelInimigos                 
                 }//for andares 4 ao 9
                 andar=10;
                 digitacao("\n Voc� chegou ao ultimo andar, a saida esta logo a sua frente, mas derrepente surge na sua frente Zaraq,\n   o chefe dos ladroes.\n   O que fazer?\n\n   1- Correr\n   2- Lutar\n   3- Entregar tudo.");
                 
                 printf("\n   Resposta: ");
                 scanf("%d", &resposta);
                 
                      if(resposta==2){
                      
                                      digitacao("\n   Voc� batalhou ferozmente e conseguiu chegar ao fim. Parabens!!!");
                                      status(vida, sangue, madeira, bandagem, sangramento);
                                      
                                      if(aleatorioItens(1,5)==3){
                                      
                                           vida=0;
                                           semvida(vida);
                                      
                                      }
                                      vida=vida-10;
                                      semvida(vida);
                      
                      }
                      else if(resposta==1){
                      
                                      if(aleatorioItens(1,5)==1){
                                      
                                                          digitacao("\n   Voc� tentou driblar o Zaraq, mas ele te pegou e voc� n�o conseguiu voltar para casa.\n");
                                                          status(vida, sangue, madeira, bandagem, sangramento);
                                                          
                                      
                                      }
                                      else{
                                      
                                           digitacao("\n   Voc� driblou Zaraq e conseguiu chegar ao fim. Parabens!!!");
                                           status(vida, sangue, madeira, bandagem, sangramento);
                                      
                                      }
                      
                      }else if(resposta==3){
                      
                                      digitacao("\n   Voc� lembrou que este � o ultimo andar e decidiu entregar todos os seus itens para o Zaraq. Parabens voc� optou por uma postura pacifista!!!");
                                      madeira=0;
                                      bandagem=0;
                                      tocha=0;
                                      faca=0;
                                      lancaFlamejante=0;
                                      status(vida, sangue, madeira, bandagem, sangramento);
                                      printf("\n   Tocha= %d\n   Faca= %d\n   Lan�a Flamejante= %d\n", tocha, faca, lancaFlamejante);
                      }
           	    
                system("pause");
                return 0;

        }
