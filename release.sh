#!/usr/bin/env bash


REPO="git@vogsphere.42istanbul.com.tr:vogsphere/intra-uuid-2274521c-0ee4-4799-97f8-9dc101454e99-3996063-ykimirti"

DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

RELEASE_DIR="$DIR/release"

if [ ! -d $DIR/.git ]; then echo "No git repo found"; fi
if [ ! -f $DIR/Makefile ]; then echo "No Makefile found"; fi

rm -rf $RELEASE_DIR
mkdir -p $RELEASE_DIR

# cp $DIR/src/* $RELEASE_DIR
for file in $DIR/src/*.{c,h}; do
	awk -f cmodify.awk "$file" > "$RELEASE_DIR/$(basename $file)"
done

git clone git@github.com:ytkimirti/libft.git $RELEASE_DIR/libft --depth 1

cd $RELEASE_DIR/libft
LIBFT_COMMIT=$(git log --oneline -n 1 | cut -d ' ' -f 1)

cd $DIR
MAIN_COMMIT=$(git log --oneline -n 1 | cut -d ' ' -f 1)

echo "# RELEASE $(date) REPO_COMMIT: $MAIN_COMMIT LIBFT_COMMIT: $LIBFT_COMMIT" >>$DIR/Makefile

rm -rf $RELEASE_DIR/.git
rm -rf $RELEASE_DIR/libft/.git

# Don't copy the makefile, generate a new one from the old one
# cp $DIR/Makefile $RELEASE_DIR

awk -f makemodify.awk Makefile >$RELEASE_DIR/Makefile

cd $RELEASE_DIR

git init
git checkout -b master
git remote add origin $REPO
git add --all
git commit -m "Initial release commit"
git push --force --set-upstream origin master
