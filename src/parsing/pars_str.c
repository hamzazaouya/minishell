#include "../../includes/minishell.h"

int get_str_len(char *str)
{
    int i;
    char c;

    i = 0;
    c = str[i++];
    while(str[i] && str[i] != c)
        i++;
    return (i + 1);
}

int get_cmd_len(char *str)
{
    int i;

    i = 0;
	if(str[i] == '|')
		return (1);
    while(str[i] && str[i] != ' ' && str[i] != '|')
        i++;
    return (i);
}

int cmd_len(char *str)
{
	if(*str == '\'' || *str == '\"')
		return (get_str_len(str));
	return get_cmd_len(str);
	
}

int	count_cmd(char *str)
{
	int i;
	int ctr;


	i = 0;
	ctr = 0;
	while(str[i])
	{
		if(str[i] != ' ' && str[i] != '|')
		{
			if(str[i] == '\"' || str[i] == '\'')
				i += get_str_len(str + i);
			else
				i += get_cmd_len(str + i);
			ctr++;
		}
		else if(str[i] == '|')
		{
			i++;
			ctr++;
		}
		else
			i++;
	}
	return (ctr);
}

char *get_arg(char *str, int *i)
{
	int j;
	int len;
	char *arg;

	j = 0;
	len = cmd_len(str);
	arg = (char *) malloc(sizeof(char) * (len + 1));
	while(j < len)
	{
		arg[j] = str[j];
		j++;
	}
	arg[j] = 0;
	*i += j;
	return (arg);
}

char **separation(char *str)
{
	int i;
	int j;
	char **cmd_sep;
	
	i = 0;
	j = 0;
	cmd_sep = (char **) malloc(sizeof(char *) * (count_cmd(str) + 1));
	while(str[i])
	{
		if(str[i] != ' ')
			cmd_sep[j++] = get_arg(str + i, &i);
		else
			i++;
	}
	cmd_sep[j] = NULL;
	return (cmd_sep);
}

// int main(void)
// {
// 	int i;

// 	i = 0;
// 	char str[] = "cat /etc/passwd | grep -v \"#\" | cut -d \":\" -f1 | awk '{if (NR % 2 == 0) print}' | sed -n \"$FT_LINE1, $FT_LINE2 p\" | rev | sort -r | tr \"\n\" \" \" | sed 's/ /, /g' | sed 's/, $/./' | tr -d \"\n\"";
// 	//printf("%s %d\n", get_arg(str, &i), i);
// 	parsing(str);
// }