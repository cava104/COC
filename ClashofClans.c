#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>
#include <stdlib.h>
//conflitto raziale Windows 98 edition
void miglioraminiera(char nome[], char nrisorsa[], char ncrisorsa[], int *giorni, int *crisorsa, int *lvl, int *lvlmax, int *inc, int *dis, int caso){
	
	int incestrattori[16] = {0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500}; //Incremento
	int ripestrattori[16] = {0,50,100,250,450,1000,2300,4600,9300,18600,25000,33000,66000,133000,266000,400000}; //Costo di riparazione
	int giorniestrattori[15] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8}; //Giorni per miglioramento
	int costoestrattori[15] = {150,300,700,1400,3000,7000,14000,28000,56000,75000,100000,200000,400000,800000,1200000}; //Costi dei vari livelli
	
	if((*giorni)==0){
		if((*dis)==0)
		{
			if((*lvl)<(*lvlmax)){
				printf("%s Lvl %d | Produzione %d %s\n", nome, (*lvl), (*inc), nrisorsa);
				printf("1) Migliora -%d %s | %d Giorni | Produzione %d %s\n", costoestrattori[*lvl], ncrisorsa, giorniestrattori[*lvl], incestrattori[(*lvl)+1], nrisorsa);
				printf("2) Annulla\n");
				scanf("%d", &caso);
				system("cls");
				switch(caso)
				{
					case 1:
						if((*crisorsa)>=costoestrattori[*lvl])
						{										
							(*crisorsa)-=costoestrattori[*lvl];
							(*giorni) = giorniestrattori[*lvl];
						}
						else
							printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI IL MIGLIORAMENTO.\n");
					break;
					case 2:
					break;
				}
			}
			else
				printf("LIVELLO MASSIMO RAGGIUNTO.\n");
		}
		else
		{
			printf("%s Lvl %d | Produzione %d %s\n", nome, (*lvl), (*inc), nrisorsa);
			printf("1) Ripara -%d %s\n", ripestrattori[*lvl], ncrisorsa);
			printf("2) Annulla\n");
			scanf("%d", &caso);
			system("cls");
			switch(caso)
			{
				case 1:
					if((*crisorsa)>=ripestrattori[*lvl])\
					{
						(*dis)=0;
						(*crisorsa)-=ripestrattori[*lvl];
						printf("%s: RIPARATO.\n", nome);
					}
					else
						printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI LA RIPARAZIONE");
					break;
				case 2:
				break;
			}
		}
	}else{
		system("cls");
		printf("Stai gia\' migliorando questa struttura.\n");
	}
}

void miglioramentominiera(char nome[], int *giorni, int *lvl, int *inc){
	int incestrattori[16] = {0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500}; //Incremento
	if((*giorni)==0){
	}else if((*giorni)==1){
		(*lvl)++;
		(*inc)=incestrattori[*lvl];
		(*giorni)--;
		printf("%s AL LIVELLO %d!\n", nome, *lvl);
	}else if((*giorni)>1){
		(*giorni)--;
	}
}



void miglioradepositi(char nome[], char nrisorsa[], char ncrisorsa[], int *giorni, int *lvl, int *lvlmax, int *rmax, int *crisorsa, int caso){
	
	int costodepositi[16] = {300,750,1500,3000,6000,12000,25000,50000,100000,250000,500000,1000000,2000000,3500000,5500000,6500000}; //costo dei vari livelli
	int capacitamax[17] = {0,1500,3000,6000,12000,25000,45000,100000,225000,450000,850000,1750000,2000000,3000000,4000000,4500000,5000000}; //capacità dei depositi
	int giornidepositi[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}; //Giorni per miglioramento
	
	if((*giorni)==0){		
		printf("%s Lvl %d | Capacita\' %d %s\n", nome, (*lvl), capacitamax[*lvl], nrisorsa);
		printf("1) Migliora -%d %s | %d Giorni | Capacita\' %d %s\n", costodepositi[*lvl], ncrisorsa, giornidepositi[*lvl], capacitamax[(*lvl)+1], nrisorsa);
		printf("2) Annulla\n");
		scanf("%d", &caso);
		system("cls");
		switch(caso)
		{
			case 1:
			if((*lvl)<(*lvlmax))
			{
				if((*crisorsa)>=costodepositi[*lvl])
				{										
					(*crisorsa)-=costodepositi[*lvl];
					(*giorni)=giornidepositi[*lvl];
				}
				else
					printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI IL MIGLIORAMENTO.\n");
			}
			else
				printf("LIVELLO MASSIMO RAGGIUNTO.\n");
			break;
			case 2:
			break;
		}
	}else{
		system("cls");
		printf("Stai gia\' migliorando questa struttura.\n");
	}
}

void miglioramentodepositi(char nome[], int *giorni, int *lvl, int *capacita){
	int capacitamax[17] = {0,1500,3000,6000,12000,25000,45000,100000,225000,450000,850000,1750000,2000000,3000000,4000000,4500000,5000000}; //capacità dei depositi
	if((*giorni)==0){
	}else if((*giorni)==1){
		(*lvl)++;
		(*capacita)=capacitamax[*lvl];
		(*giorni)--;
		printf("%s AL LIVELLO %d!\n", nome, *lvl);
	}else if((*giorni)>1){
		(*giorni)--;
	}
}



void migliorath(int *lvl, int *crisorsa, int *caporo, int *capelisir, int *giorni, int caso){
	
	int costoth[15] = {0,1000,4000,25000,150000,750000,1000000,2000000,3000000,3500000,4000000,6000000,9000000,15000000,18000000}; //costo dei vari livelli
	int capacitaoro[16] = {0,1000,2500,10000,50000,100000,300000,500000,750000,1000000,1500000,2000000,2000000,2000000,2000000,2000000}; //capacità oro
	int capacitaelisir[16] = {0,1000,2500,10000,50000,100000,300000,500000,750000,1000000,1500000,2000000,2000000,2000000,2000000,2000000}; //capacità elisir
	int giornith[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}; //Giorni per miglioramento	
	
	if((*giorni)==0){	
		printf("Municipio Lvl %d | Capacita\' Oro %d | Capacita\' Elisir %d\n", *lvl, *caporo, *capelisir);
		printf("1) Migliora -%d Oro | Giorni %d | Capacita\' Oro %d | Capacita\' Elisir %d\n", costoth[*lvl], giornith[*lvl], capacitaoro[(*lvl)+1], capacitaelisir[(*lvl)+1]);
		printf("2) Annulla\n");
		scanf("%d", &caso);
		system("cls");
		switch(caso)
		{
			case 1:
				if((*crisorsa)>=costoth[*lvl])
				{
					(*crisorsa)-=costoth[*lvl];
					(*giorni)=giornith[*lvl];
				}
				else
					printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI IL MIGLIORAMENTO.\n");
			break;
			case 2:
			break;
		}
	}else{
		system("cls");
		printf("Stai gia\' migliorando questa struttura.\n");
	}
}

void miglioramentoth(int *giorni, int *lvl, int *capacitaoro, int *capacitaelisir){
	int capacitamaxoro[16] = {0,1000,2500,10000,50000,100000,300000,500000,750000,1000000,1500000,2000000,2000000,2000000,2000000,2000000}; //capacità oro
	int capacitamaxelisir[16] = {0,1000,2500,10000,50000,100000,300000,500000,750000,1000000,1500000,2000000,2000000,2000000,2000000,2000000}; //capacità elisir
	if((*giorni)==0){
	}else if((*giorni)==1){
		(*lvl)++;
		(*capacitaoro)=capacitamaxoro[*lvl];
		(*capacitaelisir)=capacitamaxelisir[*lvl];
		(*giorni)--;
		printf("Municipio AL LIVELLO %d!\n", *lvl);
	}else if((*giorni)>1){
		(*giorni)--;
	}
}



void migliorac(char nome[], int *dis, int *lvl, int *lvlmax, int *risorsa, int *giorni, int caso){
	
	int costoc[21] = {250,1000,4000,16000,50000,100000,200000,300000,500000,700000,1000000,1200000,1700000,2100000,3200000,4900000,6300000,8200000,9800000,16500000,18000000}; //costo dei vari livelli
	int ripc[22] = {0,60,250,1000,4000,12500,25000,50000,75000,125000,175000,250000,300000,425000,525000,800000,1225000,1575000,2050000,2450000,4125000,4500000}; //costo di riparazione dei vari livelli
	int giornic[21] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11}; //Giorni per miglioramento	
	int difesa[22] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21}; //Difesa
	
	if((*giorni)==0){	
		if((*dis)==0)
		{
			printf("%s Lvl %d | Difesa %d\n", nome, *lvl, difesa[*lvl]);
			printf("1) Migliora -%d Oro | %d Giorni | Difesa %d\n", costoc[*lvl], giornic[*lvl], difesa[*lvl+1]);
			printf("2) Annulla\n");
			scanf("%d", &caso);
			system("cls");
			switch(caso)
			{
				case 1:
				{
					if((*lvl)<(*lvlmax))
					{
						if((*risorsa)>=costoc[*lvl])
						{										
							(*risorsa)-=costoc[*lvl];
							(*giorni)=giornic[*lvl];
						}
						else
							printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI IL MIGLIORAMENTO.\n");
					}
				else
					printf("LIVELLO MASSIMO RAGGIUNTO.\n");
				break;
				}
				case 2:
				break;
			}
		}
		else
		{
			printf("%s Lvl %d | Difesa %d\n", nome, *lvl, difesa[*lvl]);
			printf("1) Ripara -%d Oro\n", ripc[*lvl]);
			printf("2) Annulla\n");
			scanf("%d", &caso);
			system("cls");
			switch(caso)
			{
				case 1:
					if((*risorsa)>=ripc[*lvl])
					{
						(*dis)=0;
						(*risorsa)-=ripc[*lvl];
						printf("%s: RIPARATO.\n", nome);
					}
					else
						printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI LA RIPARAZIONE");
				break;
				case 2:
				break;
			}
		}
	}else{
		system("cls");
		printf("Stai gia\' migliorando questa struttura.\n");
	}
}

