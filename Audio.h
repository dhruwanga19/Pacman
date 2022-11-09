#pragma once

#ifndef _Audio_

#define _Audio_


#include <raylib.h>
#include <unistd.h>
#include <string>
#include <vector>

class Audio {
	private:
		std::vector<Sound> audios;  // Store the loaded audio
		bool pause_flag;  // flag to show the game is paused
		const char *audio_intro = "./assets/music/pacman_beginning.wav";
		const char *audio_effect1 = "./assets/music/pacman_chomp.wav";
	public:
		Audio();  // Default constructor
		~Audio();  // Destructor
		void playAudio(int index);  // Play the audio
		void pauseBgm();  // pause Background music
		void resumeBgm(); // resume Background music
};

#endif
