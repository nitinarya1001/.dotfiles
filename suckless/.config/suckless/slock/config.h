/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nitin-arya";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#000000",     /* after initialization */
	[INPUT] =  "#A7C080",   /* during input */
	[FAILED] = "#E68183",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
