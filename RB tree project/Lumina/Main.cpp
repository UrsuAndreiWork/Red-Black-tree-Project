// Lumina.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"
#include "Engine.h"
using namespace std;

int main()
{
   Engine motor;
   motor.DrawWindow(1400, 900);
   motor.LoadData();
   motor.Play();
}
