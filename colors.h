static const char col_black[]		= "#000000";
static const char col_gray1[]		= "#101010";
static const char col_gray2[]		= "#545454";
static const char col_gray3[]		= "#abb2bf";
static const char col_gray4[]		= "#cdd3cf";
static const char col_green[]		= "#98c379";
static const char col_yellow[]		= "#d19a66";
static const char col_blue[]		= "#61afef";
static const char col_magenta[]		= "#c678dd";
static const char col_cyan[]		= "#56b6c2";
static const char col_accent[]		= "#0335bb";
 
static const char *colors[][3]		= {
	/*						fg				bg				border	*/
	[SchemeNorm]		= { col_gray3,		col_gray1,		col_gray2   },
	[SchemeSel]			= { col_gray4,		col_accent,		col_blue    },
	[SchemeFloat]		= { col_gray3,		col_gray1,		col_magenta },
	[SchemeTagsNorm]	= { col_gray2,		col_gray1,		col_black   },
	[SchemeTagsOcc]		= { col_cyan,		col_gray1,		col_black   },
	[SchemeTagsSel]		= { col_gray4,		col_accent,		col_black   },
	[SchemeLtSymbol]	= { col_yellow,		col_gray1,		col_black   },
	[SchemeTitleNorm]	= { col_gray3,		col_gray1,		col_black   },
	[SchemeTitleSel]	= { col_gray4,		col_gray1,		col_black   },
	[SchemeScratchNorm]	= { col_gray3,		col_gray1,		col_gray2   },
	[SchemeScratchSel]	= { col_gray3,		col_gray1,		col_green   },
};

