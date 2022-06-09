#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct of vehicle registration
typedef struct {
       int code;
       char plate[20];
       char city [35];
       char model [20];
       char color [20];
}Vehicles;
Vehicles vehicles[MAX];

// Procedures
void init(){
    int i;
      for(i = 2; i < MAX; i++){
          vehicles[i].code = i;
          strcpy(vehicles[i].plate, " ");
          strcpy(vehicles[i].city, " ");
          strcpy(vehicles[i].model, " ");
          strcpy(vehicles[i].color, " ");
      }
}

// Insert new vehicle
void insert(){
    int i;
    for(i = 0; i < MAX; i++){
        if(strcmp(vehicles[i].placa, " ") == 0){
            printf ("Insert data:\n");
            printf ("Vehicle plate number.: ");
            scanf("%s", vehicles[i].plate);
            fflush(stdin);
            printf ("City...........: ");
            scanf("%s", vehicles[i].city);
            fflush(stdin);
            printf ("Model...........: ");
            scanf("%s", vehicles[i].model);
            fflush(stdin);
            printf ("Vehicle color...:");
            scanf("%s", vehicles[i].color);
            fflush(stdin);
            return;
        }
    }
};

// Update vehicle data
void update(){
    int i, code;
    system("cls");
    printf("Which record do you want to update :\n");
    for(i = 0; i < MAX; i++){
        if(strcmp(vehicles[i].plate, " ") != 0){
            printf("\nVehicle code: %d\n Plate number: %s\n Model: %s\n Color: %s\n City: %s\n\n",
               vehicles[i].code, vehicles[i].plate, vehicles[i].model, vehicles[i].color, vehicles[i].city);
        }
    }
    printf("Informe o codigo do veiculo a ser alterado: ");
    printf("Type your choose: ");
    scanf("%d", &code);
    if(strcmp(vehicles[code].plate, " ") == 0){
        printf("\nWrong code. Vehicle doesn't exist!\n\n");
    }else{
        printf ("Vehicle plate.: ");
        scanf("%s", vehicles[code].plate);
        fflush(stdin);
        printf ("City...........: ");
        scanf("%s", vehicles[code].city);
        fflush(stdin);
        printf ("Model...........: ");
        scanf("%s", vehicles[code].model);
        fflush(stdin);
        printf ("Vehicle color...:");
        scanf("%s", vehicles[code].color);
        fflush(stdin);
        printf("\n Updated!\n\n");
    }
};

// Search function 
void search(){
    int i, searchCod;
    system("cls");
    printf("\n Which vehicle do you want to see? ");
    scanf("%d",&searchCod);
    if(strcmp(vehicles[searchCod].plate, " ") == 0){
        printf("\nWrong code. Vehicle doesn't exist!\n\n");
    }else{
        printf("\nVehicle code: %d\n Plate: %s\n Model: %s\n Color: %s\n City: %s\n\n",
               vehicle[searchCod].code, vehicle[searchCod].plate, vehicle[searchCod].model, vehicle[searchCod].color, vehicle[searchCod].city);
    }
};

// Delete function
void delete(){
    int deleteCode;
    system("cls");
    printf("Which vehicle do you want do delete?: ");
    for(int i = 0; i < MAX; i++){
        if(strcmp(vehicles[i].placa, " ") != 0){
            printf("\nVehicle code: %d\n Plate number: %s\n Model: %s\n Color: %s\n City: %s\n\n",
               vehicles[i].code, vehicles[i].plate, vehicles[i].model, vehicles[i].color, vehicles[i].city);
        }
    }
    printf("Type the code of the vehicle to be deleted: ");
    scanf("%d", &deleteCode);
    if(strcmp(vehicles[deleteCode].plate, " ") == 0){
        printf("\nWrong code. Vehicle doesn't exist!\n\n");
    }else{
        vehicles[deleteCode].code = deleteCode;
        strcpy(vehicles[deleteCode].plate, " ");
        strcpy(vehicles[deleteCode].city, " ");
        strcpy(vehicles[deleteCode].model, " ");
        strcpy(vehicles[deleteCode].color, " ");
        printf("Deleted!\n\n");
    }
};

// Function "about" 
void about(){
     system ("cls");
     printf ("Ramon Medeiros\n");
     printf ("Press a key to go back to menu...\n\n");
     getchar();
};

// vehicles already inserted at base
void cad_base(){
    vehicles[0].code = 1;
    strcpy(vehicles[0].plate, "3SAM123");
    strcpy(vehicles[0].city, "California");
    strcpy(vehicles[0].model, "Ford");
    strcpy(vehicles[0].color, "White");
    vehicles[1].code = 2;
    strcpy(vehicles[1].plate, "BDC4544");
    strcpy(vehicles[1].city, "Arizona");
    strcpy(vehicles[1].model, "Fiat");
    strcpy(vehicles[1].color, "Black");
};

// Main function
int main(){
    //Options
    int option;
    cad_base();
    inicializar();
    do{
        printf("======================== MENU =======================\n");
        printf ("|           Vehicle registration system            |\n");
        printf ("----------------------------------------------------\n");
        printf ("|    1 - Insert new vehicle                        |\n");
        printf ("|    2 - Update                                    |\n");
        printf ("|    3 - Search by code                            |\n");
        printf ("|    4 - Delete a vehicle                          |\n");
        printf ("|    5 - About this system                         |\n");
        printf ("|    9 - Close application                          |\n");
        printf ("----------------------------------------------------\n");
        printf ("Type the option: ");
        scanf ("%d", &option);
        printf ("------------------------------------------------------\n");
        switch (option) {
            case 1:
                insert();
            break;
            case 2:
                update();
            break;
            case 3:
                search();
            break;
            case 4:
                 delete();
            break;
            case 5:
                 about();
            break;
            case 9:
                printf ("Closing...\n");
            break;
            default:
                printf ("Invalid option!!!\n");
                printf ("Press a key to continue...\n\n");
        }
    }while(option != 9);
  return 0;
}
