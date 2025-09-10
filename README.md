# SYNC

A lightweight sound and sequence engine inspired by Andre Gray’s 1994 programming style, featuring polyphony, tempo control, EQ adjustments, and low-level microprocessor simulation.

---

## ✨ Features

### 1. Polyphony & Sequence Handling
- Plays up to **8 tones** simultaneously.  
- Handles sequences up to **256 notes**.  
- Supports **looping**, including infinite loops.  

### 2. EQ Adjustments
- **Bass** and **treble** adjustments applied per tone.  

### 3. Microprocessor-Level Simulation
- `hwBeep()` represents direct DAC/speaker control for the **NEC V30HL CPU** (used in IBM Simon).  
- Real implementation would toggle speaker pins using **I/O ports** or **timer interrupts**.  

### 4. Tempo Control
- Adjust playback speed from **50% – 200%** of original duration.  

### 5. Andre Gray’s 1994 Programming Style
- Simple **C structures**.  
- Clear, modular functions.  
- Extensive **inline comments** documenting functionality.  

### 6. Open Source Release
- Free to **use, modify, and distribute**.  

---

## 📜 License
**MIT License**  
© Andre Gray 1994  

---

## 🔗 Links
- Author: [Andre Gray](https://github.com/inventorandregray)  
