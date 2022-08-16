#!/usr/bin/env bash

DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

if [ ! -d $DIR/.git ]; then echo "No git repo found"; fi
if [ ! -f $DIR/Makefile ]; then echo "No Makefile found"; fi

rm -rf $DIR/release
mkdir -p $DIR/release

cp $DIR/src/* $DIR/release
cp $DIR/Makefile $DIR/release

git clone git@github.com:ytkimirti/dotfiles.git $DIR/release/libft --depth 1

cd $DIR/release/libft
LIBFT_COMMIT=$(git log --oneline -n 1 | cut -d ' ' -f 1)

cd $DIR
MAIN_COMMIT=$(git log --oneline -n 1 | cut -d ' ' -f 1)

echo "RELEASE $(date) REPO_COMMIT: $MAIN_COMMIT LIBFT_COMMIT: $LIBFT_COMMIT" >>$DIR/Makefile

rm -rf $DIR/release/.git
rm -rf $DIR/release/libft/.git
