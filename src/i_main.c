//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//	Main program, simply calls D_DoomMain high level loop.
//

#include "config.h"
#include "crispy.h"

#include <stdio.h>

#include "SDL.h"

#include "doomtype.h"
#include "i_system.h"
#include "m_argv.h"
#include "m_misc.h" // [crispy] M_snprintf()

//
// D_DoomMain()
// Not a globally visible function, just included for source reference,
// calls all startup code, parses command line options.
//

void D_DoomMain (void);

int main(int argc, char **argv)
{
    // save arguments

    myargc = argc;
    myargv = argv;

    crispy->platform = SDL_GetPlatform();
    {
        char buf[16];
        SDL_version version;
        SDL_GetVersion(&version);
        M_snprintf(buf, sizeof(buf), "%d.%d.%d", version.major, version.minor, version.patch);
        crispy->sdlversion = M_StringDuplicate(buf);
    }

    M_FindResponseFile();

    // start doom

    D_DoomMain ();

    return 0;
}

const char *I_GetCurrentAudioDriver(void)
{
	const char *driver_name = SDL_GetCurrentAudioDriver();

	return driver_name ? driver_name : "none";
}
