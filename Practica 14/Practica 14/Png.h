#include "Imagen.h"

class CPng : public CImagen
{
public:
	CPng();
	virtual int SetImageFile();
	void removeAlpha();
private:
	int UncompressImage();
};