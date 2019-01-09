# ft_ls

Implementation of our own ls command in c.

## Choice of implementation

- Do an ls debian like for manage options.
	- Arguments and options can be shuffle.
- For `-R` we decide to recursion this way:
	- ft_ls(dir)
		- display list ./files_or_dirchild
		- if `-R`:
			- display ./dir/dirchild
				- ft_ls(./dir/dirchild)
