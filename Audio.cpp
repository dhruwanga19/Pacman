#include "Audio.h"

Audio::Audio(){
	this->audios.push_back(LoadSound(audio_intro));
	this->audios.push_back(LoadSound(audio_effect1));  // add the effect1 to the audio lists
					  // add more sound effects here
}	

Audio::~Audio(){
	// StopSound(this->audios[0]);
	UnloadSound(this->audios[0]);     // Unload sound data
	UnloadSound(this->audios[1]);     // Unload sound data
}

void Audio::playAudio(int index){
	PlaySound(this->audios[index]);
}

void Audio::pauseBgm(){
	this->pause_flag = true;
	PauseSound(this->audios[0]);  // audios[0] is bgm music
}

void Audio::resumeBgm(){
	this->pause_flag = false;
	ResumeSound(this->audios[0]);  // audios[0] is bgm music
}

/*
int main(int argc, char* argv[])
{
	InitAudioDevice();      // Initialize audio device
	Audio audio_control;  // intialize the audio constructor
	audio_control.playAudio(0);  // play the background music
	
	usleep(5 * 1000000); // wait for seconds

	audio_control.playAudio(1);  // test the sound
	usleep(5 * 1000000); // wait for seconds	
	// if (IsKeyPressed(KEY_SPACE)) audio_control.playAudio(0);  // Play WAV sound
	CloseAudioDevice();     // Close audio device
	return 0;
}
*/
