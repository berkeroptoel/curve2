#include "FindCurve.h"

/**
 * @brief 
 * 
 * @param poly_order 
 * @return true 
 * @return false 
 */
bool FindCurve::cal_Coeff(int8_t poly_order)
{
if (!fitCurve(poly_order, sizeof(Coordy)/sizeof(double), Coordx, Coordy,poly_order+1, coeffs)){
    return true;
}
else
{
    return false;
}

}

/**
 * @brief 
 * 
 * @param Point 0-6 The position where the coordinates are to be saved.
 * @param Coordinates_x The X coordinate to be stored in the point 
 * @param Coordinates_y TheY coordinate to be stored in the point 
 */
void FindCurve::set_Coord(int8_t Point,double Coordinates_x,double Coordinates_y)
{
  Coordx[Point]=Coordinates_x;
  Coordy[Point]=Coordinates_y;
}

float FindCurve::get_Coord(int8_t Point,bool XoY)
{ 
  if(XoY)
  {
    return Coordy[Point];
  }
  else
  {
    return Coordx[Point];
  }
}

/**
 * @brief This function indicates the average deviation of the individual calibration points from the calculated curve.
This allows the quality of the curve to be calculated.
 * 
 * @return double 
 */
double FindCurve::get_Curve_Quality(int8_t i)
{
  double x=Coordx[i];
  double y=Coordy[i]; 
  double result=y-(x*x*x*x*x*x*coeffs[0]+x*x*x*x*x*coeffs[1]+x*x*x*x*coeffs[2]+x*x*x*coeffs[3]+x*x*coeffs[4]+x*coeffs[5]+coeffs[6]);

  return result;
}

double FindCurve::get_coeffs(int8_t Coeff_count)
{
  return coeffs[Coeff_count];
}


void FindCurve::Load_Example_CalibrationPoints(){
this->set_Coord(0,62.63	,18.7);	
this->set_Coord(1,61.25	,18);
this->set_Coord(2,60.6	,17.3);
this->set_Coord(3,59.95	,16.9);
this->set_Coord(4,58.85,	16.4);
this->set_Coord(5,52,	12);
this->set_Coord(6,48.4,	9.8);
} 

