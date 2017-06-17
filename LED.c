/* Cuando el GPIO02 esté en alto entonces apagar el led conectado al GPIO05 */

#include <stdio.h>
#include <pigpio.h>

#define IN  02 /* GPIO02 como entrada */
#define OUT 05 /* GPIO05 como salida */
#define OUT3 03
int read_1;

int main (int argc, char *argv[])
{
        if(gpioInitialise()<0) return -1; /*Inicializando pigpio*/

gpioSetMode(IN, PI_INPUT);
gpioSetMode(OUT, PI_OUTPUT);
gpioSetMode(OUT3, PI_OUTPUT);
for(;;)
{
        read_1 = gpioRead(IN);
        //gpioWrite(OUT,1);

        if(read_1 == 0)
        {
            gpioWrite(OUT,0);
	    gpioWrite(OUT3, 1);
        }
	else
	{
	   gpioWrite(OUT,1);
	   gpioWrite(OUT3,0);
	}
}
gpioTerminate();
}
