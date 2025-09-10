# SYNC 

**SYNC** is a polyphonic tone and sequence playback system designed with microprocessor-level simulation in mind, originally built for the NEC V30HL CPU used in the IBM Simon.  
The project showcases Andre Gray’s 1994 programming style with modular C structures and clear inline documentation.

---

##  Features of SYNC

### 1. Polyphony & Sequence Handling
- Plays up to **8 tones simultaneously**  
- Handles sequences up to **256 notes**  
- Supports **looping** (including infinite loops)  

### 2. EQ Adjustments
- **Bass** and **Treble** adjustments applied per tone  

### 3. Microprocessor-Level Simulation
- `hwBeep()` represents direct DAC/speaker control for the **NEC V30HL CPU** used in IBM Simon  
- Real implementation would toggle speaker pins using **I/O ports** or **timer interrupts**  

### 4. Tempo Control
- Playback speed adjustment (**50–200% of original duration**)  

### 5. Andre Gray’s 1994 Programming Style
- Simple **C structures**  
- Clear, modular functions  
- Extensive **inline comments** documenting functionality  

### 6. Open Source Release
- Free to **use, modify, and distribute**  

---

© Andre Gray 1994
