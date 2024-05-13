/* See LICENSE file for copyright and license details. */

/* appearance */
static unsigned int borderpx  	      = 2;        /* border pixel of windows */
static unsigned int snap      	      = 32;       /* snap pixel */
static const unsigned int gappih      = 8;       /* horiz inner gap between windows */
static const unsigned int gappiv      = 8;       /* vert inner gap between windows */
static const unsigned int gappoh      = 6;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov      = 6;       /* vert outer gap between windows and screen edge */
static int smartgaps   		      = 1;        /* 1 means no outer gap when there is only one window */
static int showbar            	      = 1;        /* 0 means no bar */
static int topbar             	      = 1;        /* 0 means bottom bar */
static const int allowkill            = 1;        /* allow killing clients by default? */
static const int horizpadbar          = 2;        /* horizontal padding for statusbar */
static const int vertpadbar           = 6;        /* vertical padding for statusbar */
static const int focusonwheel         = 0;
static const char *fonts[]            = { "InconsolataGo Nerd Font:style=Regular:size=15" };
static const char dmenufont[]         = "InconsolataGo Nerd Font:size=15";
static char normbgcolor[]             = "#222222";
static char normbordercolor[]         = "#444444";
static char normfgcolor[]             = "#bbbbbb";
static char selfgcolor[]              = "#eeeeee";
static char selbordercolor[]          = "#005577";
static char selbgcolor[]              = "#005577";
static char errfgcolor[]              = "#222222";
static char errbgcolor[]              = "#222222";
static char updfgcolor[]              = "#222222";
static char updbgcolor[]              = "#222222";
static char songfgcolor[]             = "#222222";
static char songbgcolor[]             = "#222222";

static char *colors[][3] = {
       /*               fg            bg            border   */
       [SchemeNorm] = { normfgcolor,  normbgcolor,  normbordercolor },
       [SchemeSel]  = { selfgcolor,   selbgcolor,   selbordercolor  },
       [SchemeErr] =  { errfgcolor,   errbgcolor,   normbordercolor  },
       [SchemeUpd] =  { updfgcolor,   updbgcolor,   normbordercolor  },
       [SchemeSong] = { songfgcolor,  songbgcolor,  normbordercolor  },
};

