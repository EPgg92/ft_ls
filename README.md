# ft_ls

Implementation of our own ls command in c.

## implementation step



## Choice of implementation

- Do an ls debian like for manage options.
	- Arguments and options can be shuffle.
- For `-R` we decide to recursion this way:
	- ft_ls(dir)
		- display list ./files_or_dirchild
		- if `-R`:
			- display ./dir/dirchild
				- ft_ls(./dir/dirchild)

## Structure implementation elmt

- char content_or_file (`-F` /)
	- d : directory (`-F` /)
	- l : link (`-F` /)
	- - : file (`-F` /)
	- c : char file (`-F` /)
	- b : Block file (`-F` /)
	- p : FIFO (`-F` /)
- unsigned short right (SGID, SUID, stickybit)
- unsigned int link_of
- char* link_to = NULL for d & -
- unsigned int owner_number
- unsigned int groups_number
- char* owner
- char* groups
- unsigned int octets
- int modification_time
- int last_time
- int creation_time
- char* name
- char ACL_xattr  **bonus**

## options
- `-a` show hidden files
	- parsing fill with stat list of elmt
- `-l`
	- printing

## Sort
- `-t`
	- lexicographical[ascii] sort (name)
	- modification_time sort
- `-u` **bonus**
	- last_time sort
- `-U` **bonus**
	- creation_time sort
- `-S` **bonus**
	- octets sort decrease  
- `-r` reverse

## General Bonus

- Column (not just `-l`) calculate on term's height, term's width and length of higher filename.
- `-1` one file per line
- `-o` = `-l` without groups
- `-m` comma separation
- `-F` print name followed by a special char


## comportement ls
