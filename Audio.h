/*****************************************************************//**
 * @file   Audio.h
 * @brief  This class is used to handle importing audio and playback.
 *
 * @author Qiuhao Zeng
 * @date   29/11/2022
***********************************************************************/
#pragma once

#ifndef _Audio_

#define _Audio_


#include "raylib.h"
//#include <unistd.h>
#include <string>
#include <vector>

class Audio {
	private:
		/**
		* @brief Store the loaded audio.
		*/
		std::vector<Sound> audios;
		/**
		* @brief Flag to show the game is paused.
		*/
		bool pause_flag;
		/**
		* @brief Path to intro audio.
		*/
		const char *audio_intro = "./assets/music/pacman_beginning.wav";
		/**
		* @brief Path to pacman chomp SFX.
		*/
		const char *audio_effect1 = "./assets/music/pacman_chomp.wav";

	public:
		/**
		* Construct an audio object by pushing audio to audios vector
		* @brief Default Constructor.
		*/
		Audio();
		/* Destructor */
		~Audio();
		/**
		* Play the audio at specified index.
		* @brief Play audio.
		* @param index Number indicating index where audio is stored.
		*/
		void playAudio(int index);
		/**
		 * Used to pause background music(Stored in audios[0])
		 * @brief Pause background Music.
		 */
		void pauseBgm();
		/**
		 * Used to continue playback of background music(Stored in audios[0])
		 * @brief Resume background Music.
		 */
		void resumeBgm();
};

#endif
