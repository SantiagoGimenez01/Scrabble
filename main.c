#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int ForgC=15;
int BackC=1;
int juego(int num_jugadores);
void textcolor(int colortexto);
void SetColorAndBackground(int ForgC, int BackC);
void gotoxy(int x,int y);
int main()
{

    int menu_opc;
    int num_jugadores=0;
    int i=0,k=0;
    int l=0;
    int cont;
    char nombres[8][50];
    //Menu
    do
    {
    cont=0;
    SetColorAndBackground(10,0);
    system("cls");
    gotoxy(40,1);
    printf("Bienvenido al menu principal:\n");
    gotoxy(1,4);
    printf("1.Comenzar el juego");
    gotoxy(1,6);
    printf("2.Como jugar");
    gotoxy(1,8);
    printf("0.Salir");
    gotoxy(1,2);
    printf("Seleccione una opcion:");
    scanf("%d",&menu_opc);
    SetColorAndBackground(0,1);
    switch(menu_opc)
    {
    case 0://Salida
        system("cls");
        gotoxy(40,1);
        printf("Juego terminado");
        gotoxy(1,2);
        printf("Muchas gracias por jugar scrabble, esperamos que te hayas divertido, hasta pronto!!.\n");
        break;
    case 1://Juego
    system("cls");
    textcolor(15);
    gotoxy(45,5);
    printf("JUEGO CARGANDO");
    textcolor(15);
    gotoxy(15,8);
    printf("%c",218);
    gotoxy(94,8);
    printf("%c",191);
    gotoxy(15,9);
    printf("%c",179);
    gotoxy(15,10);
    printf("%c",192);
    gotoxy(94,10);
    printf("%c",217);
    gotoxy(94,9);
    printf("%c",179);

    for(l=1;l<79;l++)
    {
        gotoxy(l+15,8);
        printf("%c",196);
        gotoxy(l+15,10);
        printf("%c",196);

    }

    textcolor(0);
    for(l=1;l<79;l++)
    {
        Sleep(50);
        gotoxy(l+15,9);
        printf("%c",219);
    }
    gotoxy(10,20);
   SetColorAndBackground(0,2);
        system("cls");
        //Inicio de juego
        gotoxy(40,1);
        printf("Bienvenido a Scrabble");
        gotoxy(0,2);
        printf("Ingrese el numero de jugadores(Max 9):");
        scanf("%d",&num_jugadores);
        fflush(stdin);
        printf("Los jugadores a participar seran:\n");
        for(i=0;i<=num_jugadores-1;i++)
        {
            printf("Jugador %d\n",i+1);
            fgets(nombres[i],50,stdin);
            fflush(stdin);
            nombres[i][strlen(nombres[i])-1]='\0';
        }
        for(k=0;k<=num_jugadores-1;k++)
        {
            printf("El jugador %d es %s\n",k+1,nombres[k]);
        }
        Sleep(500);
        juego(num_jugadores);
        break;
    case 2://Como jugar
        system("cls");
        gotoxy(40,1);
        printf("Como jugar?");
        gotoxy(0,2);
        printf("Este juego va de a turnos en los que los jugadores tienen que ingresar una palabra la cual contiene dos letras al azar.\n");
        printf("El puntaje obtenido se calcula en base a la tabla de puntaje del scrabble en castellano.\n");
        printf("Si la palabra ingresada no contiene las letras se le asigna cero puntos.\n");
        printf("Gana aquel jugador que obtenga mas puntaje luego de tres rondas.\n");
        printf("Si no sabe la palabra ingresa =\n");
        printf("Estas preparado?\n");
        printf("Comencemos!!\n");
        break;
    default:
        system("cls");
        SetColorAndBackground(15,1);
        printf("La opcion ingresada no es valida, por favor ingresela otra vez\n");
        break;

    }
    if(menu_opc!=0)
    {
        while(cont==0)
    {
        printf("Ingrese un 3 para volver al inicio:");
        scanf("%d",&cont);
        if(cont==3)
            break;
    }
    }

    }
    while(menu_opc!=0);

    return 0;
}
//Posicionamiento
void gotoxy(int x,int y)
{
     COORD coord={0,0};
     coord.X=x;
     coord.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}
void textcolor(int colortexto)
{

    ForgC=colortexto;
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    return;
}

