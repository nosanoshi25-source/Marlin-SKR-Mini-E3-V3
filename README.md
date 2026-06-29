# Marlin Firmware - SKR Mini E3 V3 Configuration

Configuration Marlin 2.1.x prête à compiler pour :
- **Carte mère** : SKR Mini E3 V3
- **Extrudeur** : BIQU H2 V2S (Direct Drive)
- **Imprimante** : CR10V3 (300x300x400)
- **Capteur** : BLTouch
- **Écran** : BTT TFT tactile

## 🎯 Caractéristiques de cette configuration

✅ **Moteurs TMC2209** en communication UART  
✅ **Direct Drive** : Courant E0 réduit à 550mA (protection H2 V2S)  
✅ **Nivellement auto** : BLTouch avec offset calibré (-39, -7, 0)  
✅ **Écran tactile BTT** : Configuration série 250000 bauds  
✅ **Sécurité thermique** : Protections pour hotend et lit  
✅ **Rétractation optimisée** : 0.5mm pour Direct Drive  

## 📦 Fichiers inclus

- `Configuration.h` - Configuration de base
- `Configuration_adv.h` - Configuration avancée
- `README.md` - Ce fichier

## 🔧 Installation & Compilation

### Prérequis
- PlatformIO CLI installé
- Marlin 2.1.x source code

### Étapes

1. **Télécharger Marlin 2.1.x**
```bash
git clone --depth=1 --branch=2.1.x https://github.com/MarlinFirmware/Marlin.git
cd Marlin
```

2. **Copier les fichiers de configuration**
```bash
cp Configuration.h Marlin/
cp Configuration_adv.h Marlin/
```

3. **Compiler le firmware**
```bash
platformio run -e STM32F103RE_bigtree
```

4. **Localiser le fichier .bin**
```bash
# Le firmware compilé se trouve ici :
.pio/build/STM32F103RE_bigtree/firmware.bin
```

## 📝 Notes importantes

⚠️ **Après flashage de la SKR Mini E3 V3** :

1. Faire un reset EEPROM :
```gcode
M502  ; Reset à Marlin défaut
M500  ; Sauvegarder en EEPROM
```

2. Homing complet :
```gcode
G28  ; Homing XYZ
```

3. Leveling automatique du lit :
```gcode
G29  ; Mesh leveling avec BLTouch
```

4. **PID Tune** (IMPORTANT - À faire absolument) :
```gcode
M303 E0 S200 C8  ; Tune Hotend à 200°C
M303 E-1 S60 C8  ; Tune Lit à 60°C
M500             ; Sauvegarder
```

## 🔌 Connexions importantes

### BLTouch
- Signal : Z_MIN
- GND : GND
- +5V : +5V

### TMC2209
- RX/TX sur UART1 et UART2 (selon configuration)

### Écran BTT TFT
- Serial Port 1 (UART) à 250000 bauds
- GND et +5V

## 📚 Ressources

- [Marlin Documentation](https://marlinfw.org/)
- [SKR Mini E3 V3 Repository](https://github.com/bigtreetech/SKR-mini-E3)
- [BIQU H2 V2S Repository](https://github.com/biqu-equipment/H2)

## ⚡ Flashage de la carte

### Avec ST-Link V2
```bash
STM32CubeProgrammer -c port=SWD -d firmware.bin -v
```

### Avec carte SD (Méthode simple)
1. Copier `firmware.bin` sur une carte SD FAT32
2. Insérer dans la SKR Mini E3 V3
3. La carte flashe automatiquement

## 📧 Support

En cas de problème, vérifiez :
- ✅ Configuration.h et Configuration_adv.h sont copiés
- ✅ L'environnement PlatformIO est `STM32F103RE_bigtree`
- ✅ La version Marlin est 2.1.x
- ✅ Les baudrates sont 250000 pour l'écran BTT
