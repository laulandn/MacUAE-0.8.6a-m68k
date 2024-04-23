/* sysconfig.h.  Generated automatically by configure.  */
/* sysconfig.h.in.  Generated automatically from configure.in by autoheader.  */

/** changes made by !ZAJC!/GDS (Marin Saric) can be found
	by searching for "!ZAJC!". The number after "!ZAJC!"
	indicates day,month and year when the change was made
**/

#pragma once
#pragma once on

/* Define if on AIX 3.
   System headers sometimes define this.
   We just want to avoid a redefinition error message.  */
#ifndef _ALL_SOURCE
/* #undef _ALL_SOURCE */
#endif

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define if your struct stat has st_blocks.  */
/* #undef HAVE_ST_BLOCKS */

/* Define if utime(file, NULL) sets file's timestamp to the present.  */
#define HAVE_UTIME_NULL 1

/* Define as __inline if that's what the C compiler calls it.  */
#define __inline__ inline

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef mode_t */

/* Define to `long' if <sys/types.h> doesn't define.  */
/* #undef off_t */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef pid_t */

/* Define if you need to in order for stat and other things to work.  */
/* #undef _POSIX_SOURCE */

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 0

/* Define if your <sys/time.h> declares struct tm.  */
/* #undef TM_IN_SYS_TIME */

/* The number of bytes in a char.  */
#define SIZEOF_CHAR 1

/* The number of bytes in a int.  */
#define SIZEOF_INT 4

/* The number of bytes in a long.  */
#define SIZEOF_LONG 4

/* The number of bytes in a long long.  */
//#define SIZEOF_LONG_LONG 8 // xxx

/* The number of bytes in a short.  */
#define SIZEOF_SHORT 2

/* Define if you have the gettimeofday function.  */
#define HAVE_GETTIMEOFDAY 1

/* Define if you have the mkdir function.  */
#define HAVE_MKDIR 0

/* Define if you have the rmdir function.  */
#define HAVE_RMDIR 0

/* Define if you have the select function.  */
#define HAVE_SELECT 0

/* Define if you have the statfs function.  */
/* #undef HAVE_STATFS */

/* Define if you have the strerror function.  */
#define HAVE_STRERROR 1

/* Define if you have the strstr function.  */
#define HAVE_STRSTR 1

/* Define if you have the <dirent.h> header file.  */
/* #define HAVE_DIRENT_H 0 */

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <linux/joystick.h> header file.  */
/* #define HAVE_LINUX_JOYSTICK_H 1 */

/* Define if you have the <ndir.h> header file.  */
/* #undef HAVE_NDIR_H */

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <strings.h> header file.  */
/* #define HAVE_STRINGS_H 1 */

/* Define if you have the <sys/dir.h> header file.  */
/* #define HAVE_SYS_DIR_H 0 */

/* Define if you have the <sys/mount.h> header file.  */
/* #undef HAVE_SYS_MOUNT_H */

/* Define if you have the <sys/ndir.h> header file.  */
/* #undef HAVE_SYS_NDIR_H */

/* Define if you have the <sys/param.h> header file.  */
/* #define HAVE_SYS_PARAM_H 0 */

/* Define if you have the <sys/stat.h> header file.  */
#define HAVE_SYS_STAT_H 1

/* Define if you have the <sys/statfs.h> header file.  */
/* #undef HAVE_SYS_STATFS_H */

/* Define if you have the <sys/statvfs.h> header file.  */
/* #undef HAVE_SYS_STATVFS_H */

/* Define if you have the <sys/time.h> header file.  */
/* #define HAVE_SYS_TIME_H 0 */

/* Define if you have the <sys/types.h> header file.  */
#define HAVE_SYS_TYPES_H 1

/* Define if you have the <sys/vfs.h> header file.  */
/* #undef HAVE_SYS_VFS_H */

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the <utime.h> header file.  */
#define HAVE_UTIME_H 1

/* Define if you have the <values.h> header file.  */
/* #undef HAVE_VALUES_H */

#define __mac__
#define REGPARAM
#define strcasecmp strcmp
//#define NO_MAIN_IN_MAIN_C

// !ZAJC! 250698 UHdr 3.1 already define GENERATINGPOWERPC
// #define GENERATINGPOWERPC 1 		//Compiler is generating PowerPC instructions

#ifndef SystemSevenOrLater
#define SystemSevenOrLater 1 		//Compiled code will only be run on a System 7.0 or later Macintosh
#endif

#define USE_EXECLIB
#define PICASSO96_SUPPORTED