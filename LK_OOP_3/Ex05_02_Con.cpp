/**************************************************************************
*                      �  �  �  �      �  �  �                            *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : \�����_�++\Lesson_05_�������� _���\Ex05_02              *
* Project Type  : Win32 Console application                               *
* File Name     : Ex05_02_Con.cpp                                         *
* Language      : Visual C++           MS VS 2015                         *
* Programmer(s) : ������� �.�.  &   ��������� �.�.                        *
* Modified By   : ������� �.�.                                            *
* Created       : 28 / 04 / 2004                                          *
* Last Revision : 06 / 01 / 2016                                          *
* Comment(s)    : ������ �� ������� ����� �� ��������� 6 �����     *
 *                 � �����                                          *
*                                                                         *
***************************************************************************/

#pragma once                  
#include <windows.h>
#include <conio.h>
#include <iostream>    
using namespace std;           // ������������ ���� std
#include "Point05_02.h"

//������ ��� ����������� ���� ������� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   � � � � � � � � � �   � � � � � � � � � �  �  � � � � � � � � �   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

HDC hdc;// ������� �������� ����������
                // �������� ���������� �� ���� ��� ���������,
                // ���������� �������� ���������� �� ����� ����������
                // � ���� ����������� ����������� ���������

/*---------------------------------------------------------------------*/
/*               � � � � � � � � �    � � � � � � �                    */
/*---------------------------------------------------------------------*/
HWND GetConcolWindow(); //��������� �� ���������� ����

/***********************************************************************/
/*               � � � � � � � �    � � � � � � � � �                  */
/***********************************************************************/
void main()
{
    //���������� � ������������� ����������
    int x0 = 130;        //��������� ���������� �����
    int y0 = 250;
    int i, j = 0;

    //������� ���������� ����������� ����
    HWND hwnd = GetConcolWindow();

    //���� ���������� ����������
    if (hwnd != NULL)
    {
        //������� �������� ���������� ��� ����������� ����
        hdc = GetWindowDC(hwnd);

        //���� �������� ���������� - ����� ��������
        if (hdc != 0)
        {
            //===================================================================
            //        � � � � �    � � � � � � �         

            // ������� ��������� ������
            Point APoint(x0, y0);
            APoint.Show(); // �������� �����
            cin.get(); // �������� ������
            // ����� � ���������� ����
            cout << APoint.GetX() << endl;

            // 6 ����� �� ����������� � ���������
            APoint.MoveTo(230, 200); // �������� �����
            cin.get(); // �������� ������

            APoint.MoveTo(230, 210); // �������� �����
            cin.get(); // �������� ������

            APoint.MoveTo(230, 220); // �������� �����
            cin.get(); // �������� ������

            APoint.MoveTo(230, 230); // �������� �����
            cin.get(); // �������� ������

            APoint.MoveTo(230, 240); // �������� �����
            cin.get(); // �������� ������

            APoint.MoveTo(230, 250); // �������� �����
            cin.get(); // �������� ������

            APoint.MoveTo(200, 200); // �������� �����



                                   
            while (1) // ����������� ����
            {
                j++;
                for (i = 0; i < 100; i = i + 2) {
                    //����������� ����� �� 2 ������� ����
                    APoint.MoveTo(200, 200 + i); // �������� �����
                    Sleep(150); // �������� ��������

                }//for i

                if (j == 50) j = 0;

            } // while
            //===================================================================
        }//end if
    }//end if
}//end main()

/*---------------------------------------------------------------------*/
/*               � � � � � � � � � �   � � � � � � �                   */
/*---------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*  ������� ���������� ����  */
/*---------------------------*/
HWND GetConcolWindow()
{
    char str[128];
    // char title[128]="xxxxxxxxxxxxxxxxxx";
    LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxx";        //����� ������ Windows
    GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str)); // �������� ��������� ����
    SetConsoleTitle(title);                                                // ���������� ����� ��������� ����
    Sleep(100);                                                                        // ���� ����� ��������� ���� (100 ��);

    HWND hwnd = FindWindow(NULL, (LPWSTR)title);// ���������� ���������� ����
    SetConsoleTitle((LPWSTR)str);                                //���������� ������� ���������

    return hwnd;//������� ���������� ����
}//end GetConcolWindow()

/**********************  End Of Ex05_02_Con.CPP File ********************/
