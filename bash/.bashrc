#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

export EDITOR="vim"
export VISUAL="vim"

source /usr/share/bash-completion/bash_completion

alias ls='ls --color=auto'
alias grep='grep --color=auto'

# Custom aliases
# Basic stuff
alias mirrors='sudo reflector --country India --latest 20 --sort rate --save /etc/pacman.d/mirrorlist'
alias rm-bash-tmp='rm -rf ~/.bash_history-*'

#suckless software configuration 
alias cfgdwm='cd && cd ~/.config/suckless/dwm && vim config.def.h && sudo rm config.h && sudo make clean install && killall -15 dwm' #DWM configuration
alias cfgst='cd && cd ~/.config/suckless/st && vim config.def.h && sudo rm config.h && sudo make clean install' #ST configuration
alias cfgslstatus='cd && cd ~/.config/suckless/slstatus && vim config.def.h && sudo rm config.h && sudo make clean install && killall -15 slstatus && (slstatus & disown)' #SLSTATUS configuration
alias cfgslock='cd && cd ~/.config/suckless/slock && vim config.def.h && sudo rm config.h && sudo make clean install' #slock configuration

#PS1='[\u@\h \W]\$ '
PROMPT_COMMAND='PS1_CMD1=$(git branch --show-current 2>/dev/null)'; PS1='\[\e[38;5;148m\]\u\[\e[0m\] \[\e[38;5;81m\]\w\[\e[0m\] \[\e[38;5;172;1m\]${PS1_CMD1}\[\e[0m\] \[\e[38;5;222m\]\D{%d %b %y}\[\e[0m\] \[\e[38;5;222m\]\A\n\[\e[0m\]\$ '
