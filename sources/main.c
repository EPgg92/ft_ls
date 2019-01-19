#include "ft_ls.h"

int main(int argc, char **argv)
{
	int		activ_opt;
	char	**files;

	if (((activ_opt = parse_argv_option(argc, argv, &files)) == -1))
		return (ft_printf("error\n"));
	ft_printf("value output : %d\n", activ_opt);
	if (L_MIN & activ_opt)
		ft_printf("l is active\n");
	if (U_MIN & activ_opt)
		ft_printf("u is active\n");
	if (U_MAJ & activ_opt)
		ft_printf("U is active\n");
	if (T_MIN & activ_opt)
		ft_printf("t is active\n");
	if (R_MIN & activ_opt)
		ft_printf("r is active\n");
	if (R_MAJ & activ_opt)
		ft_printf("R is active\n");
	if (O_MIN & activ_opt)
		ft_printf("o is active\n");
	if (M_MIN & activ_opt)
		ft_printf("m is active\n");
	if (S_MAJ & activ_opt)
		ft_printf("S is active\n");
	if (OPT_1 & activ_opt)
		ft_printf("1 is active\n");
	if (A_MIN & activ_opt)
		ft_printf("a is active\n");
}