void miglioramentoc(char nome[], int *giorni, int *lvl, int *dif){
	int difesa[22] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21}; //Difesa
	if((*giorni)==0){
	}else if((*giorni)==1){
		(*lvl)++;
		(*dif)=difesa[*lvl];
		(*giorni)--;
		printf("%s AL LIVELLO %d!\n", nome, *lvl);
	}else if((*giorni)>1){
		(*giorni)--;
	}
}



void miglioratorrea(char nome[], int *dis, int *lvl, int *lvlmax, int *risorsa, int *giorni, int caso){
	
	int costotorrea[21] = {1000,2000,5000,20000,80000,180000,360000,600000,800000,1000000,1200000,1500000,2000000,2500000,3500000,5300000,6800000,8500000,9800000,16500000,18500000}; //costo dei vari livelli
	int riptorrea[4] = {0,50,100,150}; //costo di riparazione dei vari livelli
	int giornitorrea[5] = {1,1,2,2,3}; //Giorni per miglioramento	
	int difesa[22] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21}; //Difesa
	
	if((*giorni)==0){	
		if((*dis)==0)
		{
			printf("%s Lvl %d | Difesa %d\n", nome, *lvl, difesa[*lvl]);
			printf("1) Migliora -%d Oro | %d Giorni | Difesa %d\n", costotorrea[*lvl], giornitorrea[*lvl], difesa[*lvl+1]);
			printf("2) Annulla\n");
			scanf("%d", &caso);
			system("cls");
			switch(caso)
			{
				case 1:
				{
					if((*lvl)<(*lvlmax))
					{
						if((*risorsa)>=costotorrea[*lvl])
						{										
							(*risorsa)-=costotorrea[*lvl];
							(*giorni)=giornitorrea[*lvl];
						}
						else
							printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI IL MIGLIORAMENTO.\n");
					}
				else
					printf("LIVELLO MASSIMO RAGGIUNTO.\n");
				break;
				}
				case 2:
				break;
			}
		}
		else
		{
			printf("%s Lvl %d | Difesa %d\n", nome, *lvl, difesa[*lvl]);
			printf("1) Ripara -%d Oro\n", riptorrea[*lvl]);
			printf("2) Annulla\n");
			scanf("%d", &caso);
			system("cls");
			switch(caso)
			{
				case 1:
					if((*risorsa)>=riptorrea[*lvl])
					{
						(*dis)=0;
						(*risorsa)-=riptorrea[*lvl];
						printf("%s: RIPARATO.\n", nome);
					}
					else
						printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI LA RIPARAZIONE");
				break;
				case 2:
				break;
			}
		}
	}else{
		system("cls");
		printf("Stai gia\' migliorando questa struttura.\n");
	}
}

void miglioramentotorrea(char nome[], int *giorni, int *lvl, int *dif){
	int difesa[22] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21}; //Difesa
	if((*giorni)==0){
	}else if((*giorni)==1){
		(*lvl)++;
		(*dif)=difesa[*lvl];
		(*giorni)--;
		printf("%s AL LIVELLO %d!\n", nome, *lvl);
	}else if((*giorni)>1){
		(*giorni)--;
	}
}



void miglioramortaio(char nome[], int *dis, int *lvl, int *lvlmax, int *risorsa, int *giorni, int caso){
	
	int costo[2] = {5000,25000}; //costo dei vari livelli
	int rip[2] = {0,100}; //costo di riparazione dei vari livelli
	int giornimortaio[2] = {3,4}; //Giorni per miglioramento	
	int difesa[2] = {0,1}; //Difesa
	
	if((*giorni)==0){	
		if((*dis)==0)
		{
			printf("%s Lvl %d | Difesa %d\n", nome, *lvl, difesa[*lvl]);
			printf("1) Migliora -%d Oro | %d Giorni | Difesa %d\n", costo[*lvl], giorni[*lvl], difesa[*lvl+1]);
			printf("2) Annulla\n");
			scanf("%d", &caso);
			system("cls");
			switch(caso)
			{
				case 1:
				{
					if((*lvl)<(*lvlmax))
					{
						if((*risorsa)>=costo[*lvl])
						{										
							(*risorsa)-=costo[*lvl];
							(*giorni)=giornimortaio[*lvl];
						}
						else
							printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI IL MIGLIORAMENTO.\n");
					}
				else
					printf("LIVELLO MASSIMO RAGGIUNTO.\n");
				break;
				}
				case 2:
				break;
			}
		}
		else
		{
			printf("%s Lvl %d | Difesa %d\n", nome, *lvl, difesa[*lvl]);
			printf("1) Ripara -%d Oro\n", rip[*lvl]);
			printf("2) Annulla\n");
			scanf("%d", &caso);
			system("cls");
			switch(caso)
			{
				case 1:
					if((*risorsa)>=rip[*lvl])
					{
						(*dis)=0;
						(*risorsa)-=rip[*lvl];
						printf("%s: RIPARATO.\n", nome);
					}
					else
						printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI LA RIPARAZIONE");
				break;
				case 2:
				break;
			}
		}
	}else{
		system("cls");
		printf("Stai gia\' migliorando questa struttura.\n");
	}
}

void miglioramentomortaio(char nome[], int *giorni, int *lvl, int *dif){
	int difesa[2] = {0,1}; //Difesa
	if((*giorni)==0){
	}else if((*giorni)==1){
		(*lvl)++;
		(*dif)=difesa[*lvl];
		(*giorni)--;
		printf("%s AL LIVELLO %d!\n", nome, *lvl);
	}else if((*giorni)>1){
		(*giorni)--;
	}
}



void miglioraacc(char nome[], int *lvl, int *esercito, int *lvlmax, int *risorsa, int *giorni, int caso){
	int costoacc[4] = {200,2000,10000,100000};
	int esercitomax[4] = {0,5,10,15};
	int giorniacc[4] = {1,2,3,4};
	
	if((*giorni)==0){
		printf("%s Lvl %d | Esercito %d\n", nome, (*lvl), esercitomax[*lvl]);
		printf("1) Migliora -%d Elisir | %d Giorni | Esercito %d\n", costoacc[*lvl], giorniacc[*lvl], esercitomax[*lvl+1]);
		printf("2) Annulla\n");
		scanf("%d", &caso);
		system("cls");
		switch(caso)
		{
			case 1:
			{
				if((*lvl)<(*lvlmax))
				{
					if((*risorsa)>=costoacc[*lvl])
					{
						(*risorsa) -= costoacc[*lvl];
						(*giorni) = giorniacc[*lvl];
					}
					else
					{
						system("cls");
						printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI IL MIGLIORAMENTO.\n");
					}
				}
				else
				{
					system("cls");
					printf("LIVELLO MASSIMO RAGGIUNTO.\n");
				}
			break;
			}
			case 2:
				system("cls");
				break;
			default:
				printf("FUNZIONE NON PRESENTE.\n");
			break;
		}
	}else{
		system("cls");
		printf("Stai gia\' migliorando questa struttura.\n");
	}
}

void miglioramentoacc(char nome[], int *lvl, int *esercito, int *giorni){
	int esercitomax[4] = {0,5,10,15};
	if((*giorni)==0){
	}else if((*giorni)==1){
		(*lvl)++;
		(*esercito)=esercitomax[*lvl];
		(*giorni)--;
		printf("%s AL LIVELLO %d!\n", nome, *lvl);
	}else if((*giorni)>1){
		(*giorni)--;
	}
}



