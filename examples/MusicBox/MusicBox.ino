/*
 * SPDX-License-Identifier: (Apache-2.0 OR LGPL-2.1-or-later)
 *
 * Copyright 2022 Sony Semiconductor Solutions Corporation
 */

#ifndef ARDUINO_ARCH_SPRESENSE
#error "Board selection is wrong!!"
#endif
#ifdef SUBCORE
#error "Core selection is wrong!!"
#endif

#include <MemoryUtil.h>

#include <ScoreSrc.h>
#include <SFZSink.h>

SFZSink sink("SawLpf.sfz");
ScoreSrc inst("SCORE", sink);

void setup() {
    // init built-in I/O
    Serial.begin(115200);
    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);

    // initialize memory pool
    initMemoryPools();
    createStaticPools(MEM_LAYOUT_RECORDINGPLAYER);

    // setup instrument
    if (!inst.begin()) {
        Serial.println("ERROR: init error.");
        while (true) {
            delay(1000);
        }
    }

    Serial.println("Ready to play MusicBox");
}

void loop() {
    // run instrument
    inst.update();
}
