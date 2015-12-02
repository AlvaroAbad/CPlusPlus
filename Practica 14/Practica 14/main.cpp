// TOMAS: Muy bien la práctica.
// TOMAS: Piensa en que caso hubiera sido interesante meter el enumerado "TType" dentro de 
//        la clase "CImagen".

#pragma warning(disable:4514)
#pragma warning(disable:4710)
#include "Jpg.h"
#include "Png.h"
#include <stdio.h>
void removeAlphas(CImagen ** images, const unsigned int size) {
	for (size_t i = 0; i < size; i++)
	{
		if (images[i]->getType() == Tpng) {
			static_cast<CPng *>(images[i])->removeAlpha();
		}
	}
}

int main(int, char *) {
	CImagen * images[6];
	images[0] = new CJpg();
	images[1] = new CPng();
	images[2] = new CJpg();
	images[3] = new CJpg();
	images[4] = new CPng();
	images[5] = new CPng();

	for (unsigned int i = 0; i < 6; i++)
	{
		images[i]->SetImageFile();
		if (images[i]->getType() == Tpng) {
			printf("%u-%X\n", i, images[i]->getColorByte());
		}
	}
	removeAlphas(images, sizeof(images) / sizeof(CImagen *));
	for (unsigned int i = 0; i < 6; i++)
	{
		if (images[i]->getType() == Tpng) {
			printf("%u-%X\n", i, images[i]->getColorByte());
		}
	}
	getchar();
}