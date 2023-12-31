/* See LICENSE file for copyright and license details. */

#define SESSION_FILE "/tmp/dwm-session"

/* appearance */
static const unsigned int borderpx	= 2;
static const unsigned int fborderpx	= 4;
static const unsigned int snap		= 32;
static int floatposgrid_x			= 5;
static int floatposgrid_y			= 5;

static const unsigned int gappih	= 15;
static const unsigned int gappiv	= 15;
static const unsigned int gappoh	= 15;
static const unsigned int gappov	= 15;
static	int smartgaps				= 0;

static const int showbar			= 1;
static const int topbar				= 1;
static const int user_bh			= 32;

#define ICONSIZE 20
#define ICONSPACING 10

static const char *fonts[]			= { "Ubuntu:size=15", 
										"UbuntuMono Nerd Font:style=Bold:size=17",
										"JetBrainsMono Nerd Font:style=ExtraBold:size=14" };
static const char dmenufont[]		= "Ubuntu:size=15";


#include "colors.h"

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };


/* client rules */
static const Rule rules[] = {
	{ .class = "Lxappearance", .isfloating = 1, .floatpos = "50% 50% -1h -1w" },
	{ .class = "firefox", .tags = 1 << 1 },
	{ .class = "Thunar", .tags = 1 << 2 },
	{ .class = "Outlook", .tags = 1 << 3 },
	{ .class = "Teams", .tags = 1 << 4 },
	{ .title = "spterm", .isfloating = 1, .scratchkey = 't', .floatpos = "50% 50% 80% 80%" },
};


/* layout(s) */
static const float mfact		= 0.50;
static const int nmaster		= 1;
static const int resizehints 	= 0;
static const int lockfullscreen = 1;

