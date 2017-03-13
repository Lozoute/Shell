/*
** my.h for minishell2 in /home/auzou_t/PSU_2014_minishell2
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Nov 26 10:24:23 2014 Thibaud Auzou
** Last update Sun Nov 30 20:08:01 2014 Thibaud Auzou
*/

#ifndef MY_H_
# define MY_H_

# define STDIN		0
# define STX_ERR	2
# define ERROR		1
# define ENV_SEP	'='
# define PATH_SEP	':'
# define SHELL_SEP	' '
# define SHELL_SEP_2	'\t'
# define ENV_PATHS	"PATH"
# define ENV_PWD	"PWD"
# define ENV_OLDPWD	"OLDPWD"
# define ENV_PATHS_S	4
# define READ_SIZE	30270
# define BLD_BLUE	"\x1b[1;34;40m"
# define CLR_RESET	"\x1b[0m"
# define COMMAND_SEP	";|<>"
# define STX_ERR_MSG	"Syntax error\n"
# define NB_BF		5

typedef struct		s_env
{
  char			*name;
  char			*data;
  struct s_env		*next;
}			t_env;

typedef struct		s_paths
{
  char			*path;
  struct s_paths	*next;
}			t_paths;

typedef struct		s_infos_shell
{
  char			*pwd;
  char			*oldpwd;
  char			*host;
  char			*home;
  char			*user;
}			t_infos_shell;

typedef struct		s_list
{
  char			*command;
  char			op;
  char			**options;
  struct s_list	*next;
}			t_list;

typedef struct		s_built_ins
{
  char			*name;
  int			(*bf)();
}			t_built_ins;

/*
** Basic Lib
*/
char			*get_next_line(const int fd);
int			len(char *str);
int			add_to_save(char *buff);
int			remove_from_save(int *ok, int i);
char			*cut_save(int *ok, int force_cutting, int i, int j);
int			my_putchar(char c);
int			my_putstr(char *str);
int			my_putstre(char *str);
int			my_strlen(char *str);
int			my_put_nbr(int nb);
int			my_strcmp(char *s1, char *s2);
int			my_strncmp(char *s1, char *s2, int nb);
char			*my_strcpy(char *s1, char *s2);
char			*my_strncpy(char *s1, char *s2, int nb);
char			*my_strcat(char *dest, char *src);
char			*my_strdup(char *src);
char			*my_strndup(char *src, int nb);
char			**my_str_to_wordtab(char *str, char sep);

/*
** Env To List
*/
int			env_to_list(t_env **env, char **environ);
char			*get_env_variable_data(char *str);
char			*get_env_variable_name(char *str);
int			create_paths_list(char *str, t_paths **paths);
int			get_paths_from_env(t_env **env, t_paths **paths);
int			get_infos_from_env(t_env **env,
					   t_infos_shell **shell_infos);
int			infos_name_is_matching(char *str);
int			set_this_infos(t_infos_shell **shell_infos,
				       char *data,
				       int i);
int			init_infos(t_infos_shell *elem);

/*
** List to env
*/
char			**list_to_env(t_env **env);
char			**copy_list_in_env(char **tab, t_env **env);

/*
** Memory
*/
void			*my_malloc(void *data, int size);
void			free_env(t_env **env);
void			free_paths(t_paths **paths);
void			free_infos(t_infos_shell **infos_shell);
void			free_list(t_list **list);
void			free_wordtab(char **tab);

/*
** Main Functions
*/
int			minishell(t_env **env,
				  t_paths **paths);
int			execute_list(t_list **list,
				     t_env **env,
				     t_paths **paths,
				     t_infos_shell *shell_infos);
char			*try_to_access(t_list *tmp, t_paths **paths);
int			execute(char **av, char *com, t_env **env);
t_list			*do_execute(t_list *tmp,
				    t_paths **paths,
				    t_env **env,
				    t_infos_shell *shell_infos);

/*
** Print List
*/
int			print_list(t_env **env);

/*
** Prompt
*/
int			print_prompt(t_infos_shell **shell_infos);

/*
** Parsing
*/
int			str_to_executable_list(t_list **list,
					       char *str,
					       char *home);
int			add_it_to_list(t_list **list,
				       char *str,
				       char *home,
				       int *sep);
int			is_command_sep(char c, char *command_sep);
int			add_operator(t_list **list, char *str);
int			check_stx_op(char *str);
int			add_options(t_list **list, char *str, char *home);
int			check_stx_options(t_list **list);
char			**get_options_list(char **options, char *option);
int			options_size(char **options);
int			copy_tab(char **dest, char **src);
int			add_command(t_list **list, char *str);
int			check_stx_command(t_list **list);
char			*get_command(char *str);

/*
** Tild & Path
*/
char			*build_path(char *com,char *path);
char			*build_tild(char *str, char *home);

/*
** Signals
*/
void			ctrl_c_kill(int sig);
void			ctrl_c_prompt(int sig);

/*
** Pipe
*/
t_list			*do_pipe(t_list *elem1,
				 t_list *elem2,
				 t_paths **paths,
				 t_env **env);
void			writting_son(int pipefd[2],
				     t_list *elem,
				     t_paths **paths,
				     t_env **env);
void			reading_son(int pipefd[2],
				    t_list *elem,
				    t_paths **paths,
				    t_env **env);

/*
** Redirections
*/
t_list			*do_redirection(t_list *elem1,
					t_list *elem2,
					t_paths **paths,
					t_env **env);
int		append_in_file(t_list *elem1,
			       t_list *elem2,
			       t_paths **paths,
			       t_env **env);
int		print_in_file(t_list *elem1,
			      t_list *elem2,
			      t_paths **paths,
			       t_env **env);
int		read_from_file(t_list *elem1,
			       t_list *elem2,
			       t_paths **paths,
			       t_env **env);

/*
** System Calls
*/
void			my_execve(char *com, char **av, char **tab);
int			my_wait(void);
int			my_pipe(int fd[2]);
int			my_dup(int fd);
int			my_dup2(int fd1, int fd2);

/*
** Built Ins
*/
int			is_built_ins(char *str);
int			built_ins(t_list *elem,
				  t_paths **paths,
				  t_env **env,
				  int i);
int			my_exit(t_list *elem,
				t_paths **paths,
				t_env **env);
int			my_setenv(char **av, t_env **env);
int			change_value_env(char **av, t_env **env);
int			enlarge_env(char **av, t_env **env);
int			delete_from_env(char **av, t_env **env);
int			my_unsetenv(char **av, t_env **env);
char			*build_pwd_with_dots(char *str, char *pwd);
int			my_cd(char **av, t_env **env);
int			change_pwd(char *path, t_env **env);
int			change_old_pwd(char *save, t_env **env);
char			*build_pwd(char *str, char *save);
void			go_to_parent(char *str);
int			word_size(char *str);
void			concat_path_with_pwd(char *tmp,
					     char *pwd,
					     char *str,
					     int size);
char			*add_path_to_pwd(char *str, char *pwd);

#endif /* !MY_H_ */