/* tagging */
static char *tags[] = { "web", "cmd", "dir", "msg", "mus", "vid", "misc" };
static const int taglayouts[] = { 0, 0, 0, 2, 0, 0, 1, 0, 1 };
static char *tagsel[][2] = {
        { selfgcolor, selbgcolor },
        { "#FB4934",  selbgcolor },
        { "#FABD2F",  selbgcolor },
        { "#BDAE93",  selbgcolor },
        { "#8ec07c",  selbgcolor },
        { "#FABD2F",  selbgcolor },
        { "#D1859A",  selbgcolor },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class        	 instance    title       tags mask     allowkill     isfloating   monitor */
	{ "Gimp",       	 NULL,       NULL,       0,            1,	     1,           -1 },
	{ "firefox",	         NULL,       NULL,       0,            1,	     0,           -1 },
	{ "firefox",    	 "Places",   NULL,       0,            1,	     1,           -1 },
	{ "firefox",    	 "Browser",  NULL,       0,            1,	     1,           -1 },
	{ "Tor Browser",	 NULL,	     NULL,       1 << 6,       0,	     0,           -1 },
	{ "firefox tl",        	 NULL,       NULL,       1 << 3,       1,	     0,           -1 },
	{ "firefox wa", 	 NULL,       NULL,       1 << 3,       1,	     0,           -1 },
	{ "Spotify", 	  	 NULL,       NULL,       1 << 4,       1,	     0,           -1 },
	{ "KeePassXC",	 	 NULL,       NULL,       0,	       1,	     1,           -1 },
	{ "exiftool",   	 NULL,       NULL,       0,            1,	     1,           -1 },
	{ "weather",    	 NULL,       NULL,       0,            1,	     1,           -1 },
	{ "htop", 	   	 NULL,       NULL,       0,            1,	     1,           -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
        { "[]=",      tile },
        { "><>",      NULL },    /* no layout function means floating behavior */
        { "[M]",      monocle },
        { "⋮⋮⋮",      grid },
	{ "[][]=",    tilewide },
        { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", "-d ~", NULL };

/* alt-tab configuration */
static const unsigned int tabModKey   = 0x40;	/* if this key is hold the alt-tab functionality stays acitve. This key must be the same as key that is used to active functin altTabStart `*/
static const unsigned int tabCycleKey = 0x17;	/* if this key is hit the alt-tab program moves one position forward in clients stack. This key must be the same as key that is used to active functin altTabStart */
static const unsigned int tabPosY     = 1;	/* tab position on Y axis, 0 = bottom, 1 = center, 2 = top */
static const unsigned int tabPosX     = 1;	/* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxWTab     = 460;	/* tab menu width */
static const unsigned int maxHTab     = 120;	/* tab menu height */

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
               { "normbgcolor",        STRING,  &normbgcolor },
               { "normbordercolor",    STRING,  &normbordercolor },
               { "normfgcolor",        STRING,  &normfgcolor },
               { "selbgcolor",         STRING,  &selbgcolor },
               { "selbordercolor",     STRING,  &selbordercolor },
               { "selfgcolor",         STRING,  &selfgcolor },
               { "errbgcolor",         STRING,  &errbgcolor },
               { "errfgcolor",         STRING,  &errfgcolor },
               { "songbgcolor",        STRING,  &songbgcolor },
               { "songfgcolor",        STRING,  &songfgcolor },
               { "updbgcolor",         STRING,  &updbgcolor },
               { "updfgcolor",         STRING,  &updfgcolor },
               { "borderpx",           INTEGER, &borderpx },
};

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key       	 function        argument */
	{ MODKEY,                       XK_p,     	 spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,	 spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,     	 togglebar,      {0} },
	{ MODKEY,                       XK_j,     	 focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,     	 focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,     	 incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,     	 incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,     	 setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,     	 setmfact,       {.f = +0.05} },
        { MODKEY,                       XK_y,     	 setcfact,       {.f = +0.25} },
        { MODKEY,                       XK_n,     	 setcfact,       {.f = -0.25} },
        { MODKEY,                       XK_o,     	 setcfact,       {.f =  0.00} },
	{ MODKEY|ShiftMask,             XK_j,     	 movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,     	 movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Return,	 zoom,           {0} },
	{ MODKEY,                       XK_q,	  	 view,           {0} },
	{ MODKEY,                       XK_masculine,	 shiftview,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_masculine,	 shiftview,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_c,     	 killclient,     {0} },
	{ MODKEY,                       XK_t,     	 setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,     	 setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,     	 setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,     	 setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_c,     	 setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ShiftMask,             XK_f,     	 fullscreen,     {0} },
	{ MODKEY,                       XK_space, 	 setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space, 	 togglefloating, {0} },
	{ MODKEY,                       XK_Down,  	 moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,    	 moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right, 	 moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,  	 moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,  	 moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,    	 moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right, 	 moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,  	 moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,    	 moveresizeedge, {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,  	 moveresizeedge, {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,  	 moveresizeedge, {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right, 	 moveresizeedge, {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,    	 moveresizeedge, {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,  	 moveresizeedge, {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,  	 moveresizeedge, {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right, 	 moveresizeedge, {.v = "R"} },
	{ MODKEY,                       XK_0,     	 view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,     	 tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma, 	 focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,	 focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma, 	 tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,	 tagmon,         {.i = +1 } },
	{ Mod1Mask,             	XK_Tab,   	 altTabStart,	   {0} },
	TAGKEYS(                        XK_1,     	                 0)
	TAGKEYS(                        XK_2,     	                 1)
	TAGKEYS(                        XK_3,     	                 2)
	TAGKEYS(                        XK_4,     	                 3)
	TAGKEYS(                        XK_5,     	                 4)
	TAGKEYS(                        XK_6,     	                 5)
	TAGKEYS(                        XK_7,     	                 6)
	TAGKEYS(                        XK_8,     	                 7)
	TAGKEYS(                        XK_9,     	                 8)
	{ MODKEY|ShiftMask,             XK_q,     	 quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

