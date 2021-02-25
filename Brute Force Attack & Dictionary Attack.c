/* Title:  BruteForce & Dictionary Attack
   Author: Αντώνιος - Διονύσιος Παύλοζας
   A.M.:   2016523
   Date:   31/05/2017
*/


#define _XOPEN_SOURCE
#include<unistd.h>

//Dilosi bibliothikon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>

//Dilosi prototypon synartiseon
void hashTest(char* pass, char* passFile, char* wordListFile);
int countWords(char* file);

int main(int argc, char *argv[]){
	//Dilosi topikon metabliton
	char buffer[255];
	char user[255];
	char hash[255];
	int i;
	FILE *fd; // Deiktis arxeioy word.english.txt
	printf("Reading Dictionary: %s\n",argv[1]); 
	for(i = 1; i < argc; i++)
	{
		if((strcmp(argv[i],"-p")==0) && (i+1 < argc))
		{
			fd = fopen(argv[1], "r"); // Άnoigma Arxeioy words.english.txt
			if(!fd)
			{ 
				printf("There is not such file.\n"); // Typonei minyma lathoys ean den brei to arxeio words.english.txt
				hashTest(argv[1], argv[i+1], argv[0]);
			}
			else
			{
				int count = countWords(argv[1]); // Klisi synartisis countWords
				int counter = 0; // Arxikopoiisi metablitis counter
				printf("Reading Password file: %s\n\n",argv[i+1]);
				while(fscanf(fd, "%s", buffer) != EOF) // Topothetisi ton lexeon ston pinaka buffer mexri to telos toy arxeioy words.english.txt
				{
					counter++; // Ayxise tin metabliti counter kata ena
					printf("\rCount: %d/%d", counter, count); 
					hashTest(buffer, argv[i+1], argv[0]); // Klisi synartisis hashTest
				}
				fclose(fd); // Kleisimo arxeio words.english.txt
			}
		}
	}
	
	return 0;
}


void hashTest(char* pass, char* passFile, char* wordListFile) // Orismos synartisis hashTest
{
	// Dilosi Topikon Metabliton
	char buffer[255];
	char user[255];
	char hash[255];
	FILE *fd;    // Deiktis arxeioy shadow.txt
	fd = fopen(passFile, "r"); // Άnoigma arxeioy shadow.txt
	if(fd == NULL)
	{
		 printf("There is not such file.\n"); // Typonei minyma lathoys ean den brei to arxeio shadow.txt
	}
	while(fscanf(fd, "%s", buffer) != EOF) // Topothetisi ton lexeon ston pinaka buffer 
	{
		sscanf(buffer, "%[^:]:%[^:]", user, hash); // Diabazei ta stoixeia user:hash apo ton buffer pinaka
		if(hash[0] == '$')
		{
			char salt[255];
			sscanf(hash, "$6$%[^$]", salt); // Diabazei ta stoixeia salt apo ton hash pinaka
			char newsalt[255];
			sprintf(newsalt, "$6$%s$", salt); // Ensomatonei ta stoixeia salt ston pinaka newsalt
			if(strcmp(crypt(pass, newsalt), hash)==0)    // Sygkrisi toy hash poy brethike apo tin crypt me tin hash toy arxeioy shadow
			{
				printf("\rPassword Found: %s for user: %s\n",pass,user); 
			}
		}
	}
	fclose(fd); // Kleisimo arxeio shadow.txt
}

int countWords(char* file) // Orismos synartisis countWords
{
	// Dilosi topikon metabliton
	int counter = 0; // Arxikopoiisi metablitis counter
	char buffer[255];
	FILE *fd; // Deiktis arxeioy words.english.txt
	fd = fopen(file, "r"); // Άnoigma arxeioy words.english.txt
	if(fd == NULL)
	{ 
		printf("There is not such file.\n"); // Typonei minyma lathoys ean den brei to arxeio words.english.txt
	}
	while(fscanf(fd, "%s", buffer) != EOF) // Topothetisi ton lexeon ston pinaka buffer mexri to telos toy arxeioy words.english.txt
	{
		counter++; // Ayxise tin metabliti counter kata ena
	}
	return counter; // Epistrefei to synolo ton lexeon poy yparxoyn sto arxeio words.english.txt 
}


