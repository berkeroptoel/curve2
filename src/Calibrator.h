#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include "FindCurve.h"
#include <cstdint>

class Calibrator
{
public:
    Calibrator(void);
    void clear(void);
    bool calculate();
    double get_Coeeficents(int8_t Index);
    double get_Deviation(int8_t Index);
    void set_MeasuredPlato(int8_t Index,float Value);
    void set_MeasuredGravity(int8_t Index,float Value);
    void set_MeasuredTemperature(int8_t Index,float Value);
private:
    void begin();
    void Choose_Coefficients_best_fit(void);
    double Coefficients[6];
    double Deviation[6];
    double l_coefficients_5deg[6];
    float  deviation_3deg[10];
    double sum_2dg;
    double sum_3dg;
    double sum_4dg;
    double sum_5dg;
    void calculate_Coeeficents(FindCurve &Curve, int degree);
    int8_t count_steps;
    float MeasuredPlato[7];
    float MeasuredGravity[7];
    float MeasuredTemperature[7];
};

extern Calibrator calibrator;
#endif
