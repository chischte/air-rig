void GetForceNPosition()
{

  //*****************************************************************************
  // READ ALL POTENTIOMETERS AND CONVERT THEM INTO DIGITAL VALUES
  // read only one pot per cycle (increased cycle speed)
  //*****************************************************************************

  // read position from linear potentiometer
  valueLinearPot = analogRead(LINEAR_POT);
  currentPosition = (((valueLinearPot - 118) / (787 - 118) * 42) + 0.5)
      * 1000; //[mm/1000] MAP FUNCTION (Measured:0mm=787, 42mm=118) //VALUES IN [mm]

  //read pressure from pressure transmitter
  pressureLowerChamber = analogRead(PRESSURE_SENSOR_LOWER_CHAMBER); // [barg/100] // measured: 0 barg=0; 6barg=608;

  //calculate pneumatic force
  pneumaticForce = pressureLowerChamber * 3.117;
  // [N]
  // 1000 is the conversion from [barg/100] to [N/mm2]
  // 3117 is the area of the Ø63-zylinder

  totalForce = pneumaticForce; // no additional spring force
}
