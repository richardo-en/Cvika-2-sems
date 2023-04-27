#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Pocet_Zaznamov 10 

void x(char **IDprispevku_1,  int velkost_pola){
    int k , l, value=65;
	char controll;
    int list_to_compare[62];
    int count[62];
	for (int i = 0; i < 62; i++)
	{
		list_to_compare[i] = value;
		if (i == 25)
		{
			value = 96;
		}else if (i == 50)
		{
			value = 48;
		}
		value++;
		count[i] = 0;	
	}
	
	
    while (1)
    {
        scanf("%d %d" , &k , &l);
        if (k > 0 && l > 0  && l <= 9 && k<l)
        {
           break;
        }
    }

    for (int i = 0; i < velkost_pola; i++)
    {
        for (int letter = k-1; letter-1 < l; letter++)
        {
			int controll = IDprispevku_1[i][letter];
			for (int z = 0; z < 62; z++)
			{
				if (controll == list_to_compare[z])
				{
					count[z]++;
				}
			}
			
        }
    }
    
	for (int i = 0; i < 62; i++)
	{
		if (count[i] != 0)
		{
			printf("%c   ", list_to_compare[i]);
		}
	}
	printf("\n");
	for (int i = 0; i < 62; i++)
	{
		if (count[i] != 0)
		{
			printf("%d   ", count[i]);
		}
	}
}

char** e (char ** MenaAutorov, int velkost_pola, char ZNAK, int *VelkostMENA){
	char ** MENAx = NULL;
	char string[300];
	int index = 0, count = 0, name_index= 0;
	for (int i = 0; i < velkost_pola; i++)
	{
		while (MenaAutorov[i][name_index] != '\n')
		{
			string[index] = MenaAutorov[i][name_index];

			if (MenaAutorov[i][name_index + 2] == ZNAK)
			{
				count++;
				if (count == 0)
				{
					(*MENAx) = (char *)malloc(sizeof(char * ) * count);
				}else{
					(*MENAx) = (char *)realloc((*MENAx), sizeof(char * ) * count);
				}
				(*MENAx)[count-1] = malloc(sizeof(char) * index);
				strcpy((*MENAx)[count-1] , string);
				index = -1;
				name_index += 3;
			}
			index++;
			name_index++;
		}
		
		
	}
	
}


int main() {
	char **IDprispevku = NULL;
	char **MenaAutorov = NULL;
	int i = 0, j=0;
	char riad;

	IDprispevku = (char**)malloc(Pocet_Zaznamov * sizeof(char*));  
	for (i = 0; i < Pocet_Zaznamov; i++) {
		IDprispevku[i] = (char*)malloc(11 * sizeof(char));  
		switch(i){
		   case 0:  strcpy(*(IDprispevku + i), "UP12345678"); break;
		   case 1:  strcpy(*(IDprispevku + i), "UD12345678"); break;
		   case 2:  strcpy(*(IDprispevku + i), "PD12345678"); break;
		   case 3:  strcpy(*(IDprispevku + i), "PP12345678"); break;
	       case 4:  strcpy(*(IDprispevku + i), "UP56556576"); break;
		   case 5:  strcpy(*(IDprispevku + i), "UP12345678"); break;
		   case 6:  strcpy(*(IDprispevku + i), "PP12345678"); break;
		   case 7:  strcpy(*(IDprispevku + i), "UP98765432"); break;
		   case 8:  strcpy(*(IDprispevku + i), "UD12345678"); break;
		   case 9:  strcpy(*(IDprispevku + i), "UP76523567"); break;
		   default:  strcpy(*(IDprispevku + i), "PP29384729"); 
		
		}
	}

	MenaAutorov = (char**)malloc(Pocet_Zaznamov * sizeof(char*));  
	for (i = 0; i < Pocet_Zaznamov; i++) {
     	switch(i){
		  case 0:{
		      MenaAutorov[i] = (char*)malloc((strlen("Julius Novak#A#Marek Kovac#K#") +1)  * sizeof(char)); 
			  strcpy(*(MenaAutorov + i), "Julius Novak#A#Marek Kovac#K#");
		    } break;
	     case 1:{
		     MenaAutorov[i] = (char*)malloc((strlen("Lucia Ondrejkova#K#Lukas Hvizdal#A#") +1)  * sizeof(char)); 
			 strcpy(*(MenaAutorov + i), "Lucia Ondrejkova#K#Lukas Hvizdal#A#");
		   } break;
         case 2:{
		     MenaAutorov[i] = (char*)malloc((strlen("MARCEL VON TAKAC#K#ANDREA NOVOTNA#A#") +1)  * sizeof(char)); 
			 strcpy(*(MenaAutorov + i), "MARCEL VON TAKAC#K#ANDREA NOVOTNA#A#");
		   } break;
         case 3:{
		     MenaAutorov[i] = (char*)malloc((strlen("Ondrej Zatko#A#") +1)  * sizeof(char)); 
			 strcpy(*(MenaAutorov + i), "Ondrej Zatko#A#");
		   } break;
        case 4:{
		     MenaAutorov[i] = (char*)malloc((strlen("Lucia Ondrejkova#A#Lukas Hvizdal#K#Janko Mrkvicka#S#") +1)  * sizeof(char)); 
			 strcpy(*(MenaAutorov + i), "Lucia Ondrejkova#A#Lukas Hvizdal#K#Janko Mrkvicka#S#");
		   } break;
        case 5:{
		     MenaAutorov[i] = (char*)malloc((strlen("Janko Mrkvicka#A#Lena Von Der Brecht#S#") +1)  * sizeof(char)); 
			 strcpy(*(MenaAutorov + i), "Janko Mrkvicka#A#Lena Von Der Brecht#S#");
		   } break;
       case 6:{
		     MenaAutorov[i] = (char*)malloc((strlen("Janko Mrkvicka#A#Hana Von Der Brecht#A#") +1)  * sizeof(char)); 
			 strcpy(*(MenaAutorov + i), "Janko Mrkvicka#A#Hana Von Der Brecht#A#");
		   } break;
       default:  {
		     MenaAutorov[i] = (char*)malloc((strlen("Neviem Neviem#A#") +1)  * sizeof(char)); 
			 strcpy(*(MenaAutorov + i), "Neviem Neviem#A#");
		   } 		
		}
	}

    
	   
	while ( scanf(" %c", &riad) == 1 && riad != 'k'){
		switch(riad){
		   case 'v': {
	                   // vypis poli
						for (i = 0; i < Pocet_Zaznamov; i++) {
							printf("%s \n",IDprispevku[i]);
						}

						for (i = 0; i < Pocet_Zaznamov; i++) {
							printf("%s \n",MenaAutorov[i]);
						}				 
					 } break;
			 case 'a': { 
				        printf("a:");
					} break;
		     case 'x': { 
                        x(IDprispevku , Pocet_Zaznamov);
					} break;
             case 'e': { 
					char character;
					scanf(" %c" , &character);
				        // e(MenaAutorov , Pocet_Zaznamov , )
					} break;
		   
		}
	}
	   
	
	
	
	
	
	
 

	
    // uvolnenie poli
	for (i = 0; i < Pocet_Zaznamov; i++) {
	    free(*(IDprispevku + i));
		*(IDprispevku + i) = NULL;
		free(*(MenaAutorov + i));
		*(MenaAutorov + i) = NULL;
	}
	free(IDprispevku);
	IDprispevku = NULL;
	free(MenaAutorov);
	MenaAutorov = NULL;
	

	return 0;
}

