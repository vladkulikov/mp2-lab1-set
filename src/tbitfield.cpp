// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

inline int Counter()
{
	int count = 0, size = sizeof(TELEM) * 8;
	while (size >>= 1)
	{
		count++;
	}
	return count;
}

TBitField::TBitField(int len)
{
	if (len < 0)
	{
		throw 1;
	}
	BitLen = len;
	MemLen = (BitLen + sizeof(TELEM) * 8 - 1) >> Counter();
	pMem = new TELEM[MemLen];
	if (pMem == nullptr)
	{
		throw 2;
    }
	for (int i = 0; i < MemLen; i++)
	{
		pMem[i] = 0;
	}
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	if (bf.pMem != NULL) {
		for (int i = 0; i < MemLen; i++) 
		{
			pMem[i] = bf.pMem[i];
		}
	}
}

TBitField::~TBitField()
{
	delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return 0;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 0;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n >= BitLen || n < 0)
	{
		throw 3;
	}
	pMem[GetMemIndex(n)] &= (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	return *this;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	return *this;
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField temp(BitLen);
	for (int i = 0; i < MemLen; i++) 
	{
		temp.pMem[i] = ~pMem[i];
	}
	return temp;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	return ostr;
}
