# ⌨️ HackPad — 8-Key Macropad

A custom mechanical macropad built from scratch — PCB, firmware, and case all designed in-house. Eight programmable keys, a rotary encoder for quick adjustments, and an OLED screen to show live status.

![Overall HackPad (Render)](images/hackpad_overall.png)

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
│   ├── case_top.step
│   └── case_bottom.step
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
└── images/
    ├── hackpad_overall.png
    ├── schematic.png
    ├── pcb_layout.png
    └── case_assembly.png

The design is split into CAD, PCB, and firmware folders so each part of the project can be reviewed and iterated on independently.

## 🚧 Current Status

The project is still **under development**.

Currently working on:

* [x] PCB schematic design
* [x] PCB layout and routing
* [x] 3D case design in Fusion 360
* [x] Switch and encoder placement
* [x] Case engraving details
* [x] QMK firmware configuration
* [ ] Parts sourcing
* [ ] Physical assembly
* [ ] Final testing

## 🎨 Design

The case was modeled in Fusion 360 around the PCB layout, with cutouts for the switches, encoder, OLED window, and USB-C port. The enclosure includes custom engraved text on the case exterior for a personalized touch.

The board layout keeps all 8 switches in a clean grid, with the OLED and encoder positioned along the top edge for easy access while typing.

![Case Assembly](images/case_assembly.png)

## 🛠️ Built With

* KiCad
* Autodesk Fusion 360
* QMK Firmware
* 3D printing
* Collaboration with HackClub - Stardance

## 🤖 AI Usage

I used Claude during development, mainly for:

- **KiCad guidance:** since this was my first time using the software, for help navigating the interface.
- **Code debugging:** fixing issues in the firmware.

The actual PCB design, case design, firmware logic, and assembly were done by me.

---
**Made by Harry Fanouriakis**
*A macropad, built one key at a time.* 
