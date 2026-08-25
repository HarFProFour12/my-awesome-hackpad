# ⌨️ HackPad — 8-Key Macropad

A custom mechanical macropad built from scratch — PCB, firmware, and case all designed in-house. Eight programmable keys, a rotary encoder for quick adjustments, and an OLED screen to show live status.

![Overall HackPad](images/hackpad_overall.png)

## ✨ Features

* **8 mechanical switches** for custom keybindings & macro shortcuts
* **Rotary encoder** with push-button (volume, scroll, or custom actions)
* **OLED status display** (128x32 I2C)
* **QMK-powered firmware** (fully remappable)
* **USB-C connectivity**
* **Custom 3D-printed enclosure**

## 🖥️ Interface

The macropad connects over USB-C and acts as a standard HID keyboard, working out of the box on macOS, Windows, and Linux. Key functions, layers, and encoder behaviors are defined in the QMK firmware and can be remapped without touching the hardware.

The OLED display shows live status info and can be configured to display active layers, system stats, or custom text.

## 🧠 How It Works

The board is driven by a **Seeed XIAO RP2040**, soldered directly onto the PCB. Each of the 8 switches is wired into a 2x4 key matrix (`COL2ROW` diode direction) read by the microcontroller. QMK handles matrix scanning, debouncing, and USB HID reporting.

The rotary encoder and OLED display are connected via dedicated GPIO pins on the XIAO RP2040:
* **Encoder:** Pins `GP0` & `GP1` (Rotation), `GP2` (Push Switch)
* **OLED (I2C):** `GP4` (SDA) & `GP6` (SCL)

![Schematic](images/schematic.png)

![PCB Layout](images/pcb_layout.png)

## 🔧 Hardware

* **Microcontroller:** Seeed XIAO RP2040
* **Switches:** 8× Mechanical key switches
* **Control:** 1× Rotary encoder with push-button
* **Display:** 0.91" 128x32 OLED Display
* **PCB:** Custom 2-layer board designed in KiCad
* **Enclosure:** Custom 3D-printed body and top lid

## 📋 Bill of Materials

| Part | Qty | Notes |
|---|---|---|
| Seeed XIAO RP2040 | 1 | Main MCU |
| Mechanical switches | 8 | Cherry MX style |
| Rotary encoder w/ switch | 1 | Volume & media control |
| 128x32 OLED Display | 1 | I2C Interface |
| Diodes (1N4148) | 8 | Surface mount / Through-hole |
| Custom PCB | 1 | 2-layer board |
| 3D printed case | 1 set | Top lid + main body |

## 📁 Project Structure

```text
my_awesome_hackpad/
├── CAD/
│   ├── hackpad_assembly.step
│   ├── case_top.stl
│   └── case_bottom.stl
├── PCB/
│   ├── hackpad.kicad_pro
│   ├── hackpad.kicad_sch
│   └── hackpad.kicad_pcb
├── Firmware/
│   └── my_awesome_hackpad/
│       ├── info.json
│       ├── config.h
│       ├── rules.mk
│       └── keymaps/
│           └── default/
│               └── keymap.c
├── production/
│   └── gerbers.zip
├── images/
│   ├── hackpad_overall.png
│   ├── schematic.png
│   ├── pcb_layout.png
│   └── case_assembly.png
└── README.md
