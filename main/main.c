#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdint.h>

#include "uart.h"
#include "dht11.h"
#include "gpio.h"

int main(void){
	uart_init(); // 103 pour baud 9600 a frequence 16MHz
	uint8_t humidite, temperature;

	while(1){ // Boucle infinie
		uint8_t status = dht_lecture(&humidite, &temperature); // Lecture du capteur
		if(status == 0){
			uart_envoi_mot("Temperature= ");
			uart_envoi_nombre(temperature);
			uart_envoi_mot("C, Humidite= ");
			uart_envoi_nombre(humidite);
		}else{
			uart_envoi_mot("DHT11 error: ");
			uart_envoi_nombre(status);
		}
		uart_envoi_mot("\r\n");
		_delay_ms(2000); // Attendre 2 secondes pour la prochaine lecture
	}
}

