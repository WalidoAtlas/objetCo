/************************************************************** 
 * Affiche sur le moniteur serie le nombre entier reçu.
 * Sketch du récepteur (branché à la pin 11, par défaut).
 * http://electroniqueamateur.blogspot.com/2014/01/modules-rf-433-mhz-virtualwire-et.html
 ***************************************************************/

#include <VirtualWire.h>

int Nombre;

char Message[VW_MAX_MESSAGE_LEN]; 

void setup() {
  Serial.begin(9600);     
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);   // Bits par seconde   

  vw_rx_start();       

}

void loop(){
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) 
  {
    int i;

    for (i = 0; i < buflen; i++)
    {               
      Message[i] = char(buf[i]);
    }

    Message[buflen] = '\0';

    // Conversion du tableau de chars en int:
    Nombre = atoi(Message);

    Serial.print("Message recu: ");
    Serial.println(Nombre);                
  }
}


