# Changes the SRC_DIR variable in Makefile from src to .
BEGIN {
	pattern = "^SRC_DIR = src$"
}

$0 ~ pattern {
	print "SRC_DIR = ."
}

$0 !~ pattern {
	print $0
}
