/* Copyright (C)
* 2018 - John Melton, G0ORX/N6LYT
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*
*/

#ifndef _AUDIO_H
#define _AUDIO_H

typedef struct _audio_device {
  char *name;
  int index;
  char *description;
} AUDIO_DEVICE;

#define MAX_AUDIO_DEVICES 32

extern int n_input_devices;
extern AUDIO_DEVICE input_devices[MAX_AUDIO_DEVICES];
extern int n_output_devices;
extern AUDIO_DEVICE output_devices[MAX_AUDIO_DEVICES];

extern int audio_open_input(RADIO *r);
extern void audio_close_input(RADIO *r);
extern int audio_open_output(RECEIVER *rx);
#ifdef __APPLE__
void audio_start_output(RECEIVER *rx);
#endif
extern void audio_close_output(RECEIVER *rx);
//extern int audio_write(RECEIVER *rx,short left_sample,short right_sample);
extern int audio_write(RECEIVER *rx,float left_sample,float right_sample);
extern int audio_write_buffer(RECEIVER *rx);
extern void audio_get_cards();
extern void create_audio(/*GMainContext *context*/);
#endif
