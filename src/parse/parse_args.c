#include "../../include/push_swap.h"

char    *ft_array_to_str(char **array, int c)
{
    size_t  i;
    size_t  ib;
    size_t  y;
    char    *str;

    i = 0;
    ib = 0;
    y = 1;
    if (!array[3])
        return (array[2]);
    str = malloc(sizeof(char) * (ft_len_of_array(array, c) + 1));
    while (y < c)
    {
        while (array[y][i] != "\0")
        {
            str[ib] = array[y][i]
            i++;
            ib++;
            if (array[y][i] == " " && array[y][i + 1] != "\0")
                {
                    str[ib] = " ";
                    ib++;
                }
        }
        y++;
        i = 0;
    }
     str[ib] = "\0";
     return (str);   
}

int    ft_len_of_array(char **array, int c)
{
    size_t  i;
    size_t  y;
    size_t  compt;

    i = 0;
    y = 1;
    compt = 0;
    while (y < c)
    {
        while(array[y][i] != "\0")
        {
            i++;
            compt++;
            if (array[y][i] == " " && array[y][i + 1] != "\0")
                compt++;
        }
        compt++;
        y++;
        i = 0;
    }
    return compt;
}

int    ft_check_str(char **array, int c)
{
    size_t  i;
    char    str;

    str = ft_array_to_str(array, c);
    i = 0;
    while(str[i])
    {
        if (str[i] > '0' && str[i] < '9' || str[i] == " ")
            i++;
        else 
            return (0);
    }
    ft_add_to_list(str);
    return (1);
}
