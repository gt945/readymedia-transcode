/* MiniUPnP project
 * http://miniupnp.free.fr/ or http://miniupnp.tuxfamily.org/
 * (c) 2006 Thomas Bernard 
 * This software is subject to the conditions detailed
 * in the LICENCE file provided within the distribution */

#ifndef __UPNPGLOBALVARS_H__
#define __UPNPGLOBALVARS_H__

#include <time.h>
#include <linux/types.h> // Defines __u32

#include "minidlnatypes.h"
#include "config.h"

#include <sqlite3.h>

#define MINIDLNA_VERSION "1.0.12"

#define CLIENT_CACHE_SLOTS 20
#define USE_FORK 1
#define DB_VERSION 1

#if 0 // Add these once the newer ffmpeg libs that can detect WMAPRO are more widely used
	"http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVHIGH_PRO;DLNA.ORG_OP=01;DLNA.ORG_CI=0,"
	"http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVMED_PRO;DLNA.ORG_OP=01;DLNA.ORG_CI=0,"
	"http-get:*:audio/x-ms-wma:DLNA.ORG_PN=WMAPRO;DLNA.ORG_OP=01,"
#endif
#define RESOURCE_PROTOCOL_INFO_VALUES \
	"http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_TN," \
	"http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_SM;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_MED;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:image/jpeg:DLNA.ORG_PN=JPEG_LRG;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_NTSC;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_PAL;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_HD_NA_ISO;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_TS_SD_NA_ISO;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/mpeg:DLNA.ORG_PN=MPEG1;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_AAC_MULT5;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/mp4:DLNA.ORG_PN=AVC_MP4_MP_SD_AC3;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=MPEG_TS_HD_NA;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/vnd.dlna.mpeg-tts:DLNA.ORG_PN=AVC_TS_MP_HD_AC3_T;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVSPML_MP3;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVSPML_BASE;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVMED_BASE;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVMED_FULL;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:video/x-ms-wmv:DLNA.ORG_PN=WMVHIGH_FULL;DLNA.ORG_OP=01;DLNA.ORG_CI=0," \
	"http-get:*:audio/mpeg:DLNA.ORG_PN=MP3;DLNA.ORG_OP=01," \
	"http-get:*:audio/x-ms-wma:DLNA.ORG_PN=WMABASE;DLNA.ORG_OP=01," \
	"http-get:*:audio/x-ms-wma:DLNA.ORG_PN=WMAFULL;DLNA.ORG_OP=01," \
	"http-get:*:audio/mp4:DLNA.ORG_PN=AAC_ISO_320;DLNA.ORG_OP=01," \
	"http-get:*:audio/mp4:DLNA.ORG_PN=AAC_ISO;DLNA.ORG_OP=01," \
	"http-get:*:audio/mp4:DLNA.ORG_PN=AAC_MULT5_ISO;DLNA.ORG_OP=01," \
	"http-get:*:audio/L16;rate=44100;channels=1:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=01," \
	"http-get:*:audio/L16;rate=44100;channels=2:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=01," \
	"http-get:*:audio/L16;rate=48000;channels=1:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=01," \
	"http-get:*:audio/L16;rate=48000;channels=2:DLNA.ORG_PN=LPCM;DLNA.ORG_OP=01," \
	"http-get:*:image/jpeg:*," \
	"http-get:*:video/avi:*," \
	"http-get:*:video/divx:*," \
	"http-get:*:video/x-matroska:*," \
	"http-get:*:video/mpeg:*," \
	"http-get:*:video/mp4:*," \
	"http-get:*:video/x-ms-wmv:*," \
	"http-get:*:video/x-msvideo:*," \
	"http-get:*:audio/mp4:*," \
	"http-get:*:audio/wav:*," \
	"http-get:*:audio/x-flac:*," \
	"http-get:*:application/ogg:*"

/* statup time */
extern time_t startup_time;

extern struct runtime_vars_s runtime_vars;
/* runtime boolean flags */
extern int runtime_flags;
#define INOTIFYMASK          0x0001
#define SYSUPTIMEMASK        0x0002
#define TIVOMASK             0x0004

#define SETFLAG(mask)	runtime_flags |= mask
#define GETFLAG(mask)	runtime_flags & mask
#define CLEARFLAG(mask)	runtime_flags &= ~mask

extern const char * pidfilename;

extern char uuidvalue[];

#define SERIALNUMBER_MAX_LEN (10)
extern char serialnumber[];

#define MODELNUMBER_MAX_LEN (48)
extern char modelnumber[];

#define PRESENTATIONURL_MAX_LEN (64)
extern char presentationurl[];

/* lan addresses */
/* MAX_LAN_ADDR : maximum number of interfaces
 * to listen to SSDP traffic */
#define MAX_LAN_ADDR (4)
extern int n_lan_addr;
extern struct lan_addr_s lan_addr[];

/* UPnP-A/V [DLNA] */
extern sqlite3 *db;
#define FRIENDLYNAME_MAX_LEN (64)
extern char friendly_name[];
extern struct media_dir_s * media_dirs;
extern struct album_art_name_s * album_art_names;
extern struct client_cache_s clients[CLIENT_CACHE_SLOTS];
extern short int scanning;
extern volatile __u32 updateID;

#endif
