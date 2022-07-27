/*
 * SPDX-License-Identifier: (Apache-2.0 OR LGPL-2.1-or-later)
 *
 * Copyright 2022 Sony Semiconductor Solutions Corporation
 */

#ifndef YURUINSTRUMENT_FILTER_H_
#define YURUINSTRUMENT_FILTER_H_

#include <stdint.h>
#include <stddef.h>

static const uint8_t INVALID_NOTE_NUMBER = 0xFF;
static const uint8_t NOTE_NUMBER_MIN = 0x00;
static const uint8_t NOTE_NUMBER_MAX = 0x7F;
static const uint8_t DEFAULT_VELOCITY = 64;
static const uint8_t DEFAULT_CHANNEL = 0;
static const int PITCH_NUM = 12;

/// Interface of YuruInstument component
class Filter {
public:
    enum ParamId {            //
        PARAMID_OUTPUT_LEVEL  //<
    };

    virtual bool begin() = 0;
    virtual void update() = 0;
    virtual bool isAvailable(int param_id) = 0;
    virtual intptr_t getParam(int param_id) = 0;
    virtual bool setParam(int param_id, intptr_t value) = 0;
    virtual bool sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel) = 0;
    virtual bool sendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel) = 0;
};

/// Null of YuruInstrument component
class NullFilter : public Filter {
public:
    NullFilter() {
    }

    ~NullFilter() {
    }

    bool begin() override {
        return true;
    }

    void update() override {
    }

    bool isAvailable(int param_id) override {
        return false;
    }

    intptr_t getParam(int param_id) override {
        return 0;
    }

    bool setParam(int param_id, intptr_t value) override {
        return false;
    }

    bool sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel) override {
        return true;
    }

    bool sendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel) override {
        return true;
    }
};

/// Base class of YuruInstrument component
class BaseFilter : public Filter {
protected:
    Filter* next_filter_;

public:
    BaseFilter(Filter* filter) : next_filter_(filter) {
    }

    BaseFilter(Filter& filter) : BaseFilter(&filter) {
    }

    ~BaseFilter() {
    }

    bool begin() override {
        if (next_filter_ == nullptr) {
            return false;
        }
        return next_filter_->begin();
    }

    void update() override {
        if (next_filter_ == nullptr) {
            return;
        }
        next_filter_->update();
    }

    bool isAvailable(int param_id) override {
        if (next_filter_ == nullptr) {
            return false;
        }
        return next_filter_->isAvailable(param_id);
    }

    intptr_t getParam(int param_id) override {
        if (next_filter_ == nullptr) {
            return 0;
        }
        return next_filter_->getParam(param_id);
    }

    bool setParam(int param_id, intptr_t value) override {
        if (next_filter_ == nullptr) {
            return false;
        }
        return next_filter_->setParam(param_id, value);
    }

    bool sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel) override {
        if (next_filter_ == nullptr) {
            return false;
        }
        return next_filter_->sendNoteOn(note, velocity, channel);
    }

    bool sendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel) override {
        if (next_filter_ == nullptr) {
            return false;
        }
        return next_filter_->sendNoteOff(note, velocity, channel);
    }
};

#endif  // YURUINSTRUMENT_FILTER_H_