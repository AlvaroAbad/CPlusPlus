// Practica.cpp
//
#pragma warning(disable: 4514)//warning in corecrt_wstdio.h
#pragma warning(disable: 4710)//function scanf and printf not inline

#include <stdio.h>	
#define AMMO 0x00FF0000
#define UNLIMITEDAMMO 0x00000002

bool checkUnlimitedAmmo(unsigned int charInfo) {
	if (charInfo & UNLIMITEDAMMO) {//check of unlimited ammo
		return true;
	}
	else {
		return false;
	}
}

unsigned int setUnlimitedAmmo(unsigned int charInfo) {
	return charInfo |= UNLIMITEDAMMO; //activate unlimited ammo
}

unsigned int remainingAmmo(unsigned int charInfo) {
	if (checkUnlimitedAmmo(charInfo)) { //check if unlimited ammo is active;
		printf_s("-Unlimited Ammo-");
		return 255;
	}
	charInfo &= AMMO; //remove all character data excep ammo recunt;
	charInfo >>= 16; //move ammo recount to the 8 first bits
	return charInfo; //return resulting integer

}

unsigned int incrementAmmo(unsigned int charInfo, unsigned int extraAmmo) {
	unsigned int currentAmmo;
	currentAmmo = charInfo & AMMO;//remove all character data excep ammo recunt;
	if (currentAmmo==AMMO) { //check if full ammo;
		printf_s("-Full Ammo-");
		return charInfo;
	}
	extraAmmo <<= 16;//put incremental value to the 8 bits postition corresponding to the ammo recount
	currentAmmo += extraAmmo; //add ammo
	if (currentAmmo > 16711680) { //check if ammo surpases ammo limit
		charInfo |= AMMO;// update char ammo to full ammo
	}
	else {
		charInfo += extraAmmo; // add incremental ammo to character
	}
	return charInfo;//return resulting char info

}


int main(int, char*) {
	// Ejemplo de información empaquetada.
	// en un entero de 32 bits tenemos:
	// 8 bits mayor peso la vida 0xFF000000
	// siguientes 8 bits: número de balas. 0x00FF0000
	// Siguientes 4 bits: número de compañeros. 0x0000F000
	// bit 0: invulnerable 0x00000001
	// bit 1: balas infinitas. 0x00000002
	// bit 2: escudo. 0x00000004
	// bit 3: berseker mode. 0x00000008

	// Hacer la siguiente práctica.
	// Para almacenar el estado de un personaje se utiliza la variable
	// que está empaquetada según el formato de arriba.
	// 1.- Hacer una función que pasado un valor retorne el número de balas -OK
	// 2.- Hacer una función que añada un número de balas a las ya existentes. - OK
	// 1.- Hacer una función que pasado un valor retorne si se tienen balas infinitas - OK
	// 2.- Hacer una función ponga modo de balas infinitas. -OK

	// TEST AMMO RECAUNT
	printf_s("AMMO RECAUNT\n");
	printf_s("char(0x00FF0000): %u\n", remainingAmmo(16711680));
	printf_s("char(0x00FF0002): %u\n", remainingAmmo(16711682));
	printf_s("char(0x000F0000): %u\n", remainingAmmo(983040));
	printf_s("char(0xFFA5A000): %u\n", remainingAmmo(4289044480));
	// TEST AMMO INCREMENT
	printf_s("AMMO INCREMENT\n");
	printf_s("char(0x00FF0000): %X\n", incrementAmmo(16711680, 10));
	printf_s("char(0x00FF0002): %X\n", incrementAmmo(16711682, 10));
	printf_s("char(0x000F0000): %X\n", incrementAmmo(983040, 10));
	printf_s("char(0xFFA5A000): %X\n", incrementAmmo(4289044480, 10));
	// TEST CHECK UNLIMITED AMMO
	printf_s("CHECK UNLIMITED AMMO\n");
	printf_s("char(0x00FF0000): %s\n", checkUnlimitedAmmo(16711680) ? "True" : "False");
	printf_s("char(0x00FF0002): %s\n", checkUnlimitedAmmo(16711682) ? "True" : "False");
	printf_s("char(0x000F0000): %s\n", checkUnlimitedAmmo(983040) ? "True" : "False");
	printf_s("char(0xFFA5A002): %s\n", checkUnlimitedAmmo(4289044482) ? "True" : "False");
	// TEST SET UNLIMITED AMMO
	printf_s("SET UNLIMITED AMMO\n");
	printf_s("char(0x00FF0000): %X\n", setUnlimitedAmmo(16711680));
	printf_s("char(0x00FF0002): %X\n", setUnlimitedAmmo(16711682));
	printf_s("char(0x000F0000): %X\n", setUnlimitedAmmo(983040));
	printf_s("char(0xFFA5A000): %X\n", setUnlimitedAmmo(4289044480));
	printf_s("------------------------------------------------------\n\n");
	unsigned int opt, opt2;
	do {
		printf_s("¿Que funcion quiere volver a ejecutar?\n\n");
		printf_s("1. Calcular municion restante\n");
		printf_s("2. añadir municion al personaje\n");
		printf_s("3. comprobar si tiene municion ilimitada\n");
		printf_s("4. activar municion ilimitada\n");
		printf_s("0. terminar\n");

		scanf_s("%u", &opt);
		switch (opt) {
		case 1:
			printf_s("indique el personaje\n");
			scanf_s("%X", &opt);
			printf_s("char: %u\n", remainingAmmo(opt));
			break;
		case 2:
			printf_s("indique el personaje\n");
			scanf_s("%X", &opt);
			printf_s("indique el numero de balas\n");
			scanf_s("%u", &opt2);
			printf_s("char: %X\n", incrementAmmo(opt, opt2));
			break;
		case 3:
			printf_s("indique el personaje\n");
			scanf_s("%X", &opt);
			printf_s("char: %s\n", checkUnlimitedAmmo(opt) ? "Si" : "No");
			break;
		case 4:
			printf_s("indique el personaje\n");
			scanf_s("%X", &opt);
			printf_s("char: %X\n", setUnlimitedAmmo(opt));
			break;
		}
	} while (opt);

}
