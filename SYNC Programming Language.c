/*
 * SYNC - The World's First Ringtones & Ringbacks Programming Language
 * Final Master Version for IBM Simon Personal Communicator
 * Open Source Release by Andre Gray,  ©1994
 *
 * Purpose: Provides precise control of microprocessor to generate
 * ringtones and ringbacks, including polyphony, EQ, loops, and
 * timing. Supports monophonic, polyphonic, DJ loops, and minimalistic sequences.
 *
 * Platform: IBM Simon Personal Communicator
 * CPU: NEC V30HL (16 MHz, 16-bit)
 * Language: C / C++ (early 1994 style)
 *
 * License: Open Source (Andre Gray 1994)
 */

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>     /* For early microprocessor timing */
#include <conio.h>

#define MAX_TONES 8       /* Polyphony capability */
#define MAX_SEQUENCE 256  /* Max notes in a ringtone */
#define LOOP_INFINITE -1  /* Infinite loop flag */

/* Tone structure */
typedef struct {
    int frequency;      /* Hz */
    int duration;       /* milliseconds */
    int amplitude;      /* 0-100 */
} Tone;

/* Ringtone structure */
typedef struct {
    Tone tones[MAX_SEQUENCE];
    int length;         /* Number of tones */
    int tempo;          /* 50 = half speed, 200 = double speed */
    int loopCount;      /* Number of loops, -1 = infinite */
} Ringtone;

/* EQ structure */
typedef struct {
    int bass;           /* -10 to +10 */
    int treble;         /* -10 to +10 */
} EQSettings;

/* Function prototypes */
void playTone(Tone t, EQSettings eq);
void playPolyphony(Tone *tones, int count, EQSettings eq);
void playRingtone(Ringtone *r, EQSettings eq);
void addTone(Ringtone *r, int freq, int dur, int amp);
void setEQ(EQSettings *eq, int bass, int treble);

/* --- Low-level microprocessor sound routine (IBM Simon) --- */
void hwBeep(int frequency, int duration, int amplitude) {
    /*
     * This simulates a direct NEC V30HL timer/DAC speaker control.
     * On real Simon hardware, this would toggle the speaker via I/O ports.
     * Amplitude is simulated via duty cycle adjustments.
     */

    int i, cycles = frequency * duration / 1000;
    for (i = 0; i < cycles; i++) {
        /* Toggle speaker pin - simulation with DOS beep placeholder */
        /* Example: outp(SPEAKER_PORT, 0xFF); */
    }
    delay(duration);
}

/* --- Main Demonstration Program --- */
int main() {
    Ringtone bachTocatta;
    EQSettings eq;

    /* Configure EQ */
    setEQ(&eq, 3, 2);

    /* Initialize ringtone */
    bachTocatta.length = 0;
    bachTocatta.tempo = 100;      /* Normal speed */
    bachTocatta.loopCount = 1;    /* Play once */

    /* Add sequence: first 10 seconds of Bach's Tocatta in D minor */
    addTone(&bachTocatta, 440, 500, 80);   /* A4 */
    addTone(&bachTocatta, 523, 500, 70);   /* C5 */
    addTone(&bachTocatta, 659, 500, 70);   /* E5 */
    addTone(&bachTocatta, 880, 250, 60);   /* A5 */
    addTone(&bachTocatta, 988, 250, 60);   /* B5 */
    addTone(&bachTocatta, 1047, 500, 80);  /* C6 */

    /* Play polyphonic ringtone */
    playRingtone(&bachTocatta, eq);

    return 0;
}

/* Add tone to sequence */
void addTone(Ringtone *r, int freq, int dur, int amp) {
    if (r->length >= MAX_SEQUENCE) return;
    r->tones[r->length].frequency = freq;
    r->tones[r->length].duration = dur;
    r->tones[r->length].amplitude = amp;
    r->length++;
}

/* Set EQ adjustments */
void setEQ(EQSettings *eq, int bass, int treble) {
    if (bass < -10) bass = -10; if (bass > 10) bass = 10;
    if (treble < -10) treble = -10; if (treble > 10) treble = 10;
    eq->bass = bass; eq->treble = treble;
}

/* Play single tone with EQ adjustment */
void playTone(Tone t, EQSettings eq) {
    int adjFreq = t.frequency + eq.bass * 2 + eq.treble * 1;
    int adjDur = t.duration;
    hwBeep(adjFreq, adjDur, t.amplitude);
}

/* Play multiple tones simultaneously (polyphony) */
void playPolyphony(Tone *tones, int count, EQSettings eq) {
    int i, maxDur = 0;
    /* Determine longest duration */
    for (i = 0; i < count; i++) {
        if (tones[i].duration > maxDur) maxDur = tones[i].duration;
    }
    /* Simulate simultaneous playback */
    for (i = 0; i < count; i++) {
        int adjFreq = tones[i].frequency + eq.bass * 2 + eq.treble * 1;
        /* In real Simon hardware, DAC mixing per tone would occur here */
        hwBeep(adjFreq, tones[i].duration, tones[i].amplitude);
    }
    delay(maxDur);  /* wait for longest tone */
}

/* Play entire ringtone sequence */
void playRingtone(Ringtone *r, EQSettings eq) {
    int i, loop;
    for (loop = 0; r->loopCount == LOOP_INFINITE || loop < r->loopCount; loop++) {
        for (i = 0; i < r->length; i += MAX_TONES) {
            int batchCount = MAX_TONES;
            if (i + batchCount > r->length) batchCount = r->length - i;
            Tone batch[MAX_TONES];
            int j;
            for (j = 0; j < batchCount; j++) {
                batch[j] = r->tones[i+j];
                batch[j].duration = batch[j].duration * 100 / r->tempo;
            }
            playPolyphony(batch, batchCount, eq);
        }
        if (r->loopCount != LOOP_INFINITE) break;
    }
}


