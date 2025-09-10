# BlackBerry OS 5 Multimedia Suite (Java ME)

A fully functional multimedia suite for **BlackBerry OS 5**, written in **Java ME**, providing a native experience with audio, video, and image playback.

---

##  Features Implemented

### 1. Image Slideshow
- Next / Previous buttons  
- Loads images from project resources (`.png` or `.bmp`)

### 2. Audio Playlist
- Play current audio file  
- Move to next audio track  

### 3. Video Playlist
- Play current video file (`.3gp` preferred)  
- Move to next video track  

### 4. UI Controls
- Fully native using `ButtonField` and `BitmapField`  
- Alerts for error handling using `Dialog.alert()`  

### 5. Resource Management
- Stops and closes media players to avoid memory leaks  
- Keeps UI responsive  

---

##  Notes on OS 5 Compatibility
- Video must be small (**<100 KB**) for smooth playback  
- Audio files should be short (**<2–3 MB**) to prevent memory issues  
- No background multitasking for media; all playback happens in the same thread  
- Touch support is minimal on OS 5 devices; buttons mainly work with **trackball/keyboard**  

---

© Andre Gray 2009
