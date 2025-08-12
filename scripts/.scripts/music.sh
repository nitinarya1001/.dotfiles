#! /usr/bin/env bash

ans=""
echo -n "Enter link for song: "
read ans

if [ -z  $ans ]; then
    ans="https://www.youtube.com/watch?v=jfKfPfyJRdk"
fi

# mpv --no-video $ans & disown