#define FORCE_VSPLIT 1	/* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol	arrange function */
	{ "[]=",	tile },
	{ "><>",	NULL },
	{ "[M]",	monocle },
	{ "[@]",	spiral },
	{ "[\\]",	dwindle },
	{ "H[]",	deck },
	{ "TTT",	bstack },
	{ "===",	bstackhoriz },
	{ "HHH",	grid },
	{ "###",	nrowgrid },
	{ "---",	horizgrid },
	{ ":::",	gaplessgrid },
	{ "|M|",	centeredmaster },
	{ ">M>",	centeredfloatingmaster },
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,						KEY,	view,		{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,			KEY,	toggleview,	{.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,				KEY,	tag,		{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask,	KEY,	toggletag,	{.ui = 1 << TAG} },

#define SCRATCHKEYS(KEY,CMD) \
	{ MODKEY,				KEY,	togglescratch,	{.v = CMD} }, \
	{ MODKEY|ShiftMask,		KEY,	removescratch,	{.v = CMD} }, \
	{ MODKEY|ControlMask,	KEY,	setscratch,		{.v = CMD} },


/* commands */
static const char *dmenucmd[] 	= { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_accent, "-sf", col_gray4, NULL };
static const char *termcmd[]	= { "alacritty", NULL };
static const char *firefoxcmd[]	= { "firefox", NULL };
static const char *chromecmd[]	= { "google-chrome-stable", NULL };
static const char *thunarcmd[]	= { "thunar", NULL };

static const char *sptermcmd[]	= { "t", "alacritty", "-T", "spterm", NULL};

static const char *outlookcmd[]	= { "outlook.sh", NULL };
static const char *teamscmd[]	= { "teams.sh", NULL };

static const char *screendown[]	= { "backlight", "--dec", NULL };
static const char *screenup[]	= { "backlight", "--inc", NULL };
static const char *keysdown[]	= { "keylights", "--dec", NULL };
static const char *keysup[]		= { "keylights", "--inc", NULL };

static const char *volmute[]	= { "volume", "--toggle", NULL };
static const char *voldown[]	= { "volume", "--dec", NULL };
static const char *volup[]		= { "volume", "--inc", NULL };

#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier				key							function			argument */
	{ MODKEY,				XK_space,					spawn,				{.v = dmenucmd } },
	{ MODKEY,				XK_w,						spawn,				{.v = firefoxcmd } },
	{ MODKEY|ShiftMask,		XK_w,						spawn,				{.v = chromecmd } },
	{ MODKEY,				XK_e,						spawn,				{.v = thunarcmd } },
	{ MODKEY,				XK_o,						spawn,				{.v = outlookcmd } },
	{ MODKEY,				XK_c,						spawn,				{.v = teamscmd } },

	{ 0, 					XF86XK_MonBrightnessDown, 	spawn, 				{.v = screendown} },
	{ 0, 					XF86XK_MonBrightnessUp, 	spawn, 				{.v = screenup } },
	{ 0, 					XF86XK_KbdBrightnessDown, 	spawn, 				{.v = keysdown} },
	{ 0, 					XF86XK_KbdBrightnessUp, 	spawn, 				{.v = keysup } },
	{ 0, 					XF86XK_AudioMute, 			spawn, 				{.v = volmute } },
	{ 0, 					XF86XK_AudioLowerVolume, 	spawn, 				{.v = voldown } },
	{ 0, 					XF86XK_AudioRaiseVolume, 	spawn, 				{.v = volup } },


	{ MODKEY,				XK_Return,					spawn,				{.v = termcmd } },
	{ MODKEY,				XK_h,						focusdir,			{.i = 0 } }, 
	{ MODKEY,				XK_l,						focusdir,			{.i = 1 } }, 
	{ MODKEY,				XK_k,						focusdir,			{.i = 2 } }, 
	{ MODKEY,				XK_j,						focusdir,			{.i = 3 } }, 
	{ MODKEY|ControlMask,	XK_h,						placedir,			{.i = 0 } },
	{ MODKEY|ControlMask,	XK_l,						placedir,			{.i = 1 } },
	{ MODKEY|ControlMask,	XK_k,						placedir,			{.i = 2 } },
	{ MODKEY|ControlMask,	XK_j,						placedir,			{.i = 3 } },
	{ MODKEY,				XK_i,						incnmaster,			{.i = +1 } },
	{ MODKEY,				XK_d,						incnmaster,			{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_h,						setmfact,			{.f = -0.05} },
	{ MODKEY|ShiftMask,		XK_l,						setmfact,			{.f = +0.05} },
	{ MODKEY|ShiftMask,		XK_h,						setcfact,			{.f = +0.25} },
	{ MODKEY|ShiftMask,		XK_l,						setcfact,			{.f = -0.25} },
	{ MODKEY|ShiftMask,		XK_o,						setcfact,			{.f =	0.00} },
	{ MODKEY,				XK_q,						killclient,			{0} },
	{ MODKEY,				XK_t,						setlayout,			{.v = &layouts[0]} },
	{ MODKEY,				XK_f,						setlayout,			{.v = &layouts[1]} },
	{ MODKEY,				XK_m,						setlayout,			{.v = &layouts[2]} },
	{ MODKEY,				XK_b,						setlayout,			{.v = &layouts[6]} },
	{ MODKEY,				XK_g,						setlayout,			{.v = &layouts[11]} },
	{ MODKEY,				XK_comma,					cyclelayout,		{.i = -1 } },
	{ MODKEY,				XK_period,					cyclelayout,		{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_space,					togglefloating,		{0} },
	{ MODKEY|ShiftMask,		XK_b,						togglebar,			{0} },
	{ MODKEY,				XK_Up,						togglefullscr,		{0} },
	{ MODKEY,				XK_Down,					togglefullscr,		{0} },
	{ MODKEY,				XK_0,						view,				{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,						tag,				{.ui = ~0 } },
	{ MODKEY,				XK_Right,					viewnext,			{0} },
	{ MODKEY,				XK_Left,					viewprev,			{0} },
	{ MODKEY|ShiftMask,		XK_Right,					tagtonext,			{0} },
	{ MODKEY|ShiftMask,		XK_Left,					tagtoprev,			{0} },
	SCRATCHKEYS(			XK_grave,										sptermcmd)
	TAGKEYS(				XK_1,											0)
	TAGKEYS(				XK_2,											1)
	TAGKEYS(				XK_3,											2)
	TAGKEYS(				XK_4,											3)
	TAGKEYS(				XK_5,											4)
	TAGKEYS(				XK_6,											5)
	TAGKEYS(				XK_7,											6)
	TAGKEYS(				XK_8,											7)
	{ MODKEY|ShiftMask,		XK_q,			quit,							{0} },
	{ MODKEY|ShiftMask, 	XK_r,			quit,							{1} }, 
};

/* button definitions */
static const Button buttons[] = {
	/* click			event mask		button		function			argument */
	{ ClkLtSymbol,		0,				Button1,	setlayout,			{0} },
	{ ClkLtSymbol,		0,				Button3,	setlayout,			{.v = &layouts[2]} },
	{ ClkWinTitle,		0,				Button2,	zoom,				{0} },
	{ ClkStatusText,	0,				Button2,	spawn,				{.v = termcmd } },
	{ ClkClientWin,		MODKEY,			Button1,	movemouse,			{0} },
	{ ClkClientWin,		MODKEY,			Button2,	togglefloating,		{0} },
	{ ClkClientWin,		MODKEY,			Button3,	resizemouse,		{0} },
	{ ClkTagBar,		0,				Button1,	view,				{0} },
	{ ClkTagBar,		0,				Button3,	toggleview,			{0} },
	{ ClkTagBar,		MODKEY,			Button1,	tag,				{0} },
	{ ClkTagBar,		MODKEY,			Button3,	toggletag,			{0} },
};

void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
	{ "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
	{ "floatpos",		floatpos },
};
