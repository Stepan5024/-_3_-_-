/********************************************************************
*                      ?  ?  ?  ?  ?     ?  +  +                   *
*------------------------------------------------------------------*
* Project Type  : Win32 Console Application                        *
* Project Name  :C:\Users\bokar\source\repos\??????_??_???
* File Name     : Point05_02.CPP                                   *
* Programmer(s) : ??????? ?.?.  &  ????????? ?.?.  &  ??????? ?.?. *
* Modifyed By   : ??????? ?.?.                                     *
* Created       : 26/04/04                                         *
* Last Revision : 27/02/22                                         *
* Comment(s)    : ?????????? ???? ???????. ????????????            *
*                                                                  *
********************************************************************/
#include <Windows.h> // ??? ?????? ? ????????
#include "Point05_02.h"

//HWND   hwnd;     //  ??????? ?????????? (?????????) ????
extern HDC    hdc;      // ???????  ???????? ?????????? ??????????? extern - ??????? ?????????? ? ?????? ?????

/*------------------------------------------------------------------*/
/*                 ? ? ? ? ? ? ? ? ? ?    ? ? ? ? ? ? ?             */
/*------------------------------------------------------------------*/

/*----------------------------------------*/
/*        ?????? ?????? Location          */
/*----------------------------------------*/
Location::Location(int InitX, int InitY) // ??????????? Location()
{
	X = InitX;
	Y = InitY;
};// ??????????? Location()

Location::~Location(void)  // ?????????? ~Location() 
{
	//????????? ?????? ????
};// ?????????? ~Location()

int Location::GetX(void) { return X; }; // ???????? ???????? ?
int Location::GetY(void) { return Y; }; // ???????? ???????? ?


/*----------------------------------------*/
/*        ?????? ?????? Point             */
/*----------------------------------------*/
Point::Point(int InitX, int InitY) : Location(InitX, InitY) // ??????????? Point()
{
	Visible = false; // ?? ????, ??????? ?? ???? ?????? Point
}// ??????????? Point()

Point::~Point(void) // ?????????? ~Point()   
{
	//????????? ?????? ????
}// ?????????? ~Point()


void Point::Show(void) 
{
	// ???????? 4 ????? ?? ??????
	Visible = true; // ????? ?????
	SetPixel(hdc, X    , Y, RGB(255, 0, 0));   // ?????? ????????????? ?????? ??????? ?? ??????? ??????? ????? ????????
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));   // ??????? ???? - ????? ????????
	SetPixel(hdc, X    , Y + 1, RGB(255, 0, 0));   // ??????? ???? - ????? ????????
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));   // ??????? ???? - ????? ????????
	//Sleep(3000); //??? ???????
} // Show()


void Point::Hide(void) // ?????? ????? ?? ??????
{
	Visible = false;
	SetPixel(hdc, X, Y, RGB(0, 0, 255)); //?????? ?????? ??????
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 255));   // ????? ???? - ????? ????????
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 255));   // ????? ???? - ????? ????????
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));   // ????? ???? - ????? ????????
} // Hide()

//--------------------------------------------------------------
bool Point::IsVisible(void) { return Visible; };

//--------------------------------------------------------------
void Point::MoveTo(int NewX, int NewY) // ??????????? ????? ?? ???????????
{
	Hide();  //??????? ????? ????????? ?? ??????? ???????????
	X = NewX; //???????? ?????????? ?????
	Y = NewY; //???????? ?????????? ?????
	Show();  //???????? ????? ?? ????? ?????
}; // MoveTo()