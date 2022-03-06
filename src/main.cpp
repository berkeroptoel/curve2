#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Calibrator.h"

extern "C" {
   void app_main();
}

void app_main()
{
    printf("Hello world!\n");

    Calibrator Clb;

    Clb.set_MeasuredPlato(0, 1.0);
    Clb.set_MeasuredPlato(1, 1.1);
    Clb.set_MeasuredPlato(2, 1.2);
    Clb.set_MeasuredPlato(3, 1.3);
    Clb.set_MeasuredPlato(4, 1.4);
    Clb.set_MeasuredPlato(5, 1.5);
    Clb.set_MeasuredPlato(6, 1.6);

    Clb.set_MeasuredGravity(0, 9.81);
    Clb.set_MeasuredGravity(1, 9.83);
    Clb.set_MeasuredGravity(2, 9.85);
    Clb.set_MeasuredGravity(3, 9.87);
    Clb.set_MeasuredGravity(4, 9.89);
    Clb.set_MeasuredGravity(5, 9.91);
    Clb.set_MeasuredGravity(6, 9.93);

    Clb.calculate();


}


