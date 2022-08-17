# Changes the ../libft/vector.h and ../libft/libft.h to vector.h and libft.h
#
# This is because in the end result, the directoires to include are given with
# -I, but for some reason clangd doesn't like that so I use absolute path instead
#
# But in the release version, it has to be like this since ../ goes out of the
# project folder.

BEGIN {
	pattern = "\"../libft/(vector|libft).h\"$"
}

$0 ~ pattern {
	sub(/\.\.\/libft\//, "")
}

$0 !~ pattern {
	print $0
}
