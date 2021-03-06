#pragma once

#include "util/common.hpp"
#include "midi.hpp"


namespace rack {


struct KeyboardInputDevice : MidiInputDevice {
	int octave = 5;
	void processKey(int key, bool released);
};


struct KeyboardDriver : MidiDriver {
	KeyboardInputDevice device;
	std::string getName() override {return "Computer keyboard";}

	std::vector<int> getInputDeviceIds() override;
	std::string getInputDeviceName(int deviceId) override;
	MidiInputDevice *subscribeInputDevice(int deviceId, MidiInput *midiInput) override;
	void unsubscribeInputDevice(int deviceId, MidiInput *midiInput) override;
};


void keyboardInit();
void keyboardPress(int key);
void keyboardRelease(int key);


} // namespace rack