//Letras
int juego(int num_jugadores)
{
    int i=0,k=0,j=0,h=0,g=0;//contadores
    int a,b;//Letras
    int letras_correcta1;//Letra correcta
    int letras_correcta2;//Letra correcta
    int rondas=0;//Controla las rondas
    char palabra[50];//Palabra ingresada
    int puntaje=0;//Puntaje de cada ronda
    int puntajes_parciales[num_jugadores];
    int jugadores;//Vector para puntaje parcial
    int puntajes_finales[num_jugadores];//Vector para puntaje total
    int puntaje_max=0;//Define al ganador
    int ganador=0;//Jugador ganador

    printf("Ahora comenzemos con el juego\n");
     Sleep(2000);
    srand(time(NULL));

    do
    {   //Empieza el juego
        system("cls");
        printf("Turno %d\n",rondas+1);
        i=0;
        jugadores=0;
        puntaje=0;
        for(i;i<=num_jugadores-1;i++)
    {
        puntaje=0;
        letras_correcta1=0;
        letras_correcta2=0;
        a=rand()%(122-97)+97;
        b=rand()%(122-97)+97;
        printf("Las letras para el jugador %d son %c y %c\n",i+1,toupper(a),toupper(b));
        printf("Ingrese la palabra:");
        fgets(palabra,50,stdin);
        fflush(stdin);
        palabra[strlen(palabra)-1]='\0';
        k=0;
        while(palabra[k]!='\0')
        {
                if(palabra[k]==61)
                    break;
                if(toupper(palabra[k])==toupper(a))
                    letras_correcta1=1;
                if(toupper(palabra[k])==toupper(b))
                    letras_correcta2=1;

        k++;
        }

    h=0;
    if(rondas==0)
            puntajes_finales[jugadores]=0;
    while(h<=num_jugadores)
    {
        if(palabra[k]==61)
        {
        printf("El jugador %d no sumo puntos esta ronda\n",i+1);
        puntaje=0;
        puntajes_finales[jugadores]=puntajes_finales[jugadores]+puntaje;
        puntajes_parciales[jugadores]=puntaje;
        printf("La palabra ingresada por el jugador %d tiene un valor de %d puntos\n",i+1,puntajes_parciales[jugadores]);
        printf("El puntaje total del jugador %d es de %d puntos\n",i+1,puntajes_finales[jugadores]);
        printf("----------------------------------------------------------------------\n");
            break;
        }
        else
        {
        if (letras_correcta1==1&&letras_correcta2==1)
        {
            printf("La palabra %s es correcta\n",strupr(palabra));
            j=0;
            while(palabra[j]!='\0')
        {
            if(palabra[j]=='A' || palabra[j]=='E' || palabra[j]=='O' || palabra[j]=='S' || palabra[j]=='I' ||
                palabra[j]=='U' || palabra[j]=='N' || palabra[j]=='L' || palabra[j]=='R' || palabra[j]=='T')
                puntaje=puntaje+1;
            if(palabra[j]=='C' || palabra[j]=='D' || palabra[j]=='G')
                puntaje=puntaje+2;
            if(palabra[j]=='M' || palabra[j]=='B' || palabra[j]=='P')
                puntaje=puntaje+3;
            if(palabra[j]=='F' || palabra[j]=='H' || palabra[j]=='V' || palabra[j]=='Y')
                puntaje=puntaje+4;
            if(palabra[j]=='J')
                puntaje=puntaje+6;
            if(palabra[j]=='K' || palabra[j]=='Ñ' || palabra[j]=='Q' || palabra[j]=='W' || palabra[j]=='X')
                puntaje=puntaje+8;
            if(palabra[j]=='Z')
            puntaje=puntaje+10;
            j++;
        }
        puntajes_finales[jugadores]=puntajes_finales[jugadores]+puntaje;
        puntajes_parciales[jugadores]=puntaje;
        printf("La palabra ingresada por el jugador %d tiene un valor de %d puntos\n",i+1,puntajes_parciales[jugadores]);
        printf("El puntaje total del jugador %d es de %d puntos\n",i+1,puntajes_finales[jugadores]);
        printf("----------------------------------------------------------------------\n");
            break;
        }

    else
    {
        if (letras_correcta1!=1||letras_correcta2!=1)
        {
            printf("La palabra %s no es correcta\n",strupr(palabra));
            puntaje=0;
        puntajes_finales[jugadores]=puntajes_finales[jugadores]+puntaje;
        puntajes_parciales[jugadores]=puntaje;
        printf("La palabra ingresada por el jugador %d tiene un valor de %d puntos\n",i+1,puntajes_parciales[jugadores]);
        printf("El puntaje total el jugador %d tiene un valor de %d puntos\n",i+1,puntajes_finales[jugadores]);
            break;

        }

    }
    }
    }
    jugadores++;
    }
    if(rondas<2)
        printf("Preparense para la siguiente ronda...");
    else
    {
            if(rondas==2)
        {
        printf("Lo hicieron muy bien!!");
        break;
        }
    }


    Sleep(3000);
    rondas++;
    }
    while(rondas<3);
    Sleep(3000);
    system("cls");
    gotoxy(45,1);
    printf("Tabla de resultados");
    gotoxy(25,3);
    printf("-----------------------");
    gotoxy(25,4);
    printf("|  Jugador  | Puntaje |");
    gotoxy(25,5);
    printf("----------------------");
    while(g<=num_jugadores-1)
    {


    gotoxy(25,5+g);
    printf("| Jugador %d |   %d    |",g+1,puntajes_finales[g]);
    gotoxy(25,6+g);
    printf("-----------------------");


     if(puntaje_max<puntajes_finales[g])
        {
            puntaje_max=puntajes_finales[g];
            ganador=g;

        }

    g++;
    }

        gotoxy(1,8+g);
        printf("%c%cFelicidades jugador %d, ganaste el juego con %d puntos%c%c\n",33,33,ganador+1,puntaje_max,33,33);





    return 0;
}

