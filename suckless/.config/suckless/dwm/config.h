/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "FiraCode-Regular:size=12", "SymbolsNerdFont-Regular:size=12" };
static const char dmenufont[]       = "FiraCode-Regular:size=14";
static const char col_bgdark[]      = "#000000"; //"#111111";
// static const char col_borderdark[]  = "#000000"; //"#555555";
// static const char col_fgdark[]      = "#D8CAAC"; //"#eeeeee";
static const char col_fglight[]     = "#FFFBEF";
static const char col_bglight[]     = "#272E33"; //"#186E0B";
static const char *colors[][3]      = {
	/*               fg           bg           border   */
	[SchemeNorm] = { col_fglight,  col_bgdark, col_bglight },
	[SchemeSel]  = { col_fglight, col_bglight, col_fglight  },
};

/* tagging */
static const char *tags[] = { "", "󰖟", "", "4", "5", "6", "7", "8", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class            instance    title       tags mask     isfloating   monitor */
//	{ "Gimp"           ,NULL,      	NULL,       0,            1,           -1 },
	{ "ffplay"         ,NULL,       NULL,       0,            1,           -1 },
	{ "pavucontrol"    ,NULL,       NULL,       0,            1,           -1 },
	{ "transmission"   ,NULL,       NULL,       0,            1,           -1 },
	{ "Volume"         ,NULL,       NULL,       0,            1,           -1 },
	{ "Bluetooth"      ,NULL,       NULL,       0,            1,           -1 },
	{ "Power"          ,NULL,       NULL,       0,            1,           -1 },
	{ "vlc"            ,NULL,       NULL,       0,            1,           -1 },
	{ "Brave-browser"  ,NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Google-chrome"  ,NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Thunar"         ,NULL,       NULL,       1 << 2,       0,           -1 },
	{ "libreoffice-writer",NULL,    NULL,       1 << 3,       0,           -1 },
	{ "Lxappearance"   ,NULL,       NULL,       0,            1,           -1 },
	{ "feh"            ,NULL,       NULL,       0,            1,           -1 },
	{ "Timeshift-gtk"  ,"timeshift-gtk","Timeshift-gtk",0    ,1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
        { "[\\]",      dwindle },
        { "><>",      NULL },    /* no layout function means floating behavior */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
 	{ "[@]",      spiral },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_bgdark, "-nf", col_fglight, "-sb", col_bglight, "-sf", col_fglight, NULL };
static const char *termcmd[]  = { "st", NULL };

/* custom commands */
static const char *browsercmd[]     = { "brave", NULL};
static const char *chromecmd[]      = { "google-chrome-stable", NULL};
static const char *filemanagercmd[] = { "thunar", NULL};
static const char *clipboardcmd[]   = { "clipmenu", "-i", "-fn", dmenufont, "-nb", col_bgdark , "-nf", col_fglight, "-sb", col_bglight, "-sf", col_fglight , NULL};
static const char *rockercmd[]      = { "st", "-c", "Volume", "alsamixer", NULL};
static const char *lockcmd[]        = { "slock", NULL};
static const char *btcmd[]          = { "st", "-c", "Bluetooth", "bluetoothctl", NULL};
static const char *camcmd[]         = { "ffplay", "-window_title", "Webcam", "/dev/video0", NULL};
static const char *powercmd[]       = { "st", "-c", "Power", "bash","/home/nitin-arya/.scripts/on_and_off.sh", NULL};
static const char *sscmd[]          = { "flameshot", "gui", NULL};
static const char *upvol[]          = { "/usr/bin/amixer",  "set", "Master", "5%+",   NULL };
static const char *downvol[]        = { "/usr/bin/amixer",  "set", "Master", "5%-",   NULL };
static const char *mutevol[]        = { "/usr/bin/amixer",  "set", "Master", "toggle",NULL };

//static const char *brightup[]    = { "brightnessctl", "set", "5+%",NULL };
//static const char *brightdown[]  = { "brightnessctl", "set", "5-%",NULL }

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_Down,   focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Up,     focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_Left,   setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Right,  setmfact,       {.f = +0.05} },
//	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_F1,     setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_F2,     setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_F3,     setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_F4,     setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_F5,     setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY,                       XK_Delete, spawn, 	       {.v = downvol } },
	{ MODKEY,                       XK_End,    spawn, 	       {.v = mutevol } },
	{ MODKEY,                       XK_Insert, spawn, 	       {.v = upvol   } },
	{ MODKEY,                       XK_w,      spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_g,      spawn,          {.v = chromecmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = filemanagercmd } },
	{ MODKEY|ShiftMask,             XK_v,      spawn,          {.v = rockercmd } },
	{ MODKEY,                       XK_s,      spawn,          {.v = btcmd } },
	{ MODKEY,                       XK_c,      spawn,          {.v = camcmd } },
	{ 0,                            XK_Print,  spawn,          {.v = sscmd } },
	{ MODKEY,                       XK_v,      spawn,          {.v = clipboardcmd } },
	{ MODKEY,                       XK_l,      spawn,          {.v = lockcmd } },
	{ Mod1Mask,                     XK_F4,     spawn,          {.v = powercmd } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

