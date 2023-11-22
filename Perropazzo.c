#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20 // range di numeri possibili
#define D 0 // difficolta data dalla quantita di differenza tra i due valori
    int monete = 0;//variabileche contiene il credito non che punteggio giocatore 


/*lista delle cose da aggiungere

    - la ripetizione tempestiva della partita cambiando menu
    - il programma ha un bug nel menu per i numeri in virgolamobile bisogna giungere uncontrollo con un casting 
    - se perdi per piu di 3 volte di fila il perro ti regala 2 monete
    - aggiungere le regole al 3
*/

int gioca(){
    int utente=0;   //numero utente
    int banco=0;    //numero banco o perro
    int dif=0;      //differenza del gioco
    char ch;        //scelta
    
    if (monete != 0){ 
        system("clear");
            printf("        *** Gioco Iniziato ***           \n");
            printf("Inserisci il  numero della  tua giocata: \n");
            printf("Inserisci un numero  tra 1 e 20  --> ");
            scanf("%d",&utente);
        if(utente>0 && utente <=N){ 
            //printf("Bravo numero inserito correttamente\n");
        }else{ 
            printf("Errore\n");
            return 0;
        }    
            // Inizializza il generatore di numeri casuali con il tempo corrente
            srand(time(NULL));  
            // Genera un numero casuale tra 1 e 20
            //iL banco genera il suo numero
            banco = rand() % N + 1; 

            //confronta i due numeri e decreta un vincitore calcolando la differenza assoluta tra il numero utente e il numero casuale
            
            dif = abs(utente - banco); 
            //Controlla se l'utente si è avvicinato abbastanza 

            if (dif <= D ) {
                printf("Complimenti, hai vinto! Il numero era %d.\n", banco);
                //chiede allutente se raddoppiare o tornare al menu pricipale
                monete=monete*2;
                printf("le tue monete RADDOPPIANO diventando = %d.\n", monete);  
            } else {
                printf("Mi dispiace, hai perso. Il numero era %d.\n",banco);
                monete = monete - 2;
                printf("Il perro Vince 2 monete .\n");
            }
            
    }else{
        printf("Per giocare il tuo credito non puo'essere 0 \nInserisci Altro Credito\n");
    }//fine controllo monete iniziale
    return 0;
}//fine funzione

float credito(){

    //funzione che carica un creditoall'interno della scheda giocatore 
    //int monete = 0;  temporaneamente spostiamo la variabile in globale 
    int ch;//scelta
        system("clear");
    do{
            printf("--CREDITO ATTUALE--\n");
            printf("      %d        \n",monete);
            printf("-------------------\n\n\n\n");
    
    
      printf("Quante monete inserie ? \n");
        printf("[1] - 5\n");
        printf("[2] - 10 \n");
        printf("[3] - 20 \n");
        printf("[4] - 50 \n");
        printf("[0] - Torna al menu' principale \n");  
        
         if (scanf("%d", &ch) != 1) {
            printf("Errore: Devi inserire un numero.\n");
            return 1; // Uscita con codice di errore     
        }
        switch (ch) {
            case 1:
                monete = monete + 5;
                system("clear");
                break;
            case 2:
                monete = monete + 10;
                system("clear");
                break;
            case 3:
                monete = monete + 20;
                system("clear");        
                break;
            case 4:
                monete = monete + 50;
                system("clear");        
                break;
            case 0:
                //printf("Uscita dal credito.\n");
                    system("clear");               
                break;
            default:
                printf("\n\nScelta non valida. Riprova.\n\n");
        }
    } while (ch != 0);
    return 0;
}

//regoledel gioco
int regole(){
    int ch;//scelta
       do{
        system("clear");
        printf("Il gioco consiste nel battere un cane messicanoa indovinare un numero\n");
        printf("-Carica il credito prima di giocare.\n-Se vinci le tue monete raddopieranno.\n-Se perdi il cane ti rubera' due monete. \n\n");
        printf("Inserisci 0 per ornare al menu' pricipale : ");
        scanf("%d",&ch);
    }while(ch!= 0);
    return 0;
}

int main(){
      int ch;//scelta
              system("clear");
    do{
            printf("|------------------------------|\n");
            printf("| [1] Inizia una nuova partita |\n");
            printf("| [2] Credito                  |\n");
            printf("| [3] Regole                   |\n");
            printf("| [0] Uscita                   |\n");
            printf("|------------------------------|\n");

            if (scanf("%d", &ch) != 1) {
            printf("Errore: Devi inserire un numero.\n");
            return 1; // Uscita con codice di errore
            }
        switch (ch) {
            case 1:
                //printf("Hai scelto l'Opzione 1.\n");
                gioca();
                break;
            case 2:
                //printf("Hai scelto l'Opzione 2.\n");
                //printf("Funzione non dispobile.\n");
                credito();
                break;
            case 3:
                //printf("Hai scelto l'Opzione 3.\n");
                //printf("Funzione non dispobile.\n"); 
                regole();             
                break;
            case 0:
                printf("Uscita dal programma.\n");               
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (ch != 0);
    return 0;
}
