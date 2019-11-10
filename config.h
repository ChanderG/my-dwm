/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *fonts[] = {
	"monospace:size=16"
};
static const char dmenufont[]       = "monospace:size=16";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#003366";
static const char selbgcolor[]      = "#003366";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

static const unsigned int gappx = 24; /* gap pixel between windows */ 
static unsigned int baralpha        = 0xBB;
static unsigned int borderalpha     = OPAQUE;

/* tagging */
static const char *tags[] = { "1", "2", "3", "4q", "5w", "6e", "7r", "o", "m" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 0,       0,           -1 },
	{ "URxvt",    NULL,       "scratchpad",       0,       1,           -1 }, // for wor terminal
	{ "st-256color",    NULL, "scratchpad",       0,       1,           -1 }, // for wor terminal
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
// needs to be 0 to solve ugly spacing issues
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

// urxvt
static const char *utermcmd[]  = { "urxvtc", NULL };
// firefox
static const char *ffcmd[]  = { "firefox", NULL };
// dropdown terminal with tmux - https://github.com/noctuid/tdrop
static const char *termdropcmd[]  = { "tdrop", "-a", "-s", "dropdown", "urxvt", NULL };
// custom scratchpad with urxvt and xdotool
static const char *worspcmd[]  = { "wor-sp", NULL };
// context aware smart prefix
static const char *spcmd[]  = { "smart-prefix", NULL };
// custom status display command
static const char *statuscmd[]  = { "mouse-status", NULL };
// lock only keyboard
static const char *screenlockcmd[]  = { "rlock", "-k", NULL };


static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	// firefox
        { MODKEY|ShiftMask,             XK_f,      spawn,          {.v = ffcmd } },
	// urxvt
        { MODKEY|ShiftMask,             XK_u,      spawn,          {.v = utermcmd } },
	// tmux prefix manager
        { MODKEY|ShiftMask,             XK_s,      spawn,          {.v = spcmd } },
	// drop down terminal
	{ MODKEY,             		XK_o,      spawn,          {.v = termdropcmd } },
	// wor terminal
	{ MODKEY|ShiftMask,       	XK_o,      spawn,          {.v = worspcmd } },
	// status command
	{ MODKEY,             		XK_s,      spawn,          {.v = statuscmd } },
	// move to adjacent tags
	{ MODKEY,                       XK_Right,  view_adjacent,  { .i = +1 } },
	{ MODKEY,                       XK_Left,   view_adjacent,  { .i = -1 } },
	// end
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	// original series
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	// easy access of the middle series
	TAGKEYS(                        XK_q,                      3)
	TAGKEYS(                        XK_w,                      4)
	TAGKEYS(                        XK_e,                      5)
	TAGKEYS(                        XK_r,                      6)
	// inverted number row access series
	TAGKEYS(                        XK_exclam,                 0)
	TAGKEYS(                        XK_at, 	                   1)
	TAGKEYS(                        XK_numbersign,             2)
	TAGKEYS(                        XK_dollar,                 3)
	TAGKEYS(                        XK_percent,                4)
	TAGKEYS(                        XK_asciicircum,            5)
	TAGKEYS(                        XK_ampersand,              6)
	TAGKEYS(                        XK_asterisk,               7)
	TAGKEYS(                        XK_parenleft,              8)
	// inverted access -> all)
	{ MODKEY,                       XK_parenright,    view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_parenright,    tag,            {.ui = ~0 } },
	// done
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = screenlockcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

