//Copyright Paul Reiche, Fred Ford. 1992-2002

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifdef GFXMODULE_SDL

#include "sdl_common.h"

int batch_depth = 0;


//Status: Not entirely unimplemented!
BOOLEAN
InitGraphics (int argc, char* argv[], COUNT KbytesRequired)
		// Kbytes should only matter if we wanted to port Starcon2 to the
		// hand-helds...
{
	BOOLEAN ret;

	LoadDisplay (&_pCurDisplay);
	mem_init ();
	ActivateDisplay ();

	DrawCommandQueue = TFB_DrawCommandQueue_Create ();

	ret = TRUE;
	return (ret);
}

// Status: Unimplemented
void
UninitGraphics ()  // Also probably empty
{
	HFree (DrawCommandQueue);

	mem_uninit ();
}


// Batch/UnbatchGraphics: These routines appear to be used to ensure
// that the screen doesn't update with a half-drawn region.  This can
// be implemented in all sorts of ways - I've chosen to fold it into
// our DrawCommandQueue, for the most part.  These just forward to
// the TFB_ versions in dcqueue.c.  They may also make continuity_break
// redundant, but I haven't tested that yet.  --Michael
void
BatchGraphics (void)
{
	TFB_BatchGraphics ();
}

void
UnbatchGraphics (void)
{
	TFB_UnbatchGraphics ();
}

void
FlushGraphics (void)
{
	TFB_BatchReset ();
	continuity_break = 1;
}

void
SetGraphicUseOtherExtra (int other) //Could this possibly be more cryptic?!? :)
{
}

void
SetGraphicGrabOther (int grab_other)
{
}

// Status: Unimplemented
void
SetGraphicStrength (int numerator, int denominator)
		// I just hope numerator always = denominator...
{ 
	//fprintf (stderr, "Unimplemented function activated: SetGraphicsStrength(), %d %d\n",numerator,denominator);
}

//Status: Unimplemented
void
ScreenTransition (int TransType, PRECT pRect) //TransType==3
{
	//fprintf (stderr, "Unimplemented function activated: ScreenTransition()\n");
}

void
DrawFromExtraScreen (PRECT r) //No scaling?
{
	RECT locRect;
	TFB_DrawCommand DC;

	if (!r)
	{
		locRect.corner.x = locRect.corner.y = 0;
		locRect.extent.width = SCREEN_WIDTH;
		locRect.extent.height = SCREEN_HEIGHT;
		r = &locRect;
	}

	DC.Type = TFB_DRAWCOMMANDTYPE_COPYFROMOTHERBUFFER;
	DC.x = r->corner.x;
	DC.y = r->corner.y;
	DC.w = r->extent.width;
	DC.h = r->extent.height;
	DC.image = 0;

	TFB_EnqueueDrawCommand (&DC);
}

void
LoadIntoExtraScreen (PRECT r)
{
	RECT locRect;
	TFB_DrawCommand DC;

	if (!r)
	{
		locRect.corner.x = locRect.corner.y = 0;
		locRect.extent.width = SCREEN_WIDTH;
		locRect.extent.height = SCREEN_HEIGHT;
		r = &locRect;
	}

// fprintf (stderr, "LoadIntoExtraScreen (%d, %d, {%d, %d})\n", r->corner.x, r->corner.y, r->extent.width, r->extent.height);
//	DC = HMalloc (sizeof (TFB_DrawCommand));

	DC.Type = TFB_DRAWCOMMANDTYPE_COPYBACKBUFFERTOOTHERBUFFER;
	DC.x = r->corner.x;
	DC.y = r->corner.y;
	DC.w = r->extent.width;
	DC.h = r->extent.height;
	DC.image = 0;

	TFB_EnqueueDrawCommand (&DC);
}

// Status: Ignored
BOOLEAN
InitVideo (BOOLEAN useCDROM) //useCDROM doesn't really apply to us...
{
	BOOLEAN ret;

// fprintf (stderr, "Unimplemented function activated: InitVideo()\n");
	ret = TRUE;
	return (ret);
}

// Status: Ignored
void
UninitVideo ()  //empty
{
	// fprintf (stderr, "Unimplemented function activated: UninitVideo()\n");
}

//Status: Unimplemented
void
VidStop() // At least this one makes sense.
{
		// fprintf (stderr, "Unimplemented function activated: VidStop()\n");
}

//Status: Unimplemented
MEM_HANDLE
VidPlaying()  // Easy enough.
{
		MEM_HANDLE ret;

		//fprintf (stderr, "Unimplemented function activated: VidPlaying()\n");
		ret = 0;
		return (ret);
}

//Status: Unimplemented
VIDEO_TYPE
VidPlay (VIDEO_REF VidRef, char *loopname, BOOLEAN uninit)
		// uninit? when done, I guess.
{
	VIDEO_TYPE ret;
	ret = 0;

// fprintf (stderr, "Unimplemented function activated: VidPlay()\n");
	return (ret);
}

VIDEO_REF
_init_video_file(PVOID pStr)
{
	VIDEO_REF ret;

	fprintf (stderr, "Unimplemented function activated: _init_video_file()\n");
	ret = 0;
	return (ret);
}

// Status: Unimplemented
BOOLEAN
_image_intersect (PIMAGE_BOX box1, PIMAGE_BOX box2, PRECT rect)
		// This is a biggie.
{
	BOOLEAN ret;

// fprintf (stderr, "Unimplemented function activated: _image_intersect()\n");
	ret = TRUE;
	return (ret);
}


#endif
