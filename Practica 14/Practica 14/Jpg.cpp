#include <stdio.h>
#include <string>
#include "Jpg.h"

CJpg::CJpg()
{
	this->type = Tjpg;
}

// **************************************************************
//
// **************************************************************
int CJpg::SetImageFile()
{
	printf("Lectura del fichero comprimido JPG\n");
	UncompressImage();
	return 0;
}

// **************************************************************
//
// **************************************************************
int CJpg::UncompressImage()
{
	printf("Descompresión de Imagen JPG\n");
	m_uResX				= 800;
	m_uResY				= 600;
	m_uColorBytes	= 4;
	m_uSize				= m_uResX * m_uResY * m_uColorBytes;
	m_pBuffer			= new unsigned char[m_uSize];
	strcpy(reinterpret_cast<char *>(m_pBuffer), "Bytes del buffer descomprimido desde JPG");
	return 0;
}