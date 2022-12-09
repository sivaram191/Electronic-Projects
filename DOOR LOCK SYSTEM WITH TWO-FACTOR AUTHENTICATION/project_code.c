#include <reg51.h>
#include <string.h>
#include <stdio.h>
#define LCDPORT P1
sbit keyrow1 = P2 ^ 0;
sbit keyrow2 = P2 ^ 1;
sbit keyrow3 = P2 ^ 2;
sbit keyrow4 = P2 ^ 3;
sbit keycolumn1 = P2 ^ 4;
sbit keycolumn2 = P2 ^ 5;
sbit keycolumn3 = P2 ^ 6;
sbit motorpin1 = P3 ^ 2;
sbit motorpin2 = P3 ^ 3;
sbit rs = P3 ^ 5;
sbit rw = P3 ^ 6;
sbit en = P3 ^ 7;
char i,rx_data[50];
char rfid[13],ch=0;
unsigned char result[1];
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void lcddisplay(unsigned char *q);
char keypad();
void check();
void delay(unsigned int);
unsigned char pin_siva[] = {"12345"};
unsigned char pin_sai[] = {"09876"};
unsigned char pin_charan[] = {"54321"};
unsigned char pin_abhi[] = {"67890"};
unsigned char Epin[5];
void main()
{
	  
    lcdcmd(0x0F);
    lcdcmd(0x38);
    lcdcmd(0x01);
    while (1)
    {
        unsigned int i = 0;
        lcdcmd(0x80);
        lcddisplay("PLS ENTER PIN");
        delay(1000);
        lcdcmd(0xc0);
        while (pin_siva[i] != '\0')
        {
            Epin[i] = keypad();
            delay(1000);
            i++;
        }
        check();
    }
}
void delay(unsigned int j)
{
    int a, b;
    for (a = 0; a < j; a++)
    {
        for (b = 0; b < 10; b++);           
    }
}
void uart_init()
{
  TMOD=0x20;
  SCON=0x50;
  TH1=0xfd;
  TR1=1;
}
void lcdcmd(unsigned char A)
{
    P1 = A;
    rs = 0;
    rw = 0;
    en = 1;
    delay(1000);
    en = 0;
}
void lcddat(unsigned char i)
{
    P1 = i;
    rs = 1;
    rw = 0;
    en = 1;
    delay(1000);
    en = 0;
}
void cmden(void)
{
    rs=0;
    en=1;
    delay(5);
    en=0;
}
void lcdcmd2(unsigned char ch)
{
    LCDPORT=ch & 0xf0;
    cmden();
    LCDPORT=(ch<<4) & 0xf0;
    cmden();
}
void lcddisplay(unsigned char *q)
{
    int k;
    for (k = 0; q[k] != '\0'; k++)
    {
        lcddat(q[k]);
    }
    delay(10000);
}
void daten()
{
    rs=1;
    rw=0;
    en=1;
    delay(5);
    en=0;
}
void lcddata(unsigned char ch)
{
    LCDPORT=ch & 0xf0;
    daten();
    LCDPORT=(ch<<4) & 0xf0;
    daten();
}
char rxdata()
{
  while(!RI);
    ch=SBUF;    
    RI=0;
    return ch;
}
char keypad()
{
    int x = 0;
    while (x == 0)
    {
        keyrow1 = 0;
        keyrow2 = 1;
        keyrow3 = 1;
        keyrow4 = 1;
        if (keycolumn1 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '1';
        }
        if (keycolumn2 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '2';
        }
        if (keycolumn3 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '3';
        }
        keyrow1 = 1;
        keyrow2 = 0;
        keyrow3 = 1;
        keyrow4 = 1;
        if (keycolumn1 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '4';
        }
        if (keycolumn2 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '5';
        }
        if (keycolumn3 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '6';
        }
        keyrow1 = 1;
        keyrow2 = 1;
        keyrow3 = 0;
        keyrow4 = 1;
        if (keycolumn1 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '7';
        }
        if (keycolumn2 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '8';
        }
        if (keycolumn3 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '9';
        }
        keyrow1 = 1;
        keyrow2 = 1;
        keyrow3 = 1;
        keyrow4 = 0;
        if (keycolumn1 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '*';
        }
        if (keycolumn2 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '0';
        }
        if (keycolumn3 == 0)
        {
            lcddat('*');
            delay(1000);
            x = 1;
            return '#';
        }
    }
}
void check()
{
    if (pin_siva[0] == Epin[0] && pin_siva[1] == Epin[1] && pin_siva[2] == Epin[2] && pin_siva[3] == Epin[3] && pin_siva[4] == Epin[4])
    {
        delay(1000);
        lcdcmd(0x01);
        lcdcmd(0x81); 
        lcddisplay("PIN CORRECT");
        delay(2000);
			  lcdcmd(0x01);
			  lcddisplay("WELCOME siva");
			  delay(2000);
			  lcdcmd(0x01);
			  lcddisplay("scan your card");
			  delay(1000);
			  lcdcmd(0x01);
			  uart_init();
			  while(1)
      {
          i=0;
          for(i=0;i<12;i++)
          rfid[i]=rxdata();
          rfid[i]='\0';
          lcdcmd(1);
			    lcddisplay("Rfid No. is:");
          lcdcmd2(0xc0);
          for(i=0;i<12;i++)
          lcddat(rfid[i]);
          delay(1000);
				  if(strncmp(rfid,"09000BDEB569",12)==0)
					{
						motorpin1 = 1;
            motorpin2 = 0;
						delay(5000);
            lcdcmd(0xc1);
						lcdcmd(0x01);
            lcddisplay("DOOR OPENED");
            lcdcmd(0x01);
						delay(5000);
						motorpin1 = 0;
            motorpin2 = 1;
						delay(10000);
						motorpin1 = 1;
            motorpin2 = 1;
						delay(5000);
						lcddisplay("DOOR CLOSED");
						delay(1000);
						lcdcmd(0x01);
						break;
					}
					else
					{
						lcdcmd(0x01);
            lcddisplay("Try Another Card");
						break;
					}		
		  }
    }
		else if (pin_sai[0] == Epin[0] && pin_sai[1] == Epin[1] && pin_sai[2] == Epin[2] && pin_sai[3] == Epin[3] && pin_sai[4] == Epin[4])
    {
        delay(1000);
        lcdcmd(0x01);
        lcdcmd(0x81);
        lcddisplay("PIN CORRECT");
        delay(2000);
			  lcdcmd(0x01);
			  lcddisplay("WELCOME sai");
			  delay(2000);
			  lcdcmd(0x01);
			  lcddisplay("scan your card");
			  delay(1000);
			  lcdcmd(0x01);
			  uart_init();
			  while(1)
      {
          i=0;
          for(i=0;i<12;i++)
          rfid[i]=rxdata();
          rfid[i]='\0';
          lcdcmd(1);
			    lcddisplay("Rfid No. is:");
          lcdcmd2(0xc0);
          for(i=0;i<12;i++)
          lcddat(rfid[i]);
          delay(1000);
				  if(strncmp(rfid,"4D0098E62516",12)==0)
					{
						motorpin1 = 1;
            motorpin2 = 0;
						delay(5000);
            lcdcmd(0xc1);
						lcdcmd(0x01);
            lcddisplay("DOOR OPENED");
            lcdcmd(0x01);
						delay(5000);
						motorpin1 = 0;
            motorpin2 = 1;
						delay(10000);
						motorpin1 = 1;
            motorpin2 = 1;
						delay(5000);
						lcddisplay("DOOR CLOSED");
						delay(1000);
						lcdcmd(0x01);
						break;
					}
					else
					{
						lcdcmd(0x01);
            lcddisplay("Try Another Card");
						break;
					}		
		  }
    }
		else if (pin_charan[0] == Epin[0] && pin_charan[1] == Epin[1] && pin_charan[2] == Epin[2] && pin_charan[3] == Epin[3] && pin_charan[4] == Epin[4])
    {
        delay(1000);
        lcdcmd(0x01);
        lcdcmd(0x81);
        lcddisplay("PIN CORRECT");
        delay(2000);
			  lcdcmd(0x01);
			  lcddisplay("WELCOME charan");
			  delay(2000);
			  lcdcmd(0x01);
			  lcddisplay("scan your card");
			  delay(1000);
			  lcdcmd(0x01);
			  uart_init();
			  while(1)
      {
          i=0;
          for(i=0;i<12;i++)
          rfid[i]=rxdata();
          rfid[i]='\0';
          lcdcmd(1);
			    lcddisplay("Rfid No. is:");
          lcdcmd2(0xc0);
          for(i=0;i<12;i++)
          lcddat(rfid[i]);
          delay(1000);
				  if(strncmp(rfid,"4D0098E73A08",12)==0)
					{
						motorpin1 = 1;
            motorpin2 = 0;
						delay(5000);
            lcdcmd(0xc1);
						lcdcmd(0x01);
            lcddisplay("DOOR OPENED");
            lcdcmd(0x01);
						delay(5000);
						motorpin1 = 0;
            motorpin2 = 1;
						delay(10000);
						motorpin1 = 1;
            motorpin2 = 1;
						delay(5000);
						lcddisplay("DOOR CLOSED");
						delay(1000);
						lcdcmd(0x01);
						break;
					}
					else
					{
						lcdcmd(0x01);
            lcddisplay("Try Another Card");
						break;
					}		
		  }
    }
		else if (pin_abhi[0] == Epin[0] && pin_abhi[1] == Epin[1] && pin_abhi[2] == Epin[2] && pin_abhi[3] == Epin[3] && pin_abhi[4] == Epin[4])
    {
        delay(1000);
        lcdcmd(0x01); 
        lcdcmd(0x81); 
        lcddisplay("PIN CORRECT");
        delay(2000);
			  lcdcmd(0x01);
			  lcddisplay("WELCOME Abhi");
			  delay(2000);
			  lcdcmd(0x01);
			  lcddisplay("scan your card");
			  delay(1000);
			  lcdcmd(0x01);
			  uart_init();
			  while(1)
      {
          i=0;
          for(i=0;i<12;i++)
          rfid[i]=rxdata();
          rfid[i]='\0';
          lcdcmd(1);
			    lcddisplay("Rfid No. is:");
          lcdcmd2(0xc0);
          for(i=0;i<12;i++)
          lcddat(rfid[i]);
          delay(1000);
				  if(strncmp(rfid,"4D009909835E",12)==0)
					{
						motorpin1 = 1;
            motorpin2 = 0;
						delay(5000);
            lcdcmd(0xc1);
						lcdcmd(0x01);
            lcddisplay("DOOR OPENED");
            lcdcmd(0x01);
						delay(5000);
						motorpin1 = 0;
            motorpin2 = 1;
						delay(10000);
						motorpin1 = 1;
            motorpin2 = 1;
						delay(5000);
						lcddisplay("DOOR CLOSED");
						delay(1000);
						lcdcmd(0x01);
						break;
					}
					else
					{
						lcdcmd(0x01);
            lcddisplay("Try Another Card");
						break;
					}		
		  }
    }
    else
    {
        lcdcmd(0x01);
        lcdcmd(0x80);
        lcddisplay("WRONG PIN");
        delay(1000);
        lcdcmd(0x01);
    }
}
