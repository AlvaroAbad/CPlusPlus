#pragma once
#pragma warning(disable: 4996)
#pragma warning(disable:4514)
#pragma warning(disable:4710)
enum TType{ Tjpg = 1, Tpng = 2 };
class CImagen
{
public:
	virtual ~CImagen();

	TType getType();
	virtual int	SetImageFile();
	unsigned int GetNumPixels() const;
	unsigned int GetUncompressedSize() const;
	const unsigned char * GetBuffer() const;
	int	Draw() const;
	int	InvertImage();
	unsigned int getColorByte();

protected:
	TType type;
	unsigned int m_uResX;
	unsigned int m_uResY;
	unsigned int m_uColorBytes;
	unsigned char *	m_pBuffer;
	unsigned int m_uSize;
};