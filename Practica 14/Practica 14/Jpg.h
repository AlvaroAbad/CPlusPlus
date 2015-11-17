#include "Imagen.h"

class CJpg : public CImagen
{
public:
	CJpg();
	virtual int SetImageFile();
	
private:
	int UncompressImage();
};