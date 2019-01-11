/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_start_with.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 10:40:00 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:59:51 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_start_with(const char *string, const char *subset)
{
	while (*subset && *string && *string == *subset)
	{
		subset++;
		string++;
	}
	return (!*subset ? 1 : 0);
}
