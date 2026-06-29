/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Configuration pour SKR Mini E3 V3 + BIQU H2 V2S + CR10V3
 * Direct Drive | BLTouch (Port Dédié) | Écran BTT TFT (Mode double / Tactile)
 */

#pragma once
#define CONFIGURATION_H_VERSION 020109

// ============================================================================
// CONFIGURATION DES PORTS SÉRIE (Essentiel pour l'écran tactile BTT)
// ============================================================================
#define SERIAL_PORT 0       // Connexion USB PC / Octoprint
#define SERIAL_PORT_2 1     // Port UART physique pour le mode tactile de l'écran BTT TFT
#define BAUDRATE 250000     // CORRIGÉ : Modifié de 115200 à 250000 pour l'écran tactile BTT TFT d'origine

#define MOTHERBOARD BOARD_SKR_MINI_E3_V3_0

// ============================================================================
// NOM DE LA MACHINE & EXTRUDEURS
// ============================================================================
#define CUSTOM_MACHINE_NAME "CR10V3 H2V2S"
#define EXTRUDERS 1
#define HOTENDS 1

// AJOUTÉ : Pas par millimètre recommandés pour le BIQU H2 V2S (Rapport d'engrenage 7:1)
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 932 }

// ============================================================================
// PARAMÈTRES THERMIQUES (Spécifications H2 V2S)
// ============================================================================
#define TEMP_SENSOR_0 1  // Thermistance NTC100K standard
#define TEMP_SENSOR_BED 1
#define TEMP_SENSOR_PROBE 0

#define HEATER_0_MAXTEMP 270 // Sécurité maximale pour le H2 V2S
#define BED_MAXTEMP 130
#define CHAMBER_MAXTEMP 60

// Valeurs PID génériques (À affiner via un PID Tune sur votre machine)
#define DEFAULT_Kp 21.73
#define DEFAULT_Ki 1.54
#define DEFAULT_Kd 76.55

#define DEFAULT_bedKp 103.10
#define DEFAULT_bedKi 17.35
#define DEFAULT_bedKd 1530.40

#define EXTRUDE_MINTEMP 170
#define EXTRUDE_MAXTEMP 270

// ============================================================================
// PARAMÈTRES DES AXES & PILOTES (TMC2209 en UART)
// ============================================================================
#define X_DRIVER_TYPE TMC2209
#define Y_DRIVER_TYPE TMC2209
#define Z_DRIVER_TYPE TMC2209
#define E0_DRIVER_TYPE TMC2209

#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0

#define INVERT_X_DIR false
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false
#define INVERT_E0 true  // Inversion de rotation requise pour l'extrudeur BIQU H2

#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
//#define USE_ZMIN_PLUG // Désactivé : le BLTouch gère seul le homing de l'axe Z

#define X_MIN_ENDSTOP_INVERTING false
#define Y_MIN_ENDSTOP_INVERTING false
#define Z_MIN_ENDSTOP_INVERTING false

// Dimensions du plateau (CR10V3 : 300x300x400)
#define X_BED_SIZE 300
#define Y_BED_SIZE 300
#define Z_MAX_POS 400

#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0

#define HOMING_FEEDRATE_XY (50*60)
#define HOMING_FEEDRATE_Z (4*60)

// ============================================================================
// NIVELLEMENT & CAPTEUR BLTOUCH (Lignes d'activation essentielles)
// ============================================================================
#define BLTOUCH
#define AUTO_BED_LEVELING_BILINEAR
#define Z_SAFE_HOMING

// CORRIGÉ : Force Marlin à utiliser le port BLTouch/Probe pour faire le Homing du Z
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
