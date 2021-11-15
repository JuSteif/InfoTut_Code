#include <stdio.h>

struct Spielfeld{
	int Feld[3][3];
};

struct Spieler{
	int ind;
};

void SpielfeldAusgeben(struct Spielfeld spielfeld){
	for(int i = 0; i < 3; i++){
		printf("| ");
		for(int j = 0; j < 3; j++){
			switch(spielfeld.Feld[i][j]){
			case 0:
				printf(" ");
				break;
			case 1:
				printf("X");
				break;
			case 2:
				printf("O");
				break;
			}

			printf(" | ");
		}
		printf("\n");
	}
}

int einlesen(struct Spielfeld* spielfeld, struct Spieler* aktuellerSpieler){
	int pos; // Darf nicht kleiner als 1 sein und nicht größer als 9
	printf("Gib die Position an: ");
	scanf("%d", &pos);

	if(pos < 1 || pos > 9){
		printf("Wir gehen hier raus\n");
		return 1;
	}
	pos--;
	int x = pos % 3;
	int y = pos / 3;

	spielfeld->Feld[y][x] = aktuellerSpieler->ind;

	return 0;
}

int main(){
	struct Spielfeld spielfeld;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			spielfeld.Feld[i][j] = 0;
		}
	}

	struct Spieler spieler1;
	spieler1.ind = 1;

	struct Spieler spieler2;
	spieler2.ind = 2;

	struct Spieler* aktuellerSpieler = &spieler1;

	while(1){
		SpielfeldAusgeben(spielfeld);
		int fehler = einlesen(&spielfeld, aktuellerSpieler);
		while(fehler){
			fehler = einlesen(&spielfeld, aktuellerSpieler);
		}

		if(aktuellerSpieler == &spieler1){
			aktuellerSpieler = &spieler2;
		}
		else{
			aktuellerSpieler = &spieler1;
		}
	}


	return 0;
}
