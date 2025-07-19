#include<pic.h>
void command(char x);
void data(char x);
void delay(char x);
void strdata(const char *x);
void main()
{
 char a=0,b,f=0,c[4],d[4],x[4],y[4],k[15],k1[15],e,flag1=0,flag2=0;
 int i,s=0,s1=0;
TRISA=0XFF;
TRISB=0X00;
TRISC=0X00;
TRISD=0X00;
ADCON0=0X01;
ADCON1=0X00;
PORTB=0X00;
	command(0X01);
	command(0X0E);
	command(0X06);
	command(0X80);
	command(0X38);
		strdata("SOLAR TRACKER");
		command(0XC0);
		delay(5);
		strdata("LDR1:");
		command(0XC8);
		strdata("LDR2:");
while(1)
{
	CHS2=0;
	CHS1=0;
	CHS0=1;
for(i=0;i<10;i++)
{
		ADGO=1;
		while(ADGO==1);
		k[i]=ADRESH;
        s=s+k[i];
}
		f=s/10;
		b=f;
		x[0]=f%10;
		f=f/10;
		x[1]=f%10;
		x[2]=f/10;
		y[0]=x[2]+0X30;
		y[1]=x[1]+0X30;
		y[2]=x[0]+0X30;
		y[3]='\0';
	command(0XC5);
	strdata(y);
	s=0;

	CHS2=0;
	CHS1=0;
	CHS0=0;
for(i=0;i<10;i++)
{
		ADGO=1;
		while(ADGO==1);
		k1[i]=ADRESH;
        s1=s1+k1[i];
}
		a=s1/10;
		e=a;
		c[0]=a%10;
		a=a/10;
		c[1]=a%10;
		c[2]=a/10;
		d[0]=c[2]+0X30;
		d[1]=c[1]+0X30;
		d[2]=c[0]+0X30;
		d[3]='\0';
	command(0XCD);
	strdata(d);
s1=0;
if(b>e)
	{
		if(flag1!=1)
			{
			RB4=1;
			RB5=1;
			delay(4);
			RB4=0;
			RB5=0;
			flag1=1;
			flag2=0;
			}

	}
else if(e>b)
	{
		if(flag2!=1)
			{
			RB4=1;
			RB5=0;
			delay(4);
			RB4=0;
			RB5=0;
			flag2=1;
			flag1=0;
			}

	}
}
}
void data(char x)
{
PORTD=x;
RC0=1;
RC1=0;
RC2=1;
delay(1);
RC2=0;
}
void command(char x)
{
PORTD=x;
RC0=0;
RC1=0;
RC2=1;
delay(1);
RC2=0;
}
void delay(char x)
{
int i;
for(i=0;i<=x*500;i++);
}
void strdata(const char *x)
{
while(*x)
{
data(*x);
x++;
}
}