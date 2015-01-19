
#ifndef	FT_LS_H
# define FT_LS_H
# include <dirent.h>
//# include <sys/stat.h>
//# include <pwd.h>
//# include <uuid/uuid.h>
//# include <grp.h>
//# include <time.h>
//# include <unistd.h>
//# include <stdlib.h>
//# include <stdio.h>

/*typedef struct	s_dir
{
	ino_t		d_ino;	
	off_t		d_off;
	unsigned short	d_reclen;
	unsigned char	*d_type;
	char		d_name[256];
}			t_dir;
*/
typedef struct	s_file
{
	
}		t_file;

typedef	struct	s_flags
{
	char	a;
	char	r_maj;
	char	l;
	char	r;
	char	t;
}		t_flags;

void	init_flags(t_flags *flags);
void    check_options(char *av, t_flags *flags);
char    **parse_args(char **av, t_flags *flags, int ac);
void    display_flags(t_flags flags);

#endif
