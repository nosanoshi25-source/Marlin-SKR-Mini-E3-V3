/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Advanced Configuration pour SKR Mini E3 V3 + BIQU H2 V2S + CR10V3
 */

#pragma once
#define CONFIGURATION_ADV_H_VERSION 020109

// ============================================================================
// PARAMÈTRES COURANTS MOTEURS TMC2209
// ============================================================================
#define MONITOR_DRIVER_STATUS
#define CURRENT_STEP_MAX 5
#define REPORT_CURRENT_CHANGE
#define STOP_ON_ERROR

// Courants moteurs (800 mA pour XYZ, abaissé à 550 mA pour E0 afin d'éviter la surchauffe du pancake H2)
#define X_CURRENT 800
#define X_CURRENT_HOME 800
#define Y_CURRENT 800
#define Y_CURRENT_HOME 800
#define Z_CURRENT 800
#define Z_CURRENT_HOME 800
#define E0_CURRENT 550  // CORRIGÉ : Modifié de 800 à 550 pour préserver le moteur du H2 V2S

#define HOLD_MULTIPLIER 0.5
#define STEALTHCHOP_XY
#define STEALTHCHOP_Z
#define STEALTHCHOP_E
#define TMC_BAUD_RATE 115200

// ============================================================================
// CONFIGURATION DES PALPEURS & MARGES (BLTouch)
// ============================================================================
#define SEGMENT_LEVELED_MOVES
#define LEVELED_SEGMENT_LENGTH 5.0
#define ARC_SUPPORT
#define MM_PER_ARC_SEGMENT 1.0
#define N_ARC_CORRECTION 25

#define MULTIPLE_PROBING 2
#define EXTRA_PROBING 1
#define NOZZLE_TO_PROBE_OFFSET { -39, -7, 0 }
#define PROBING_MARGIN 10

#define Z_PROBE_SPEED_FAST (4*60)
#define Z_PROBE_SPEED_SLOW (2*60)

#define BLTOUCH_FORCE_OPEN_DRAIN_MODE
#define BLTOUCH_SET_SERVOPWM
#define BLTOUCH_DELAY 375

// ============================================================================
// PROTECTIONS THERMIQUES ET VENTILATION
// ============================================================================
#define EXTRUDER_RUNOUT_PREVENT
#define EXTRUDER_RUNOUT_PREVENT_TEMPERATURE 170
#define EXTRUDER_RUNOUT_DISTANCE 5

#define FAST_PWM_FAN
#define FAN_MIN_PWM 35
#define FAN_MAX_PWM 255

#define FAN_KICKSTART_TIME 100
#define TEMP_RESIDENCY_TIME 10
#define TEMP_RESIDENCY_TOLERANCE 2
#define TEMP_WINDOW 1

#define HEATER_0_MINTEMP 5
#define BED_MINTEMP 5

// ============================================================================
// FONCTIONS DE RÉTRACTATION DU MICROLOGICIEL (FWRETRACT)
// ============================================================================
#define BABYSTEPPING
#define BABYSTEP_ALWAYS_AVAILABLE
#define BABYSTEP_XY
#define BABYSTEP_INVERT_Z
#define BABYSTEP_MILLIMETER_UNITS
#define BABYSTEP_EDITABLES

#define NOZZLE_PARK_FEATURE
#define NOZZLE_PARK_POINT { 10, 10, 20 }
#define NOZZLE_PARK_XY_FEEDRATE 100
#define NOZZLE_PARK_Z_FEEDRATE 5

#define PRINTJOB_TIMER_AUTOSTART
#define PRINTCOUNTER
#define HOST_KEEPALIVE_FEATURE
#define DEFAULT_KEEPALIVE_INTERVAL 2

#define FWRETRACT
#define FWRETRACT_AUTORETRACT
#define MIN_AUTORETRACT 0.1
#define MAX_AUTORETRACT 2.0
// Rétractation par défaut abaissée à 0.5 mm pour le Direct Drive H2
#define RETRACT_LENGTH_DEFAULT 0.5
#define RETRACT_FEEDRATE_DEFAULT 45
#define RETRACT_ACCELERATION_DEFAULT 1000
#define RETRACT_RETRACT_ZRAISE_DEFAULT 0
#define RETRACT_RECOVER_FEEDRATE_DEFAULT 45

// ============================================================================
// PARAMÈTRES EEPROM & STRUCTURE DU MAILLAGE
// ============================================================================
#define MESH_INSET 10
#define GRID_MAX_POINTS_X 5
#define GRID_MAX_POINTS_Y 5

#define GCODE_CASE_INSENSITIVE
#define SDCARD_SORT_ALPHA
#define SDSORT_FOLDERS_FIRST

#define EEPROM_SETTINGS
#define EEPROM_CHITCHAT
#define EEPROM_AUTO_INIT
#define EEPROM_SIZE 16384

#define BUFSIZE 32
#define TX_BUFFER_SIZE 32

#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED
#define MAX_BED_POWER 255
#define MAX_EXTRUDER_POWER 255
#define ADAPTIVE_STEP_SMOOTHING
