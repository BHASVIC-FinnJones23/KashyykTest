#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

char bookings[6][9][50];

void updateFiles(){
    FILE *fpointer;
    int i=0;
    for(i=0;i<6;i++){
        char path[15]="..//room0.txt";
        int roomNumber = i + 1;
        path[8]=roomNumber+'0';
        fpointer = fopen(path,"w");//open the rooms file
        //this isn't great
        fprintf(fpointer,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",bookings[i][0],bookings[i][1],bookings[i][2],bookings[i][3],bookings[i][4],bookings[i][5],bookings[i][6],bookings[i][7],bookings[i][8]);
        fclose(fpointer);
    }

}

void updateLocalBookingList(){
    FILE *fpointer;
    char lineHolder[500];

    int i=0;
    for(i=1;i<=6;i++){
        char path[15]="..//room0.txt";
        path[8]=i+'0';
        //printf("roomspath is :%s\n",path);


        if((fpointer = fopen(path,"r"))==NULL){
            //this should never happen unless some idiot deleted the booking files
            printf("Error Opening the file!\n");
        }

        int k=0;
        while(fgets(lineHolder,51,fpointer)!=NULL){
            int j=0;
            while(j<50&&(lineHolder[j]!='\0'&&lineHolder[j]!='\n')){//this line is not always true, is bull####
                //"i" is the real room number
                //so i-1 would be the reference in booking array
                //I have to loop through it so many times to prevtn using RUBBISH string functions
                //strcpy() <--Useless Junk
                bookings[i-1][k][j]=lineHolder[j];

                j++;
            }
            k++;
        }
        fclose(fpointer);
    }


}