void miglioracaserma(int *lvl, int *lvlmax, int *risorsa, int *giorni, int *esercitomax, int *esercito, int sbloccato[], int barbaro[], int arciere[], int gigante[], int caso){
	int costocaserma[16] = {100,500,2500,5000,20000,120000,270000,800000,1200000,1700000,2600000,3700000,6500000,9000000,12500000,15000000};
	int giornicaserma[16] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32};
	char truppe[3][100]= {"Barbaro","Arciere","Gigante"};
	
	if((*giorni)==0){
		printf("Caserma Lvl %d\n", (*lvl));
		printf("1) Migliora -%d Elisir | %d Giorni | Sblocca %s\n", costocaserma[*lvl], giornicaserma[*lvl], truppe[*lvl]);
		printf("2) Modifica esercito\n");
		printf("3) Annulla\n");
		scanf("%d", &caso);
		system("cls");
		switch(caso)
		{
			case 1:
			{
				if((*lvl)<(*lvlmax))
				{
					if((*risorsa)>=costocaserma[*lvl])
					{
						(*risorsa) -= costocaserma[*lvl];
						(*giorni) = giornicaserma[*lvl];
					}
					else
					{
						system("cls");
						printf("NON HAI ABBASTANZA RISORSE PER PERMETTERTI IL MIGLIORAMENTO.\n");
					}
				}
				else
				{
					system("cls");
					printf("LIVELLO MASSIMO RAGGIUNTO.\n");
				}
			break;
			}
			case 2:
			{
				if((*lvl)>0 && (*esercitomax)>0){
					while(caso!=5){
						printf("Esercito %d/%d\n\n", (*esercito), (*esercitomax));
						
						if(sbloccato[0]!=0)
							printf("1) Barbaro Lvl %d | %d addestrati | FORTE CONTRO CANNONE\n", barbaro[0], barbaro[1]);
						else
							printf("1) Barbaro | BLOCCATO\n");
							
						if(sbloccato[1]!=0)
							printf("2) Arciere Lvl %d | %d addestrati | FORTE CONTRO TORRE DELL\'ARCIERE\n", arciere[0], arciere[1]);
						else
							printf("2) Arciere | BLOCCATO\n");
							
						if(sbloccato[2]!=0)
							printf("3) Gigante Lvl %d | %d addestrati | FORTE CONTRO MORTAIO\n", gigante[0], gigante[1]);
						else
							printf("3) Gigante | BLOCCATO\n");
						
						printf("4) Resetta esercito\n");
						
						printf("5) Indietro\n");
						
						scanf("%d", &caso);
						system("cls");
						switch(caso)
						{
							case 1:
							{
								printf("Quanti Barbari vuoi nel tuo esercito?\n");
								scanf("%d", &caso);
								system("cls");
								if((*esercito)+caso > (*esercitomax))
									printf("Non hai abbastanza spazio nell\'Accampamento.\n");
								else{
									barbaro[1] += caso;
									(*esercito) += caso;
								}
								caso = 0;
								break;
							}
							case 2:
							{
								if(sbloccato[1]!=0){
									printf("Quanti Arcieri vuoi nel tuo esercito?\n");
									scanf("%d", &caso);
									system("cls");
									if((*esercito)+caso > (*esercitomax))
										printf("Non hai abbastanza spazio nell\'Accampamento.\n");
									else{
										arciere[1] += caso;
										(*esercito) += caso;
									}
								}else{
									system("cls");
									printf("Migliora Caserma al lvl 2 per sbloccare\n");
								}
								caso = 0;
								break;
							}
							case 3:
							{
								if(sbloccato[2]!=0){
									printf("Quanti Giganti vuoi nel tuo esercito?\n");
									scanf("%d", &caso);
									system("cls");
									if((*esercito)+caso > (*esercitomax))
										printf("Non hai abbastanza spazio nell\'Accampamento.\n");
									else{
										gigante[1] += caso;
										(*esercito) += caso;
									}
								}else{
									system("cls");
									printf("Migliora Caserma al lvl 3 per sbloccare\n");
								}
								caso = 0;
								break;
							}
							case 4:
							{
								(*esercito) = 0;
								barbaro[1] = 0;
								arciere[1] = 0;
								gigante[1] = 0;
								break;
							}
							case 5:
							break;
						}
					}
				}else{
					system("cls");
					printf("Migliora la caserma e l\'accampamento al livello 1 per sbloccare questa funzione.\n");
				}
				break;
			}
			case 3:
				system("cls");
				break;
			default:
				printf("FUNZIONE NON PRESENTE.\n");
			break;
		}
	}else{
		system("cls");
		printf("Stai gia\' migliorando questa struttura.\n");
	}
}

void miglioramentocaserma(int *lvl, int *giorni, int truppa[]){
	if((*giorni)==0){
	}else if((*giorni)==1){
		truppa[*lvl] = 1;
		(*lvl)++;
		(*giorni)--;
		printf("Caserma AL LIVELLO %d!\n", *lvl);
	}else if((*giorni)>1){
		(*giorni)--;
	}
}



int casuale(int x, int y){
	return rand()%(y-x+1)+x;
}



void attacco(int edificio[], int caso, int *esercito1, int *sconfitta1, int *vittoria1, int *flag, int sbloccato[], int barbaro[], int arciere[], int gigante[]){	
	if((*esercito1)!=0){
		(*flag) = 1;
		if(edificio[1]==0){
			system("cls");
			int num1, num2, result, second;
			do{
				printf("Quale truppa vuoi usare?\n");
				if(sbloccato[0]!=0)
					printf("1) Barbaro Lvl %d | %d addestrati | FORTE CONTRO CANNONE\n", barbaro[0], barbaro[1]);
				else
					printf("1) Barbaro | BLOCCATO\n");
					
				if(sbloccato[1]!=0)
					printf("2) Arciere Lvl %d | %d addestrati | FORTE CONTRO TORRE DELL\'ARCIERE\n", arciere[0], arciere[1]);
				else
					printf("2) Arciere | BLOCCATO\n");
					
				if(sbloccato[2]!=0)
					printf("3) Gigante Lvl %d | %d addestrati | FORTE CONTRO MORTAIO\n", gigante[0], gigante[1]);
				else
					printf("3) Gigante | BLOCCATO\n");
				scanf("%d", &caso);
				system("cls");
				switch(caso){
					case 1:
					{
						if(sbloccato[0]!=0 && barbaro[1]!=0){
							if(edificio[2]==1){
								if((edificio[0] - barbaro[0]) <= 2)
									second = 20;
								else if((edificio[0] - barbaro[0]) <= 3)
									second = 15;
								else if((edificio[0] - barbaro[0]) <= 4)
									second = 10;
								else	
									second = 5;				
							}
							else
								second = 5;
							barbaro[0]--;
							(*esercito1)--;
						}else{
							printf("NON HAI TRUPPE DI QUESTO TIPO. SELEZIONA UN\'ALTRA TRUPPA\n");
							caso = 100;
						}
						break;
					}
					case 2:
					{
						if(sbloccato[1]!=0 && arciere[1]!=0){
							if(edificio[2]==2){
								if((edificio[0] - arciere[0]) <= 2)
									second = 20;
								else if((edificio[0] - arciere[0]) <= 3)
									second = 15;
								else if((edificio[0] - arciere[0]) <= 4)
									second = 10;
								else	
									second = 5;
							}
							else
								second = 5;
							arciere[0]--;
							(*esercito1)--;
						}else{
							printf("NON HAI TRUPPE DI QUESTO TIPO. SELEZIONA UN\'ALTRA TRUPPA\n");
							caso = 100;
						}
						break;
					}
					case 3:
					{
						if(sbloccato[2]!=0 && gigante[1]!=0){
							if(edificio[2]==3){
								if((edificio[0] - gigante[0]) <= 2)
									second = 20;
								else if((edificio[0] - gigante[0]) <= 3)
									second = 15;
								else if((edificio[0] - gigante[0]) <= 4)
									second = 10;
								else	
									second = 5;	
							}
							else
								second = 5;
							gigante[0]--;
							(*esercito1)--;
						}else{
							printf("NON HAI TRUPPE DI QUESTO TIPO. SELEZIONA UN\'ALTRA TRUPPA\n");
							caso = 100;
						}
						break;
					}
					default:
					{
						printf("FUNZIONE NON PRESENTE\n");
						caso = 100;
						break;
					}
				}
			}while(caso==100);
			
		    time_t start, end;
		    srand(time(0));
		    
		    num1 = casuale(1,3);
		    if(num1==1){
			    num1 = casuale(1,100);
			    num2 = casuale(1,100);
			    printf("Risolvi %d + %d | %d secondi\n", num1, num2, second);
			
			    time(&start);
			    scanf("%d", &caso);
			    time(&end);
			
			    result = num1 + num2;
			}else if(num1==2){
				num1 = casuale(1,100);
			    num2 = casuale(1,100);
			    printf("Risolvi %d - %d | %d secondi\n", num1, num2, second);
			
			    time(&start);
			    scanf("%d", &caso);
			    time(&end);
			
			    result = num1 - num2;
			}else if(num1==3){
				num1 = casuale(1,20);
			    num2 = casuale(1,20);
			    printf("Risolvi %d x %d | %d secondi\n", num1, num2, second);
			
			    time(&start);
			    scanf("%d", &caso);
			    time(&end);
			
			    result = num1 * num2;
			}
		    system("cls");
		    
		    if (difftime(end, start) > second) {
		        printf("Tempo scaduto!\n");
		    } else if (caso == result) {
		    	edificio[1] = 1;
		        printf("Hai vinto! Edificio distrutto.\n");
		    } else {
		        printf("Risposta sbagliata!\n");
		    }
		    
		    if((*esercito1)==0){
		    	(*sconfitta1)=1;
			}
		}
		else{
			system("cls");
			printf("Edificio gia\' distrutto.\n");
		}
	}
	else{
		system("cls");
		printf("Devi avere almeno 1 truppa per inziare l\'attacco.\n");
	}
}

