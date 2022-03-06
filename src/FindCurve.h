/**
 * @file FindCurve.h
 * @author Tjorben Eberle (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef FindCurve_h
#define FindCurve_h

/*! Importation of librairies*/
#include "curveFitting.h"
#include <cstdint>

class FindCurve
{
private:
double coeffs[7];
double Coordx[7];
double Coordy[7];


public:
FindCurve(){}
void set_Coord(int8_t Point,double Coordinates_x,double Coordinates_y);
float get_Coord(int8_t Point,bool XoY);
double get_Curve_Quality(int8_t i);
bool cal_Coeff(int8_t poly_order);
void set_coeffs(float a, float b, float c,float d);
double get_coeffs(int8_t Coeff_count);
void Load_Example_CalibrationPoints();
};
#endif
