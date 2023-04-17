/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

/**
  * Converts inches to meters
  *
  * @param inches - inches to convert
  * @return inches - converted to meters
  */
static double in_to_m(double inches) { return inches / 39.37; }
/**
  * Convert meters to inches
  *
  * @param m - meters to convert
  * @return - meters converted to inches
  */
static double m_to_in(double m) { return m * 39.37; }
/**
  * Convert degrees to radians
  *
  * @param deg - degrees to convert
  * @return - deg converted to radians
  */
static double deg_to_rad(double deg) { return deg * (M_PI/180); }
/**
  * Convert radians to degrees
  *
  * @param rad - radians to convert
  * @return - rad converted to degrees
  */
static double rad_to_deg(double rad) { return rad * (180/M_PI); }
/**
  * Convert Volts to Velocity
  * @param volts - Input volts to convert
  * @param maxVelo - Max possible velocity of subsystem
  * @return - voltage conversion of specified velocity
  */
static short int volt_to_velo(float volts, int maxVelo) { return (maxVelo/12.0) * volts; }
/**
  * Convert Velocity to Volts - Useful for commanding motor via voltage by inputing velocity in rpm 
  * @param velo specified velocity to convert to voltage
  * @param maxVelo - the maximum possible velocity of the system
  * @return - converted voltage of specified velocity
  */
static float velo_to_volt(int velo, int maxVelo) { return 12.0 / (double(maxVelo) / velo); }
/**
  * Convert percentage into voltage - Useful for commanding motor via voltage by inputing velocity in percentage of power
  * @param perc - input percentage to convert (0 - 100)
  * @return - the voltage for the specified percentage (0.0 - 12.0)
  */
static float pct_to_volts(int inpPercentage) { return (inpPercentage / 100.0) * 12.0; }
/**
  * Convert voltage into percentage
  * @param inpVolts - input voltage to convert (0.0 - 12.0)
  * @return - the percentage for the specified voltage (0 - 100)
  */
static float volts_to_pct(int inpVolts) { return (inpVolts / 100.0) * 12.0; }