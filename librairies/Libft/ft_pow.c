/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pow.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 10:18:56 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:59:29 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

long long	ft_pow(int nbr, int pow)
{
	long long int result;

	result = 1;
	if (pow < 0)
		return (0);
	while (pow--)
		result *= nbr;
	return (result);
}