int main(){
	PlaySound(TEXT("CocStart.wav"),NULL,SND_ASYNC);
	sleep(1);
	printf("SUPERCELL\n");
	sleep(2);
	printf("CLASH OF CLANS\n");
	sleep(4);
	
	srand(time(NULL));
	
	//VARIABILI TH2
	char nmo[] = "Miniera d\'Oro", nmo2[] = "Miniera d\'Oro 2", nee[] = "Estrattore d\'Elisir", nee2[] = "Estrattore d\'Elisir 2", noro[] = "Oro", nelisir[] = "Elisir";
	char ndeporo[] = "Deposito d\'Oro", ndepelisir[] = "Deposito d\'Elisir";
	char nc[] = "Cannone", nc2[] = "Cannone 2", ntorrea[] = "Torre dell\'Arciere";
	char nacc[] = "Accampamento";
	int caso=0, giorno=1, probabilita=100, probmax=20; //variabili a caso
	int oro=250, oromax=0, io=0; //oro
	int elisir=250, elisirmax=0, ie=0; //elisir
	
	int th[4] = {2,2500,2500,0}; //Livello, oromax, elisirmax, giorni rimasti al miglioramento
	
	int lvlmaxestrattori=4; //livello massimo estrattori
	int mo[4] = {1,0,100,0}; //Livello, distrutto, incremento, giorni rimasti al miglioramento
	int mo2[4] = {0,0,0,0};
	int ee[4] = {1,0,100,0};
	int ee2[4] = {0,0,0,0};
	
	int lvlmaxdepositi=3; //livello massimo depositi
	int deporo[3] = {0,0,0}; //Livello, capacità, giorni rimasti al miglioramento
	int depelisir[3] = {0,0,0};
	
	int lvlmaxc=3; //livello massimo cannoni
	int c[4] = {0,0,0,0}; //Livello, distrutto, difesa, giorni rimasti al miglioramento
	int c2[4] = {0,0,0,0};
	
	int lvlmaxtorrea=2; //Livello massimo torre arciere
	int torrea[4] = {0,0,0,0}; //Livello, distrutto, difesa, giorni rimasti al miglioramento
	
	int lvlmaxcaserma = 2;
	int caserma[2] = {0,0}; //Livello, giorni rimasti al miglioramento
	
	int sbloccato[3] = {0,0,0}; //Definisce se ho sbloccato o meno una truppa (Barbaro, Arciere...)
	int barbaro[2] = {1,0}; //Livello, quantità
	int arciere[2] = {1,0};
	int gigante[2] = {1,0};
	
	int lvlmaxacc=2;
	int acc[3] = {0,0,0}; //Livello, esercito massimo, giorni rimasti al miglioramento
	int esercito = 0;
	int difesa=1; //difesa
	
	int ac[3] = {0,0,1}, ac2[3] = {0,0,1}, atorrea[3] = {0,0,2}; //Livello, distrutto, numero di struttura(serve per le truppe)
	int trofei=0, trofeivitt=0, trofeisconf=0, attmax=0, orovitt=0, elisirvitt=0; //attacco
	int fine=0, sconfitta=0, vittoria=0; //attacco2
	
	//VARIABILI TH3
	char nmo3[] = "Miniera d\'Oro 3", nee3[] = "Estrattore d\'Elisir 3";
	char ndeporo2[] = "Deposito d\'Oro 2", ndepelisir2[] = "Deposito d\'Elisir 2";
	char nmortaio[] = "Mortaio"; 
	
	int mo3[4] = {0,0,0,0}; //Livello, distrutto, incremento, giorni rimasti al miglioramento
	int ee3[4] = {0,0,0,0};
	
	
	int deporo2[3] = {0,0,0}; //Livello, capacità, giorni rimasti al miglioramento
	int depelisir2[3] = {0,0,0};
	
	
	int mortaio[4] = {0,0,0,0}; //Livello, distrutto, difesa, giorni rimasti al miglioramento
	int lvlmaxmortaio = 1;
	
	int amortaio[3] = {0,0,3};
	
	//LETTURA FILE
	FILE *fp;
    fp = fopen("dati.csv", "r");
    
    fscanf(fp, "%d, %d, %d, %d\n", &trofei, &oro, &elisir, &attmax);
			    
    fscanf(fp, "%d, %d, %d, %d\n", &mo[0], &mo[1], &mo[2], &mo[3]);
    fscanf(fp, "%d, %d, %d, %d\n", &mo2[0], &mo2[1], &mo2[2], &mo2[3]);
    fscanf(fp, "%d, %d, %d, %d\n", &mo3[0], &mo3[1], &mo3[2], &mo3[3]);
    fscanf(fp, "%d, %d, %d, %d\n", &ee[0], &ee[1], &ee[2], &ee[3]);
    fscanf(fp, "%d, %d, %d, %d\n", &ee2[0], &ee2[1], &ee2[2], &ee2[3]);
    fscanf(fp, "%d, %d, %d, %d\n", &ee3[0], &ee3[1], &ee3[2], &ee3[3]);
    
    fscanf(fp, "%d, %d, %d\n", &deporo[0], &deporo[1], &deporo[2]);
    fscanf(fp, "%d, %d, %d\n", &deporo2[0], &deporo2[1], &deporo2[2]);
    fscanf(fp, "%d, %d, %d\n", &depelisir[0], &depelisir[1], &depelisir[2]);
    fscanf(fp, "%d, %d, %d\n", &depelisir2[0], &depelisir2[1], &depelisir2[2]);
    
    fscanf(fp, "%d, %d, %d, %d\n", &th[0], &th[1], &th[2], &th[3]);
    
    fscanf(fp, "%d, %d, %d, %d\n", &c[0], &c[1], &c[2], &c[3]);
    fscanf(fp, "%d, %d, %d, %d\n", &c2[0], &c2[1], &c2[2], &c2[3]);
    fscanf(fp, "%d, %d, %d, %d\n", &torrea[0], &torrea[1], &torrea[2], &torrea[3]);
    fscanf(fp, "%d, %d, %d, %d\n", &mortaio[0], &mortaio[1], &mortaio[2], &mortaio[3]);
    
    fscanf(fp, "%d, %d\n", &caserma[0], &caserma[1]);
    fscanf(fp, "%d, %d, %d\n", &sbloccato[0], &sbloccato[1], &sbloccato[2]);
    fscanf(fp, "%d, %d\n", &barbaro[0], &barbaro[1]);
    fscanf(fp, "%d, %d\n", &arciere[0], &arciere[1]);
    fscanf(fp, "%d, %d\n", &gigante[0], &gigante[1]);
    
    fscanf(fp, "%d, %d, %d\n", &acc[0], &acc[1], &acc[2]);
    
    fscanf(fp, "%d, %d, %d\n", &giorno, &probabilita, &probmax);
    
    fclose(fp);
	
	system("cls");
	PlaySound(TEXT("CocTheme.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
	
	//MENU TH2
	while(th[0]<3){
		oromax = 0;
		oromax = th[1] + deporo[1];
		elisirmax = 0;
		elisirmax = th[2]+ depelisir[1];
		ie = 50;
		io = 50;
		
		printf("Giorno %d\n", giorno);
		printf("Oro %d/%d | Elisir %d/%d\n\n", oro, oromax, elisir, elisirmax);
		
		if(th[3]!=0)
			printf("1) Municipio - Lvl %d | MIGLIORAMENTO %d Giorni\n", th[0], th[3]);
		else
			printf("1) Municipio - Lvl %d\n", th[0]);
		
		printf("2) Risorse\n");
		printf("3) Difesa\n");
		printf("4) Attacco\n");
		printf("5) Giorno successivo\n");
		printf("6) Salva\n\n");
		
		scanf("%d", &caso);
		system("cls");
		
		switch(caso){
			case 1:
			{
				migliorath(&th[0], &oro, &th[1], &th[2], &th[3], caso);
				break;	
			}
			case 2:
			{
				printf("RISORSE\n");
				printf("Giorno %d\n", giorno);
				printf("Oro %d/%d | Elisir %d/%d\n\n", oro, oromax, elisir, elisirmax);
				
				printf("1) Miniere d\'Oro\n");
				printf("2) Estrattori d\'Elisir\n");
				printf("3) Depositi\n");
				printf("4) Indietro\n\n");
				
				scanf("%d", &caso);
				system("cls");
				
				switch(caso){
					case 1:
					{
						printf("MINIERE D\'ORO\n");
						printf("Giorno %d\n", giorno);
						printf("Oro %d/%d | Elisir %d/%d\n\n", oro, oromax, elisir, elisirmax);
						
						if(mo[1]==1)
							printf("1) %s - Lvl %d | DISTRUTTO\n", nmo, mo[0]);
						else if(mo[3]!=0)
							printf("1) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nmo, mo[0], mo[3]);
						else
							printf("1) %s - Lvl %d\n", nmo, mo[0]);
						
						if(mo2[1]==1)
							printf("2) %s - Lvl %d | DISTRUTTO\n", nmo2, mo2[0]);
						else if(mo2[3]!=0)
							printf("2) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nmo2, mo2[0], mo2[3]);
						else
							printf("2) %s - Lvl %d\n", nmo2, mo2[0]);
						
						printf("3) Indietro\n\n");
						
						scanf("%d", &caso);
						system("cls");
						
						switch(caso){
							case 1:
							{
								miglioraminiera(nmo, noro, nelisir, &mo[3], &elisir, &mo[0], &lvlmaxestrattori, &mo[2], &mo[1], caso);
								break;
							}
							case 2:
							{
								miglioraminiera(nmo2, noro, nelisir, &mo2[3], &elisir, &mo2[0], &lvlmaxestrattori, &mo2[2], &mo2[1], caso);
								break;
							}
							case 3:
							{
								break;
							}
						}
						break;
					}
					case 2:
					{
						printf("ESTRATTORI D\'ELISIR\n");
						printf("Giorno %d\n", giorno);
						printf("Oro %d/%d | Elisir %d/%d\n\n", oro, oromax, elisir, elisirmax);
						
						if(ee[1]==1)
							printf("1) %s - Lvl %d | DISTRUTTO\n", nee, ee[0]);
						else if(ee[3]!=0)
							printf("1) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nee, ee[0], ee[3]);
						else
							printf("1) %s - Lvl %d\n", nee, ee[0]);
					
						if(ee2[1]==1)
							printf("2) %s - Lvl %d | DISTRUTTO\n", nee2, ee2[0]);
						else if(ee2[3]!=0)
							printf("2) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nee2, ee2[0], ee2[3]);
						else
							printf("2) %s - Lvl %d\n", nee2, ee2[0]);
							
						printf("3) Indietro\n\n");
						
						scanf("%d", &caso);
						system("cls");
						
						switch(caso){
							case 1:
							{
								miglioraminiera(nee, nelisir, noro, &ee[3], &oro, &ee[0], &lvlmaxestrattori, &ee[2], &ee[1], caso);
								break;
							}
							case 2:
							{
								miglioraminiera(nee2, nelisir, noro, &ee2[3], &oro, &ee2[0], &lvlmaxestrattori, &ee2[2], &ee2[1], caso);
								break;
							}
							case 3:
							{
								break;
							}
						}
						break;
					}
					case 3:
					{
						printf("DEPOSITI\n");
						printf("Giorno %d\n", giorno);
						printf("Oro %d/%d | Elisir %d/%d\n\n", oro, oromax, elisir, elisirmax);
						
						if(deporo[2]!=0)
							printf("1) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", ndeporo, deporo[0], deporo[2]);
						else
							printf("1) %s - Lvl %d\n", ndeporo, deporo[0]);
						if(depelisir[2]!=0)
							printf("2) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n\n", ndepelisir, depelisir[0], depelisir[2]);
						else		
							printf("2) %s - Lvl %d\n\n", ndepelisir, depelisir[0]);
							
						printf("3) Indietro\n\n");
						
						scanf("%d", &caso);
						system("cls");
						
						switch(caso){
							case 1:
							{
								miglioradepositi(ndeporo, noro, nelisir, &deporo[2], &deporo[0], &lvlmaxdepositi, &deporo[1], &elisir, caso);
								break;
							}
							case 2:
							{
								miglioradepositi(ndepelisir, nelisir, noro, &depelisir[2], &depelisir[0], &lvlmaxdepositi, &depelisir[1], &oro, caso);
								break;
							}
							case 3:
							{
								break;
							}
						}
						break;
					}
					case 4:
					{
						break;
					}
				}
				break;
			}
			case 3:
			{
				printf("DIFESA\n");
				printf("Giorno %d\n", giorno);
				printf("Oro %d/%d | Elisir %d/%d\n\n", oro, oromax, elisir, elisirmax);
				
				printf("1) Cannoni\n");
				printf("2) Torri dell'arciere\n");
				printf("3) Indietro\n\n");
				
				scanf("%d", &caso);
				system("cls");
				
				switch(caso){
					case 1:
					{
						printf("CANNONI\n");
						printf("Giorno %d\n", giorno);
						printf("Oro %d/%d | Elisir %d/%d\n\n", oro, oromax, elisir, elisirmax);
				
						if(c[1]==1)
							printf("1) %s - Lvl %d | DISTRUTTO\n", nc, c[0]);
						else if(c[3]!=0)
							printf("1) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nc, c[0], c[3]);
						else
							printf("1) %s - Lvl %d\n", nc, c[0]);
						
						if(c2[1]==1)
							printf("2) %s - Lvl %d | DISTRUTTO\n", nc2, c2[0]);
						else if(c2[3]!=0)
							printf("2) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nc2, c2[0], c2[3]);
						else
							printf("2) %s - Lvl %d\n", nc2, c2[0]);
						
						printf("3) Indietro\n\n");
							
						scanf("%d", &caso);
						system("cls");
						
						switch(caso){
							case 1:
							{
								migliorac(nc, &c[1], &c[0], &lvlmaxc, &oro, &c[3], caso);
								break;
							}
							case 2:
							{
								migliorac(nc2, &c2[1], &c2[0], &lvlmaxc, &oro, &c2[3], caso);
								break;
							}
							case 3:
							{
								break;
							}
						}
						break;
					}
					case 2:
					{
						printf("TORRI DELL'ARCIERE\n");
						printf("Giorno %d\n", giorno);
						printf("Oro %d/%d | Elisir %d/%d\n\n", oro, oromax, elisir, elisirmax);
						
						if(torrea[1]==1)
							printf("1) %s - Lvl %d | DISTRUTTO\n\n", ntorrea, torrea[0]);
						else if(torrea[3]!=0)
							printf("1) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n\n", ntorrea, torrea[0], torrea[3]);
						else
							printf("1) %s - Lvl %d\n\n", ntorrea, torrea[0]);
						
						printf("2) Indietro\n\n");
						scanf("%d", &caso);
						system("cls");
						
						switch(caso){
							case 1:
							{
								miglioratorrea(ntorrea, &torrea[1], &torrea[0], &lvlmaxtorrea, &oro, &torrea[3], caso);
								break;
							}
							case 2:
							{
								break;
							}
						}
						break;
					}
					case 3:
					{
						break;
					}
				}
				break;
			}
			case 4:
			{
				printf("ATTACCO\n");
				printf("Giorno %d\n", giorno);
				printf("Oro %d/%d | Elisir %d/%d\n\n", oro, oromax, elisir, elisirmax);
				
				printf("1) Caserma\n");
				printf("2) Accampamento\n");
				printf("3) Attacco\n");
				printf("4) Indietro\n\n");
				
				scanf("%d", &caso);
				system("cls");
				
				switch(caso){
					case 1:
					{
						miglioracaserma(&caserma[0], &lvlmaxcaserma, &elisir, &caserma[1], &acc[1], &esercito, sbloccato, barbaro, arciere, gigante, caso);
						break;	
					}
					case 2:
					{
						miglioraacc(nacc, &acc[0], &acc[1], &lvlmaxacc, &elisir, &acc[2], caso);
						break;
					}
					case 3:
					{	
						if(attmax==0)
						{
							PlaySound(TEXT("CocBattle.wav"),NULL,SND_ASYNC);
							if(trofei<=100)
							{	
							
								probabilita = casuale(1,2);
								ac[0]=probabilita;
								
								probabilita = casuale(1,1);
								ac2[0]=probabilita;
								
								probabilita = casuale(1,1);
								atorrea[0]=probabilita;
							
								probabilita = casuale(300,1000);
								orovitt=probabilita;
								
								probabilita = casuale(300,1000);
								elisirvitt=probabilita;
								
								probabilita = casuale(12,35);
								trofeivitt=probabilita;
								
								probabilita = casuale(18,30);
								trofeisconf=probabilita;
							}
							if(trofei>100 && trofei<=300)
							{
								probabilita = casuale(1,2);
								ac[0]=probabilita;
								
								probabilita = casuale(1,2);
								ac2[0]=probabilita;
								
								probabilita = casuale(1,2);
								atorrea[0]=probabilita;
							
								probabilita = casuale(600,1200);
								orovitt=probabilita;
								
								probabilita = casuale(600,1200);
								elisirvitt=probabilita;
								
								probabilita = casuale(18,35);
								trofeivitt=probabilita;
								
								probabilita = casuale(20,30);
								trofeisconf=probabilita;
							}
							if(trofei>300)
							{
								probabilita = casuale(1,3);
								ac[0]=probabilita;
								
								probabilita = casuale(1,3);
								ac2[0]=probabilita;
								
								probabilita = casuale(1,3);
								atorrea[0]=probabilita;
							
								probabilita = casuale(1000,1800);
								orovitt=probabilita;
								
								probabilita = casuale(1000,1800);
								elisirvitt=probabilita;
								
								probabilita = casuale(20,35);
								trofeivitt=probabilita;
								
								probabilita = casuale(25,30);
								trofeisconf=probabilita;
								
							}
							fine=0;
							ac[1]=0;
							ac2[1]=0;
							atorrea[1]=0;	
							int flag = 0;
							do{
								printf("VILLAGGIO NEMICO\n");
							
								printf("Vittoria + %d Oro | + %d Elisir | + %d Trofei\n", orovitt, elisirvitt, trofeivitt);
								printf("Sconfitta - %d Trofei\n", trofeisconf);
								
								printf("Esercito %d/%d truppe\n\n", esercito, acc[1]);
								printf("Municipio Lvl 2\n");
								
								if(ac[1]==0)
									printf("1) Cannone Lvl %d\n", ac[0]);
								else
									printf("1) Cannone Lvl %d | DISTRUTTO\n", ac[0]);
								if(ac2[1]==0)
									printf("2) Cannone 2 Lvl %d\n", ac2[0]);
								else
									printf("2) Cannone 2 Lvl %d | DISTRUTTO\n", ac2[0]);
								if(atorrea[1]==0)
									printf("3) Torre dell\'arciere Lvl %d\n\n", atorrea[0]);
								else
									printf("3) Torre dell\'arciere Lvl %d | DISTRUTTO\n\n", atorrea[0]);
									
								printf("4) Torna al villaggio\n");
								scanf("%d", &caso);
								system("cls");
								switch(caso)
								{
									case 1:
									{
										attacco(ac, caso, &esercito, &sconfitta, &vittoria, &flag, sbloccato, barbaro, arciere, gigante);
										break;
									}
									case 2:
									{
										attacco(ac2, caso, &esercito, &sconfitta, &vittoria, &flag, sbloccato, barbaro, arciere, gigante);
										break;
									}
									case 3:
									{
										attacco(atorrea, caso, &esercito, &sconfitta, &vittoria, &flag, sbloccato, barbaro, arciere, gigante);
										break;
									}
									case 4:
									{
										system("cls");
										if(flag!=0)
											sconfitta=1;
										else
											fine=1;
										break;
									}
									default:
										printf("FUNZIONE NON PRESENTE.\n");
										break;
								}
								if(ac[1]==1 && ac2[1]==1 && atorrea[1]==1){
									vittoria=1;
								}
							}while(fine==0 && sconfitta==0 && vittoria==0);
							if(vittoria==1)
							{
								system("cls");
								trofei+=trofeivitt;
								if((oro==oromax) || ((oromax-oro)<orovitt))
									oro=oromax;
								else
									oro+=orovitt;
								if((elisir==elisirmax) || ((elisirmax-elisir)<elisirvitt))
									elisir=elisirmax;
								else
									elisir+=elisirvitt;
								vittoria=0;
								attmax=3;
								printf("VITTORIA\n");
								PlaySound(TEXT("CocBattleWin.wav"),NULL,SND_SYNC);
							}
							else if(sconfitta==1)
							{
								system("cls");
								if(trofei<=trofeisconf)
									trofei=0;
								else
									trofei-=trofeisconf;
								sconfitta=0;
								attmax=3;
								printf("SCONFITTA\n");
								PlaySound(TEXT("CocBattleDefeat.wav"),NULL,SND_SYNC);
							}
							PlaySound(TEXT("CocTheme.wav"),NULL,SND_ASYNC);
						}
						else
							printf("HAI GIA\' ATTACCATO DI RECENTE. ATTENDI %d GIORNI PER ATTACCARE DI NUOVO.\n", attmax);
						break;
					}
					case 4:
					{
						break;
					}
				}
				break;
			}
			case 5:
			{
				printf("GIORNATA CONCLUSA!\n");
				giorno++;
				
				if(attmax>0)
					attmax=attmax-1;
				else
					attmax=0;
					
				miglioramentominiera(nmo, &mo[3], &mo[0], &mo[2]);
				miglioramentominiera(nmo2, &mo2[3], &mo2[0], &mo2[2]);
				miglioramentominiera(nee, &ee[3], &ee[0], &ee[2]);
				miglioramentominiera(nee2, &ee2[3], &ee2[0], &ee2[2]);
				
				miglioramentodepositi(ndeporo, &deporo[2], &deporo[0], &deporo[1]);
				miglioramentodepositi(ndepelisir, &depelisir[2], &depelisir[0], &depelisir[1]);
				
				miglioramentoth(&th[3], &th[0], &th[1], &th[2]);
				
				miglioramentoc(nc, &c[3], &c[0], &c[2]);
				miglioramentoc(nc2, &c2[3], &c2[0], &c2[2]);
				miglioramentotorrea(ntorrea, &torrea[3], &torrea[0], &torrea[2]);
				
				miglioramentoacc(nacc, &acc[0], &acc[1], &acc[2]);
				miglioramentocaserma(&caserma[0], &caserma[1], sbloccato);
				
				//Difesa villaggio
				difesa=1;
				
				if(c[1]==0 && c[3]==0)
					difesa+=c[0];
				if(c2[1]==0 && c2[3]==0)
					difesa+=c2[0];
				if(torrea[1]==0 && torrea[3]==0)
					difesa+=torrea[0];
				
				probabilita = casuale(1,probmax);
				if(probabilita==1)
				{
					probabilita = casuale(1,difesa);
					if(probabilita==1 && mo[0]>0 && mo[3]==0)
						mo[1]=1;
					else
						mo[1]=0;
					
					probabilita = casuale(1,difesa);
					if(probabilita==1 && mo2[0]>0 && mo2[3]==0)
						mo2[1]=1;
					else
						mo2[1]=0;
					
					probabilita = casuale(1,difesa);
					if(probabilita==1 && ee[0]>0 && ee[3]==0)
						ee[1]=1;
					else
						ee[1]=0;
			
					probabilita = casuale(1,difesa);
					if(probabilita==1 && ee2[0]>0 && ee2[3]==0)
						ee2[1]=1;
					else
						ee2[1]=0;
					
					probabilita = casuale(1,difesa);
					if(probabilita==1 && c[0]>0 && c[3]==0)
						c[1]=1;
					else
						c[1]=0;
			
					probabilita = casuale(1,difesa);
					if(probabilita==1 && c2[0]>0 && c2[3]==0)
						c2[1]=1;
					else
						c2[1]=0;
					
					probabilita = casuale(1,difesa);
					if(probabilita==1 && torrea[0]>0 && torrea[3]==0)
						torrea[1]=1;
					else
						torrea[1]=0;
					
					probmax=20;
					printf("IL TUO VILLAGGIO E\' STATO ATTACCATO\n");
				}
				else
				{
					if(probmax>1)
						probmax=probmax-1;
					else
						probmax=1;
				}
				
				//Risorse
				if(mo[1]==0 && mo[3]==0)
					io+=mo[2];
				if(mo2[1]==0 && mo2[3]==0)						
					io+=mo2[2];
				
				if(ee[1]==0 && ee[3]==0)
					ie+=ee[2];
				if(ee2[1]==0 && ee2[3]==0)
					ie+=ee2[2];
				
				if((elisir==elisirmax) || ((elisirmax-elisir)<ie))
					elisir=elisirmax;
				else
					elisir=elisir+ie;
				if((oro==oromax) || ((oromax-oro)<io))
					oro=oromax;
				else
					oro=oro+io;
				break;
			}
			case 6:
			{
			    fp = fopen("dati.csv", "w");
				
			    fprintf(fp, "%d, %d, %d, %d\n", trofei, oro, elisir, attmax);
			    
			    fprintf(fp, "%d, %d, %d, %d\n", mo[0], mo[1], mo[2], mo[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", mo2[0], mo2[1], mo2[2], mo2[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", mo3[0], mo3[1], mo3[2], mo3[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", ee[0], ee[1], ee[2], ee[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", ee2[0], ee2[1], ee2[2], ee2[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", ee3[0], ee3[1], ee3[2], ee3[3]);
			    
			    fprintf(fp, "%d, %d, %d\n", deporo[0], deporo[1], deporo[2]);
			    fprintf(fp, "%d, %d, %d\n", deporo2[0], deporo2[1], deporo2[2]);
			    fprintf(fp, "%d, %d, %d\n", depelisir[0], depelisir[1], depelisir[2]);
			    fprintf(fp, "%d, %d, %d\n", depelisir2[0], depelisir2[1], depelisir2[2]);
			    
			    fprintf(fp, "%d, %d, %d, %d\n", th[0], th[1], th[2], th[3]);
			    
			    fprintf(fp, "%d, %d, %d, %d\n", c[0], c[1], c[2], c[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", c2[0], c2[1], c2[2], c2[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", torrea[0], torrea[1], torrea[2], torrea[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", mortaio[0], mortaio[1], mortaio[2], mortaio[3]);
			    
			    
			    fprintf(fp, "%d, %d\n", caserma[0], caserma[1]);
			    fprintf(fp, "%d, %d, %d\n", sbloccato[0], sbloccato[1], sbloccato[2]);
			    fprintf(fp, "%d, %d\n", barbaro[0], barbaro[1]);
			    fprintf(fp, "%d, %d\n", arciere[0], arciere[1]);
			    fprintf(fp, "%d, %d\n", gigante[0], gigante[1]);
			    
			    fprintf(fp, "%d, %d, %d\n", acc[0], acc[1], acc[2]);
			    
			    fprintf(fp, "%d, %d, %d\n", giorno, probabilita, probmax);
			    
			    fclose(fp);
			    
			    system("cls");
			    printf("Salvataggio completato\n");
				break;
			}
			case 6910469:
			{
				oro = 69104;
				elisir = 69104;
				break;
			}
		}
	}
	
	
	
	
	
	
	//francesco pradella francesco pradella francesco pradella francesco pradella francesco pradella fracesco pradella francesco pradella francesco pradella francesco pradella francesco pradella francesco pradella
	
	lvlmaxdepositi = 6;
	lvlmaxestrattori = 6;
	lvlmaxc = 4;
	lvlmaxtorrea = 3;
	lvlmaxacc = 3;
	
	giorno = 1;
	
	system("cls");
	PlaySound(TEXT("CocTheme.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
	
	do{	
		//MENU TH3
		oromax = 0;
		oromax = th[1] + deporo[1];
		elisirmax = 0;
		elisirmax = th[2]+ depelisir[1];
		ie = 50;
		io = 50;
		
		printf("Giorno %d\n", giorno);
		printf("Oro %d/%d | Elisir %d/%d\n\n", oro, oromax, elisir, elisirmax);
		printf("Risorse\n");
		if(mo[1]==1)
			printf("1) %s - Lvl %d | DISTRUTTO\n", nmo, mo[0]);
		else if(mo[3]!=0)
			printf("1) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nmo, mo[0], mo[3]);
		else
			printf("1) %s - Lvl %d\n", nmo, mo[0]);
		
		if(mo2[1]==1)
			printf("2) %s - Lvl %d | DISTRUTTO\n", nmo2, mo2[0]);
		else if(mo2[3]!=0)
			printf("2) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nmo2, mo2[0], mo2[3]);
		else
			printf("2) %s - Lvl %d\n", nmo2, mo2[0]);
		
		if(mo3[1]==1)
			printf("3) %s - Lvl %d | DISTRUTTO\n", nmo3, mo3[0]);
		else if(mo3[3]!=0)
			printf("3) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nmo3, mo3[0], mo3[3]);
		else if(giorno==1)
			printf("3) %s - Lvl %d | NUOVO\n", nmo3, mo3[0]);
		else
			printf("3) %s - Lvl %d\n", nmo3, mo3[0]);
	
		if(ee[1]==1)
			printf("4) %s - Lvl %d | DISTRUTTO\n", nee, ee[0]);
		else if(ee[3]!=0)
			printf("4) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nee, ee[0], ee[3]);
		else
			printf("4) %s - Lvl %d\n", nee, ee[0]);
	
		if(ee2[1]==1)
			printf("5) %s - Lvl %d | DISTRUTTO\n", nee2, ee2[0]);
		else if(ee2[3]!=0)
			printf("5) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nee2, ee2[0], ee2[3]);
		else
			printf("5) %s - Lvl %d\n", nee2, ee2[0]);
			
		if(ee3[1]==1)
			printf("6) %s - Lvl %d | DISTRUTTO\n\n", nee3, ee3[0]);
		else if(ee3[3]!=0)
			printf("6) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n\n", nee3, ee3[0], ee3[3]);
		else if(giorno==1)
			printf("6) %s - Lvl %d | NUOVO\n\n", nee3, ee3[0]);
		else
			printf("6) %s - Lvl %d\n\n", nee3, ee3[0]);

		if(deporo[2]!=0)
			printf("7) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", ndeporo, deporo[0], deporo[2]);
		else
			printf("7) %s - Lvl %d\n", ndeporo, deporo[0]);
		
		if(deporo2[2]!=0)
			printf("8) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", ndeporo2, deporo2[0], deporo2[2]);
		else if(giorno==1)
			printf("8) %s - Lvl %d | NUOVO\n", ndeporo2, deporo2[0]);
		else
			printf("8) %s - Lvl %d\n", ndeporo2, deporo2[0]);
		
		if(depelisir[2]!=0)
			printf("9) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", ndepelisir, depelisir[0], depelisir[2]);
		else		
			printf("9) %s - Lvl %d\n", ndepelisir, depelisir[0]);
			
		if(depelisir2[2]!=0)
			printf("10) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n\n", ndepelisir2, depelisir2[0], depelisir2[2]);
		else if(giorno==1)		
			printf("10) %s - Lvl %d | NUOVO\n\n", ndepelisir2, depelisir2[0]);
		else		
			printf("10) %s - Lvl %d\n\n", ndepelisir2, depelisir2[0]);
	
		printf("Principale\n");
		if(th[3]!=0)
			printf("11) Municipio - Lvl %d | MIGLIORAMENTO %d Giorni\n\n", th[0], th[3]);
		else
			printf("11) Municipio - Lvl %d\n\n", th[0]);
			
		printf("Difesa\n");
		
		if(c[1]==1)
			printf("12) %s - Lvl %d | DISTRUTTO\n", nc, c[0]);
		else if(c[3]!=0)
			printf("12) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nc, c[0], c[3]);
		else
			printf("12) %s - Lvl %d\n", nc, c[0]);
		
		if(c2[1]==1)
			printf("13) %s - Lvl %d | DISTRUTTO\n", nc2, c2[0]);
		else if(c2[3]!=0)
			printf("13) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", nc2, c2[0], c2[3]);
		else
			printf("13) %s - Lvl %d\n", nc2, c2[0]);
		
		if(torrea[1]==1)
			printf("14) %s - Lvl %d | DISTRUTTO\n", ntorrea, torrea[0]);
		else if(torrea[3]!=0)
			printf("14) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n", ntorrea, torrea[0], torrea[3]);
		else
			printf("14) %s - Lvl %d\n", ntorrea, torrea[0]);
			
		if(mortaio[1]==1)
			printf("15) %s - Lvl %d | DISTRUTTO\n\n", nmortaio, mortaio[0]);
		else if(mortaio[3]!=0)
			printf("15) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n\n", nmortaio, mortaio[0], mortaio[3]);
		else if(giorno==1)
			printf("15) %s - Lvl %d | NUOVO\n\n", nmortaio, mortaio[0]);
		else
			printf("15) %s - Lvl %d\n\n", nmortaio, mortaio[0]);
			
		printf("Esercito\n");
		if(acc[2]!=0)
			printf("16) %s - Lvl %d | MIGLIORAMENTO %d Giorni\n\n", nacc, acc[0], acc[2]);
		else
			printf("16) %s - Lvl %d\n\n", nacc, acc[0]);
			
		if(giorno==1)
			printf("17) Caserma - Lvl %d | NUOVO\n\n", caserma[0]);
		else
			printf("17) Caserma - Lvl %d\n\n", caserma[0]);
		
		printf("18) Attacca (%d Trofei)\n", trofei);
			
		printf("19) Concludi\n");
		
		printf("20) Salva\n");
		
		scanf("%d", &caso);
		system("cls");
		
		switch(caso)
		{
			case 1:
			{
				miglioraminiera(nmo, noro, nelisir, &mo[3], &elisir, &mo[0], &lvlmaxestrattori, &mo[2], &mo[1], caso);
				break;
			}
			case 2:
			{
				miglioraminiera(nmo2, noro, nelisir, &mo2[3], &elisir, &mo2[0], &lvlmaxestrattori, &mo2[2], &mo2[1], caso);
				break;
			}
			case 3:
			{
				miglioraminiera(nmo3, noro, nelisir, &mo3[3], &elisir, &mo3[0], &lvlmaxestrattori, &mo3[2], &mo3[1], caso);
				break;
			}
			case 4:
			{
				miglioraminiera(nee, nelisir, noro, &ee[3], &oro, &ee[0], &lvlmaxestrattori, &ee[2], &ee[1], caso);
				break;
			}
			case 5:
			{
				miglioraminiera(nee2, nelisir, noro, &ee2[3], &oro, &ee2[0], &lvlmaxestrattori, &ee2[2], &ee2[1], caso);
				break;
			}
			case 6:
			{
				miglioraminiera(nee3, nelisir, noro, &ee3[3], &oro, &ee3[0], &lvlmaxestrattori, &ee3[2], &ee3[1], caso);
				break;
			}
			case 7:
			{
				miglioradepositi(ndeporo, noro, nelisir, &deporo[2], &deporo[0], &lvlmaxdepositi, &deporo[1], &elisir, caso);
				break;
			}
			case 8:
			{
				miglioradepositi(ndeporo2, noro, nelisir, &deporo2[2], &deporo2[0], &lvlmaxdepositi, &deporo2[1], &elisir, caso);
				break;
			}
			case 9:
			{
				miglioradepositi(ndepelisir, nelisir, noro, &depelisir[2], &depelisir[0], &lvlmaxdepositi, &depelisir[1], &oro, caso);
				break;
			}
			case 10:
			{
				miglioradepositi(ndepelisir2, nelisir, noro, &depelisir2[2], &depelisir2[0], &lvlmaxdepositi, &depelisir2[1], &oro, caso);
				break;
			}
			case 11:
			{
				migliorath(&th[0], &oro, &th[1], &th[2], &th[3], caso);
				break;			
			}
			case 12:
			{
				migliorac(nc, &c[1], &c[0], &lvlmaxc, &oro, &c[3], caso);
				break;
			}
			case 13: 
			{
				migliorac(nc2, &c2[1], &c2[0], &lvlmaxc, &oro, &c2[3], caso);
				break;
			}
			case 14:
			{
				miglioratorrea(ntorrea, &torrea[1], &torrea[0], &lvlmaxtorrea, &oro, &torrea[3], caso);
				break;
			}
			case 15:
			{
				miglioramortaio(nmortaio, &mortaio[1], &mortaio[0], &lvlmaxmortaio, &oro, &mortaio[3], caso);
				break;
			}
			case 16:
			{
				miglioraacc(nacc, &acc[0], &acc[1], &lvlmaxacc, &elisir, &acc[2], caso);
				break;
			}
			case 17:
			{
				miglioracaserma(&caserma[0], &lvlmaxcaserma, &elisir, &caserma[1], &acc[1], &esercito, sbloccato, barbaro, arciere, gigante, caso);
				break;
			}
			case 18:
			{	
				if(attmax==0)
				{
					PlaySound(TEXT("CocBattle.wav"),NULL,SND_ASYNC);
					if(trofei<=100)
					{	
					
						probabilita = casuale(2,3);
						ac[0]=probabilita;
						
						probabilita = casuale(2,3);
						ac2[0]=probabilita;
						
						probabilita = casuale(1,2);
						atorrea[0]=probabilita;
						
						probabilita = casuale(1,1);
						amortaio[0]=probabilita;
					
						probabilita = casuale(500,1200);
						orovitt=probabilita;
						
						probabilita = casuale(500,1200);
						elisirvitt=probabilita;
						
						probabilita = casuale(12,35);
						trofeivitt=probabilita;
						
						probabilita = casuale(18,30);
						trofeisconf=probabilita;
					}
					if(trofei>100 && trofei<=300)
					{
						probabilita = casuale(2,4);
						ac[0]=probabilita;
						
						probabilita = casuale(2,4);
						ac2[0]=probabilita;
						
						probabilita = casuale(1,2);
						atorrea[0]=probabilita;
						
						probabilita = casuale(1,1);
						amortaio[0]=probabilita;
					
						probabilita = casuale(800,1400);
						orovitt=probabilita;
						
						probabilita = casuale(800,1400);
						elisirvitt=probabilita;
						
						probabilita = casuale(18,35);
						trofeivitt=probabilita;
						
						probabilita = casuale(20,30);
						trofeisconf=probabilita;
					}
					if(trofei>300)
					{
						probabilita = casuale(3,4);
						ac[0]=probabilita;
						
						probabilita = casuale(3,4);
						ac2[0]=probabilita;
						
						probabilita = casuale(2,3);
						atorrea[0]=probabilita;
						
						probabilita = casuale(1,1);
						amortaio[0]=probabilita;
					
						probabilita = casuale(1200,2000);
						orovitt=probabilita;
						
						probabilita = casuale(1200,2000);
						elisirvitt=probabilita;
						
						probabilita = casuale(20,35);
						trofeivitt=probabilita;
						
						probabilita = casuale(25,30);
						trofeisconf=probabilita;
						
					}
					esercito=acc[1];
					fine=0;
					ac[1]=0;
					ac2[1]=0;
					atorrea[1]=0;
					int flag = 0;	
					do{
						printf("VILLAGGIO NEMICO\n");
					
						printf("Vittoria + %d Oro | + %d Elisir | + %d Trofei\n", orovitt, elisirvitt, trofeivitt);
						printf("Sconfitta - %d Trofei\n", trofeisconf);
						
						printf("Esercito %d/%d truppe\n\n", esercito, acc[1]);
						printf("Municipio Lvl 3\n");
						
						if(ac[1]==0)
							printf("1) Cannone Lvl %d\n", ac[0]);
						else
							printf("1) Cannone Lvl %d | DISTRUTTO\n", ac[0]);
						if(ac2[1]==0)
							printf("2) Cannone 2 Lvl %d\n", ac2[0]);
						else
							printf("2) Cannone 2 Lvl %d | DISTRUTTO\n", ac2[0]);
						if(atorrea[1]==0)
							printf("3) Torre dell\'arciere Lvl %d\n", atorrea[0]);
						else
							printf("3) Torre dell\'arciere Lvl %d | DISTRUTTO\n", atorrea[0]);
						if(amortaio[1]==0)
							printf("4) Mortaio Lvl %d\n\n", amortaio[0]);
						else
							printf("4) Mortaio Lvl %d | DISTRUTTO\n\n", amortaio[0]);
							
						printf("5) Torna al villaggio\n");
						scanf("%d", &caso);
						system("cls");
						switch(caso)
						{
							case 1:
							{
								attacco(ac, caso, &esercito, &sconfitta, &vittoria, &flag, sbloccato, barbaro, arciere, gigante);
								break;
							}
							case 2:
							{
								attacco(ac2, caso, &esercito, &sconfitta, &vittoria, &flag, sbloccato, barbaro, arciere, gigante);
								break;
							}
							case 3:
							{
								attacco(atorrea, caso, &esercito, &sconfitta, &vittoria, &flag, sbloccato, barbaro, arciere, gigante);
								break;
							}
							case 4:
							{
								attacco(amortaio, caso, &esercito, &sconfitta, &vittoria, &flag, sbloccato, barbaro, arciere, gigante);
								break;
							}
							case 5:
							{
								system("cls");
								if(flag!=0)
									sconfitta=1;
								else
									fine=1;
								break;
							}
							default:
								printf("FUNZIONE NON PRESENTE.\n");
								break;
						}
						if(ac[1]==1 && ac2[1]==1 && atorrea[1]==1 && mortaio[1]==1){
							vittoria=1;
						}
					}while(fine==0 && sconfitta==0 && vittoria==0);
					if(vittoria==1)
					{
						system("cls");
						trofei+=trofeivitt;
						oro+=orovitt;
						elisir+=elisirvitt;
						vittoria=0;//se mi spoileri un film marvel ti ammazzo - muore iron man - forza juve
						attmax=3;
						printf("VITTORIA\n");
						PlaySound(TEXT("CocBattleWin.wav"),NULL,SND_SYNC);
					}
					else if(sconfitta==1)
					{
						system("cls");
						if(trofei<=trofeisconf)
							trofei=0;
						else
							trofei-=trofeisconf;
						sconfitta=0;
						attmax=3;
						printf("SCONFITTA\n");
						PlaySound(TEXT("CocBattleDefeat.wav"),NULL,SND_SYNC);
					}
					PlaySound(TEXT("CocTheme.wav"),NULL,SND_ASYNC);
				}
				else
					printf("HAI GIA\' ATTACCATO DI RECENTE. ATTENDI %d GIORNI PER ATTACCARE DI NUOVO.\n", attmax);
			break;
			}
			case 19:
			{
				printf("GIORNATA CONCLUSA!\n");
				giorno++;
				
				if(attmax>0)
					attmax=attmax-1;
				else
					attmax=0;
					
				miglioramentominiera(nmo, &mo[3], &mo[0], &mo[2]);
				miglioramentominiera(nmo2, &mo2[3], &mo2[0], &mo2[2]);
				miglioramentominiera(nmo3, &mo3[3], &mo3[0], &mo3[2]);
				miglioramentominiera(nee, &ee[3], &ee[0], &ee[2]);
				miglioramentominiera(nee2, &ee2[3], &ee2[0], &ee2[2]);
				miglioramentominiera(nee3, &ee3[3], &ee3[0], &ee3[2]);
				
				miglioramentodepositi(ndeporo, &deporo[2], &deporo[0], &deporo[1]);
				miglioramentodepositi(ndeporo2, &deporo2[2], &deporo2[0], &deporo2[1]);
				miglioramentodepositi(ndepelisir, &depelisir[2], &depelisir[0], &depelisir[1]);
				miglioramentodepositi(ndepelisir2, &depelisir2[2], &depelisir2[0], &depelisir2[1]);
				
				miglioramentoth(&th[3], &th[0], &th[1], &th[2]);
				
				miglioramentoc(nc, &c[3], &c[0], &c[2]);
				miglioramentoc(nc2, &c2[3], &c2[0], &c2[2]);
				miglioramentotorrea(ntorrea, &torrea[3], &torrea[0], &torrea[2]);
				miglioramentomortaio(nmortaio, &mortaio[3], &mortaio[0], &mortaio[2]);
				//miranda perez juan carlos
				miglioramentoacc(nacc, &acc[0], &acc[1], &acc[2]);
				miglioramentocaserma(&caserma[0], &caserma[1], sbloccato);
				
				//Difesa villaggio
				difesa=1;
				
				if(c[1]==0 && c[3]==0)
					difesa+=c[0];
				if(c2[1]==0 && c2[3]==0)
					difesa+=c2[0];
				if(torrea[1]==0 && torrea[3]==0)
					difesa+=torrea[0];
				
				probabilita = casuale(1,probmax);
				if(probabilita==1)
				{
					probabilita = casuale(1,difesa);
					if(probabilita==1 && mo[0]>0 && mo[3]==0)
						mo[1]=1;
					else
						mo[1]=0;
					
					probabilita = casuale(1,difesa);
					if(probabilita==1 && mo2[0]>0 && mo2[3]==0)
						mo2[1]=1;
					else
						mo2[1]=0;
					
					probabilita = casuale(1,difesa);
					if(probabilita==1 && ee[0]>0 && ee[3]==0)
						ee[1]=1;
					else
						ee[1]=0;
			
					probabilita = casuale(1,difesa);
					if(probabilita==1 && ee2[0]>0 && ee2[3]==0)
						ee2[1]=1;
					else
						ee2[1]=0;
					
					probabilita = casuale(1,difesa);
					if(probabilita==1 && c[0]>0 && c[3]==0)
						c[1]=1;
					else
						c[1]=0;
			
					probabilita = casuale(1,difesa);
					if(probabilita==1 && c2[0]>0 && c2[3]==0)
						c2[1]=1;
					else
						c2[1]=0;
					
					probabilita = casuale(1,difesa);
					if(probabilita==1 && torrea[0]>0 && torrea[3]==0)
						torrea[1]=1;
					else
						torrea[1]=0;
					
					probmax=20;
					printf("IL TUO VILLAGGIO E\' STATO ATTACCATO\n");
				}
				else
				{
					if(probmax>1)
						probmax=probmax-1;
					else
						probmax=1;
				}
				
				//Risorse
				if(mo[1]==0 && mo[3]==0)
					io+=mo[2];
				if(mo2[1]==0 && mo2[3]==0)						
					io+=mo2[2];
				
				if(ee[1]==0 && ee[3]==0)
					ie+=ee[2];
				if(ee2[1]==0 && ee2[3]==0)
					ie+=ee2[2];
				
				if((elisir==elisirmax) || ((elisirmax-elisir)<ie))
					elisir=elisirmax;
				else
					elisir=elisir+ie;
				if((oro==oromax) || ((oromax-oro)<io))
					oro=oromax;
				else
					oro=oro+io;
			break;
			}
			case 20:
				fp = fopen("dati.csv", "w");
				
			    fprintf(fp, "%d, %d, %d, %d\n", trofei, oro, elisir, attmax);
			    
			    fprintf(fp, "%d, %d, %d, %d\n", mo[0], mo[1], mo[2], mo[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", mo2[0], mo2[1], mo2[2], mo2[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", mo3[0], mo3[1], mo3[2], mo3[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", ee[0], ee[1], ee[2], ee[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", ee2[0], ee2[1], ee2[2], ee2[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", ee3[0], ee3[1], ee3[2], ee3[3]);
			    
			    fprintf(fp, "%d, %d, %d\n", deporo[0], deporo[1], deporo[2]);
			    fprintf(fp, "%d, %d, %d\n", deporo2[0], deporo2[1], deporo2[2]);
			    fprintf(fp, "%d, %d, %d\n", depelisir[0], depelisir[1], depelisir[2]);
			    fprintf(fp, "%d, %d, %d\n", depelisir2[0], depelisir2[1], depelisir2[2]);
			    
			    fprintf(fp, "%d, %d, %d, %d\n", th[0], th[1], th[2], th[3]);
			    
			    fprintf(fp, "%d, %d, %d, %d\n", c[0], c[1], c[2], c[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", c2[0], c2[1], c2[2], c2[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", torrea[0], torrea[1], torrea[2], torrea[3]);
			    fprintf(fp, "%d, %d, %d, %d\n", mortaio[0], mortaio[1], mortaio[2], mortaio[3]);
			    
			    
			    fprintf(fp, "%d, %d\n", caserma[0], caserma[1]);
			    fprintf(fp, "%d, %d, %d\n", sbloccato[0], sbloccato[1], sbloccato[2]);
			    fprintf(fp, "%d, %d\n", barbaro[0], barbaro[1]);
			    fprintf(fp, "%d, %d\n", arciere[0], arciere[1]);
			    fprintf(fp, "%d, %d\n", gigante[0], gigante[1]);
			    
			    fprintf(fp, "%d, %d, %d\n", acc[0], acc[1], acc[2]);
			    
			    fprintf(fp, "%d, %d, %d\n", giorno, probabilita, probmax);
			    
			    fclose(fp);
			    
			    system("cls");
			    printf("Salvataggio completato\n");
			break;
			default:
				printf("FUNZIONE NON PRESENTE.\n");
				break;
			case 6910469:
				oro = 69104;
				elisir = 69104;
				break;
		}
	}while(th[0]<4); //federico chiodi beta tester ufficiale
}
