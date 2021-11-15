#include <stdio.h>

struct Spielfeld{
	int Feld[3][3];
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

int main(){
	struct Spielfeld spielfeld;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			spielfeld.Feld[i][j] = 0;
		}
	}

	spielfeld.Feld[0][0] = 1;
	spielfeld.Feld[0][1] = 2;
	SpielfeldAusgeben(spielfeld);

	return 0;
}
