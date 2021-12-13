#include <stdio.h>
#include <stdlib.h>

int getNumberofLines(FILE* file){
	int iCounter = 1;
	char cAktuell = fgetc(file);

	while(cAktuell != EOF){
		if(cAktuell == '\n'){
			iCounter++;
		}
		cAktuell = fgetc(file);
	}
	fseek(file, 0, SEEK_SET);

	return iCounter;
}

char* getLineOwn(FILE* file){
	char* string = malloc(sizeof(char) * 100);

	fscanf(file, "%[^\n]", string);

	return string;
}

int main(int argc, char* argv[]){
	printf("Hallo Welt\n");

	FILE* file;

	file = fopen(argv[1], "r");

	int iNumberLines = getNumberofLines(file);
	printf("%d\n", iNumberLines);

	//fscanf
	for(int i = 0; i < iNumberLines; i++){
		int x, y;
		int iError = fscanf(file, "X=%d Y=%d\n", &x, &y);
		printf("Richtig eingelesene Zeichen: %d", iError);
		if(iError != 2){
			printf("Fehler\n");
			while(fgetc(file) != '\n'){

			}
		}
		else{
			printf("Ergebnis %d: %d\n", i, x + y);
		}
	}

	fseek(file, 0, SEEK_SET);
	char* string;
	string = getLineOwn(file);

	printf("%s\n", string);

	fclose(file);
	free(string);

	return 0;
}
