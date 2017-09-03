/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *fonts[] = {
	"monospace:size=11"
};
static const char dmenufont[]       = "monospace:size=11";
static const char normbordercolor[] = "#ff0000";
static const char normbgcolor[]     = "#000000";
static const char normfgcolor[]     = "#00ee00";
static const char selbordercolor[]  = "#00ff00";
static const char selbgcolor[]      = "#000000";
static const char selfgcolor[]      = "#ef0000";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static unsigned int snap      = 15;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

/* tagging . press Alt for using shift-keys :)*/
static const char *tags[] = { "1", "2", "3", "4", "5"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "conky",     NULL,       NULL,       0,            1,           -1 },
	
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
        { "><>",      NULL },    /* no layout function means floating behavior */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "=[]",      htile },/* tile border is horizontal, not vertical*/
};

/* key definitions */
#define MODKEY Mod1Mask
//#define WINDOWMASK Mod4Mask
#define WINDOWMASK XK_Super_L
#define XK_XF86AudioRaiseVolume 0x1008ff13
#define XK_XF86AudioLowerVolume 0x1008ff11
#define XK_XF86MonBrightnessDown 0x1008ff03
#define XK_XF86MonBrightnessUp 0x1008ff02
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ ControlMask|ShiftMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ ControlMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-b", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "xfce4-terminal", NULL };
static const char *prtscr[]={"screenshot", NULL};
static const char *thunar[]={"thunar",NULL};
static const char *volumeup[]={"amixer", "set", "Master", "5%+", NULL};
static const char *volumedown[]={"amixer", "set", "Master", "5%-", NULL};
static const char *uplight[]={"xbacklight", "+5", NULL};
static const char *downlight[]={"xbacklight", "-5", NULL};

static Key keys[] = {
	// modifier                     key        function        argument
	{ 0,                       WINDOWMASK,      spawn,          {.v = dmenucmd } },
        { 0,                          XK_Print,     spawn,          {.v=prtscr}},
        { MODKEY,                       XK_e,      spawn,          {.v =thunar} },
	{ MODKEY|ControlMask,              XK_t, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom_float,           {.i=+1} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,             XK_F4,      killclient,     {0} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,			XK_y,	   setlayout,	   {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ControlMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ShiftMask|ControlMask,                       XK_Left,  focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask|ControlMask,                       XK_Right, focusmon,       {.i = +1 } },
	{ MODKEY|ControlMask,             XK_Left,  tagmon,         {.i = -1 } },
	{ MODKEY|ControlMask,             XK_Right, tagmon,         {.i = +1 } },
	{ 0,						XK_XF86AudioRaiseVolume,	spawn,	{ .v=volumeup }	},
	{ 0,						XK_XF86AudioLowerVolume,	spawn,	{ .v=volumedown }	},
	{ 0,						XK_XF86MonBrightnessDown,	spawn,	{ .v=downlight }	},
	{ 0,						XK_XF86MonBrightnessUp,	spawn,	{ .v=uplight }	},
	{ ControlMask|ShiftMask,		XK_r,	   update_configuration, {0} },
    TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ControlMask,             XK_BackSpace,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button3,        killclient,           {0} },
	{ ClkWinTitle,          0,              Button1,        focusstack,           {.i=+1} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

