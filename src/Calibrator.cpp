#define __PGMSPACE_H_ true

#include "Calibrator.h"
#include "FindCurve.h"
#include "esp_log.h"

/********************************************************************
* LOCAL VARIABLES
*********************************************************************/
FindCurve Fit_Curve_2dg;
FindCurve Fit_Curve_3dg;
FindCurve Fit_Curve_4dg;
FindCurve Fit_Curve_5dg;
Calibrator calibrator;

static const char* TAG = "Calibrator";

/********************************************************************
* PUBLIC FUNCTIONS
*********************************************************************/
/*
* Default constructor
*/
Calibrator::Calibrator(void) {
	count_steps = 7;
	sum_5dg = 0;
	sum_4dg = 0;
	sum_3dg = 0;
	sum_2dg = 0;

}

/**
 * @brief 
 * 
 * @param l_count_steps Number of calibration steps that were captured
 */
void Calibrator::begin() {
    /*
        Here the 7 measured values from 0- 6 are stored
        Point= 0-6
        X= Angle (Gravity)
        Y= Plato
     */

    //Ends the calibre process, calculates which of the types was calculated more accurately (either a second or third degree polynomial).
    ESP_LOGI(TAG,"Transfer the Measurements to the Curve Fitting Formular\n");

    for(int8_t i = 0; i <= count_steps - 1; i++) {

        //Measured Plato in float and Measured Gravity in 11 decimal place float
    	ESP_LOGI(TAG,"Step:%d, Plato:%f Â°P ,Gravity:%.11f Â°G",i,MeasuredPlato[i],MeasuredGravity[i]);

        Fit_Curve_5dg.set_Coord(i, MeasuredGravity[i], MeasuredPlato[i]);
        //Fit_Curve_5dg.Load_Example_CalibrationPoints();
    }

    ESP_LOGI(TAG,"Starting calibration process\n");
}

/**
 * Calculates the Polynomial coefficients based on the calibration 
 * data provided (angles and plato).
*/
bool Calibrator::calculate() {
    //Print_Info(LOGLEVEL_INFO, "The calibration was started");
    ESP_LOGI(TAG,"The calibration was started");
    begin();
    calculate_Coeeficents(Fit_Curve_5dg,5);
        Coefficients[6] = 0; 

   return true;
}


void Calibrator::clear(void) {
    for(int8_t i = 0; i < 6; i++) {
        Coefficients[i]         =   0;
        l_coefficients_5deg[i]  =   0;
    }
}


/**
 * @brief The calculated coefficients are now moved to the Temp variable in order to write them into the Hydrom Config later, if necessary.
 * 
 * @param l_Curve This value transfers the measured values
 * @param degree A polynomial of which grade should be fitted?
 */
void Calibrator::calculate_Coeeficents(FindCurve &l_Curve, int degree) {
    int l;

    ESP_LOGI(TAG, "Start to find a Curve with %d degree.", degree);
    if(l_Curve.cal_Coeff(degree)) {
        for(int8_t i = 0; i <= degree; i++){
            l=degree-i;
            Coefficients[l] = l_Curve.get_coeffs(i);
            Deviation[i] = l_Curve.get_Curve_Quality(i);

            ESP_LOGI(TAG,"The calculated Coefficent %.11f for %d . The measured value ( %.2f / %.2f ) differ by %.11f .",l_Curve.get_coeffs(i),l,l_Curve.get_Coord(i,true),l_Curve.get_Coord(i,false),l_Curve.get_Curve_Quality(i));
        }

        ESP_LOGI(TAG,"The coefficients of a polynomial of degree %d were successfully calculated.",degree);
    } else {

        ESP_LOGI(TAG,"The calculation of the coefficients of a polynomial of degree %d failed.",degree);
    }
}

double Calibrator::get_Coeeficents(int8_t Index){
    return Coefficients[Index];
}

double Calibrator::get_Deviation(int8_t Index){
    return Deviation[Index];
}


void Calibrator::set_MeasuredPlato(int8_t Index,float Value){
    MeasuredPlato[Index]=Value;
}

void Calibrator::set_MeasuredGravity(int8_t Index,float Value){
    MeasuredGravity[Index]=Value;
}

void Calibrator::set_MeasuredTemperature(int8_t Index,float Value){
    MeasuredTemperature[Index]=Value;
}
