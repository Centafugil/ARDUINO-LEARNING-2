SENSOR 1 :- LDR (Light Dependent Resistor)


Working : LDR changes its Resistance based on the Light exposure


Value range : 0 - 1023


//For mapping values from input to output

    *Use map(value, inputLow, inputHigh, outputLow, OutputHigh)*


'specialNote' - An arduino cannot directly understand change in resistor use an Voltage divder circuit and hook the arduino
                at the middle of the ldr and resistor to get change in voltage.