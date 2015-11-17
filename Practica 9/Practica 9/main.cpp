// TOMAS: Muy bien la práctica aunque yo no hubiera metido en la clase las funciones "countCoincidence" y "addNumbers"
//        ya que intuye normalmente no se ha usar en cualquier fichero que se habra y generan una dependencia innecesaria.
//        Tampoco me hubiera guardado el puntero al nombre del fichero pues este no tiene por qué ser válido entre
//        que se crea el objeto TFile y el open (el usuario lo ha podido liberar) y aunque no lo haga antes es peligroso
//        si lo hace después si más tarde un programador que va a tocar la clase cuenta con que es válido durante la vida
//        del objeto.
//        Te podrías copiar la cadena pero esto no es eficiente. Yo creo que lo mejor es que el nombre
//        del fichero se le pasase al abrirlo.
// ALVARO: Tomo nota y actualizo la practica
//			- elimino el atributo fileName de la clase y lo establezco como parametro al hacer openFile.
//		    - Creo un cpp y h FileUtilities donde defino countCoincidence y addNumbers.
#pragma warning(disable: 4710)
#include "FileFunctions.h"
#include "FileUtilities.h"

int main(int, char *) {
	TFile * file = new TFile();
	file->openFile("prueba.txt","r");
	printf("%u\n", countCoincidence(file,","));
	printf("%u\n", addNumbers(file));
	file->closeFile();
	getchar();
}

