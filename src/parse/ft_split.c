#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*word_dup(const char *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = word_len(s, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **tab, int filled)
{
	while (filled > 0)
	{
		filled--;
		free(tab[filled]);
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = word_dup(s, c);
			if (!result[i])
				return (free_all(result, i), NULL);
			i++;
			s += word_len(s, c);
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
